#include <SDL.h> 
#include <SDL_image.h>

#include <iostream>
#include <cstdio>
#include <map>  
#include <string>

#include "constants.cpp"
#include "TextureHolder.cpp"
#include "GameModel.h"


class GameWindow {

private:

	GameModel * gamemodel;
	SDL_Window * window;
	SDL_Renderer* renderer;
	map<int, int> PressedKeys;
	bool running = true;
	TextureHolder * textureholder;
	int now;
	int lastMove;

public:
	void onKeyDown(SDL_Event* evt) {
		PressedKeys[evt->key.keysym.sym] = 1;
		checkKeysAndMove();
	}

	void onKeyUp(SDL_Event* evt) {
		PressedKeys[evt->key.keysym.sym] = 0;
	}

	bool checkMove(const Direction d)
	{
		auto currX = gamemodel->getHero()->getX();
		auto currY = gamemodel->getHero()->getY();
		switch (d)
		{
		case NORTH:
			return gamemodel->getFieldHolder()->getField(currX, currY + 1)->CanBeStepped();
		case WEST:
			return gamemodel->getFieldHolder()->getField(currX + 1, currY)->CanBeStepped();
		case EAST:
			return gamemodel->getFieldHolder()->getField(currX - 1, currY)->CanBeStepped();
		case SOUTH:
			return gamemodel->getFieldHolder()->getField(currX, currY - 1)->CanBeStepped();
		}
		return false;
	}

	void drawTexture(int x, int y, int w, int h, string texturename) {
		SDL_Rect destination;
		destination.x = x;
		destination.y = y;
		destination.w = w;
		destination.h = h;

		SDL_Texture* texture = textureholder->getTexture(texturename);
		SDL_RenderCopy(renderer, texture, NULL, &destination);
	}

	void drawRectangle(int x, int y, int w, int h, int r, int g, int b) {
		SDL_Rect kwadrat;
		kwadrat.x = x;
		kwadrat.y = y;
		kwadrat.w = w;
		kwadrat.h = h;
		SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(renderer, &kwadrat);
	}

	void drawMap() {
		Hero * hero = gamemodel->getHero();
		FieldHolder * fieldholder = gamemodel->getFieldHolder();
		//cout << "herox: " << hero->getX() << endl;

		for (int x = hero->getX() - 5; x <= hero->getX() + 5; x++) {
			for (int y = hero->getY() - 5; y <= hero->getY() + 5; y++) {
				drawTexture((
					hero->getX() - x) * FIELD_SIZE + 310,
					(hero->getY() - y) * FIELD_SIZE + 310,
					FIELD_SIZE,
					FIELD_SIZE,
					fieldholder->getField(x, y)->getFilename());
			}
		}
	}

	void drawHero() {
		Hero * hero = gamemodel->getHero();
		drawTexture(310, 310, FIELD_SIZE, FIELD_SIZE, hero->getFilename());
	}

	void drawHpMpBars()
	{
		int hpWidth = 0;
		int mpWidth = 0;
		if (gamemodel->getHero()->getMAX_HP() != 0)
			hpWidth = gamemodel->getHero()->getCURRENT_HP() / gamemodel->getHero()->getMAX_HP() * 400;
		drawRectangle(20, 700, hpWidth, 20, 255, 0, 0);
		if (gamemodel->getHero()->getMAX_MP() != 0)
			mpWidth = gamemodel->getHero()->getCURRENT_MP() / gamemodel->getHero()->getMAX_MP() * 400;
		drawRectangle(20, 722, mpWidth, 20, 255, 0, 0);
	}

	GameWindow(GameModel * gamemodel) :gamemodel(gamemodel), window(NULL), renderer(NULL) {
		int flags = SDL_WINDOW_SHOWN;

		if (SDL_Init(SDL_INIT_EVERYTHING)) { return; }
		int img_flags = IMG_INIT_PNG || IMG_INIT_JPG;

		int initted = IMG_Init(img_flags);
		if ((initted&img_flags) != img_flags) {
			printf("IMG_Init: %s\n", IMG_GetError());
		}
		if (SDL_CreateWindowAndRenderer(DISPLAY_WIDTH, DISPLAY_HEIGHT, flags, &window, &renderer)) { return; }
		textureholder = new TextureHolder(renderer);
	}

	~GameWindow() {
		if (NULL != renderer) { SDL_DestroyRenderer(renderer); renderer = NULL; }
		if (NULL != window) { SDL_DestroyWindow(window);	window = NULL; }
		SDL_Quit();
	}

	void draw() {

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		drawMap();
		drawHero();
		drawHpMpBars();

		SDL_RenderPresent(renderer);
	}

	void checkKeysAndMove()
	{
		if (now - lastMove < 500)
		{
			return;
		}
		lastMove = SDL_GetTicks();

		if (PressedKeys[SDLK_w] == 1 && checkMove(NORTH))
		{
			gamemodel->getHero()->move(NORTH);
		}
		else 		if (PressedKeys[SDLK_a] == 1 && checkMove(WEST))
		{
			gamemodel->getHero()->move(WEST);
		}
		else		if (PressedKeys[SDLK_s] == 1 && checkMove(SOUTH))
		{
			gamemodel->getHero()->move(SOUTH);
		}
		else		if (PressedKeys[SDLK_d] == 1 && checkMove(EAST))
		{
			gamemodel->getHero()->move(EAST);
		}
	}

	void run() {
		SDL_Event event;
		int lastDraw = SDL_GetTicks();
		int frames = 0;
		int lastFpsUpdate = 0;
		lastMove = 0;

		char szFps[128];
		while (running) {
			//Obs³uga eventów, w tym wcisakania klawiszy
			if (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT:    running = false; break;
				case SDL_KEYDOWN: onKeyDown(&event); break;
				case SDL_KEYUP:   onKeyUp(&event);   break;
				}
			}

			//sprawdzamy czy od ostatniej klatki mine³o doœæ czasu, je¿eli tak to j¹ generujemy
			now = SDL_GetTicks();


			if (now - lastFpsUpdate >= 1000) {
				sprintf_s(szFps, "FPS: %d FPS", frames);
				SDL_SetWindowTitle(window, szFps);
				frames = 0;
				lastFpsUpdate = lastDraw;
			}
			if (now - lastDraw >= 1000 / FPS) {
				lastDraw = SDL_GetTicks();
				draw();
				frames++;
			}

		}

	}
};
