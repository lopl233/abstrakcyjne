#include <SDL.h> 
#include <SDL_image.h>

#include <cstdio>
#include <map>  
#include <string>
#include <math.h>
#include <iostream>

#include "constants.cpp"
#include "TextureHolder.cpp"
#include "GameModel.h"
#include "GraphicEvent.h"
#include "GraphicEventQ.h"
#include "PointToPointEvent.h"
#include "AddHpEvent.h"
#include "Event.h"


class GameWindow {

private:

	GameModel * gamemodel;
	SDL_Window * window;
	SDL_Renderer* renderer;
	map<int, int> PressedKeys;
	bool running = true;
	TextureHolder * textureholder;
	GraphicEventQ graphiceventq;
	int now;
	int lastMove;
	int lastMoveSuccess;

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
		const auto currX = gamemodel->getHero()->getX();
		const auto currY = gamemodel->getHero()->getY();
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

	void drawTexture(int x, int y, int w, int h, string texturename, int angle = 0) {
		SDL_Rect destination;
		destination.x = x;
		destination.y = y;
		destination.w = w;
		destination.h = h;

		SDL_Texture* texture = textureholder->getTexture(texturename);

		if (angle == 0) {
			SDL_RenderCopy(renderer, texture, NULL, &destination);
		}
		else
		{
			SDL_Point center;
			center.x = w / 2;
			center.y = h / 2;
			SDL_RenderCopyEx(renderer, texture, NULL, &destination,angle , &center, SDL_FLIP_NONE);
		}

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

	double getMovingX() {


		Hero * hero = gamemodel->getHero();
		Direction direction = hero->getDirection();
		double x = hero->getX();
		if (direction == NORTH || direction == SOUTH)return x;
		if (now - lastMoveSuccess > 500)return x;


		if (direction == WEST)x -= 1 - ((double)(now - lastMoveSuccess) / 500);
		else x += 1 - ((double)(now - lastMoveSuccess) / 500);

		return x;
	}

	double getMovingY() {

		Hero * hero = gamemodel->getHero();
		Direction direction = hero->getDirection();
		double y = hero->getY();
		if (direction == WEST || direction == EAST)return y;
		if (now - lastMoveSuccess > 500)return y;

		if (direction == NORTH)y -= 1 -( (double)(now - lastMoveSuccess) / 500);
		else y += 1 - ((double)(now - lastMoveSuccess) / 500);

		return y;
	}

	void drawMap() {
		Hero * hero = gamemodel->getHero();
		FieldHolder * fieldholder = gamemodel->getFieldHolder();
		for (int x = hero->getX() - 6; x <= hero->getX() + 6; x++) {
			for (int y = hero->getY() - 6; y <= hero->getY() + 6; y++) {
				drawTexture(
					(int)((getMovingX() - x) * FIELD_SIZE) + 310,
					(int)((getMovingY() - y) * FIELD_SIZE) + 310,
					FIELD_SIZE,
					FIELD_SIZE,
					fieldholder->getField(x, y)->getFilename());
				auto m = fieldholder->getField(x, y)->GetMonster();
				if(m != nullptr)
				{
					drawTexture(
						(int)((getMovingX() - x) * FIELD_SIZE) + 310,
						(int)((getMovingY() - y) * FIELD_SIZE) + 310,
						FIELD_SIZE,
						FIELD_SIZE,
						m->getFilename());
				}
			}
		}
	}

	void drawHero() {
		Hero * hero = gamemodel->getHero();
		int angle = 0;
		if (hero->getDirection() == EAST) { angle = 90; }
		else if (hero->getDirection() == SOUTH) { angle = 180; }
		else if (hero->getDirection() == WEST) { angle = 270; }
		drawTexture(310, 310, FIELD_SIZE, FIELD_SIZE, hero->getFilename(),angle);
	}

	void drawInterface() {
		drawRectangle(0, 0, 10, 768, 255, 255, 255);
		drawRectangle(0, 0, 1024, 10, 255, 255, 255);
		drawRectangle(0, 670 , 1024, 130, 255, 255, 255);
		drawRectangle(670, 0, 1024, 768, 255, 255, 255);
		drawHpMpBars();

	}

	void drawHpMpBars()
	{
		int hpWidth = 0;
		int mpWidth = 0;
		if (gamemodel->getHero()->getMAX_HP() != 0) {
			hpWidth = gamemodel->getHero()->getCURRENT_HP() / gamemodel->getHero()->getMAX_HP() * 280;
			drawRectangle(720, 12, hpWidth, 20, 255, 0, 0);
			drawTexture(700, 12, 30, 20, "HP.png");
		}
		if (gamemodel->getHero()->getMAX_MP() != 0) {
			mpWidth = gamemodel->getHero()->getCURRENT_MP() / gamemodel->getHero()->getMAX_MP() * 280;
			drawRectangle(720, 32, mpWidth, 20, 255, 0, 0);
			drawTexture(700, 32, 30, 20, "MP.png");
		}
	}

	void drawGraphicEvent(GraphicEvent *event) {
		int x = (int)(( getMovingX() - event->getX(now)) * FIELD_SIZE + 310);
		int y = (int)(( getMovingY() - event->getY(now)) * FIELD_SIZE + 310);

		drawTexture(x, y, event->getSize(now), event->getSize(now), event->getTextureName(),event->getAngle(now));
	}

	void drawAllEvents() {

		graphiceventq.removeOldEvents(now);
		for (auto it = graphiceventq.begin(); it != graphiceventq.end(); it++) {
			if ((*it)->getStartTime() < now)
				drawGraphicEvent(*it);

		}
		
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
		drawAllEvents();
		drawInterface();

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
			lastMoveSuccess = lastMove;
			gamemodel->getHero()->move(NORTH);
		}
		else if (PressedKeys[SDLK_a] == 1 && checkMove(WEST))
		{
			lastMoveSuccess = lastMove;
			gamemodel->getHero()->move(WEST);
		}
		else if (PressedKeys[SDLK_s] == 1 && checkMove(SOUTH))
		{
			lastMoveSuccess = lastMove;
			gamemodel->getHero()->move(SOUTH);
		}
		else if (PressedKeys[SDLK_d] == 1 && checkMove(EAST))
		{
			lastMoveSuccess = lastMove;
			gamemodel->getHero()->move(EAST);
		}
	}

	void run() {
		SDL_Event event;
		int lastDraw = SDL_GetTicks();
		int frames = 0;
		int lastFpsUpdate = 0;
		lastMove = 0;
		int x, y;

		gamemodel->getEventQ()->addEvent(new AddHpEvent(gamemodel, &graphiceventq, 0));


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

			gamemodel->getEventQ()->proccessQ(now);

			if (now - lastFpsUpdate >= 1000) {
				sprintf_s(szFps, "FPS: %d FPS", frames);
				SDL_SetWindowTitle(window, szFps);
				frames = 0;
				lastFpsUpdate = lastDraw;
			}
			if (now - lastDraw >= 1000 / FPS) {
				lastDraw = SDL_GetTicks();
				draw();
				SDL_GetMouseState(&x, &y);
				if (x > 10 && x < 670 && y>10 && x < 670) {
					int field_x = getMovingX() - 5 + ((x - 10) / FIELD_SIZE);
					int field_y = getMovingY() - 5 + ((y - 10) / FIELD_SIZE);
					//cout << field_x << " " << field_y << endl;
				
				}
				frames++;
			}

		}

	}
};
