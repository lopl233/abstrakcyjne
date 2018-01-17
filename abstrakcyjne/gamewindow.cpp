#include <SDL.h> 
#include <SDL_image.h>
#include <map>  
#include "constants.cpp"
#include <string>
#include "TextureHolder.cpp"

class GameWindow {

private:
	SDL_Window * window;
	SDL_Renderer* renderer;
	std::map<int, int> PressedKeys;
	bool running = true;
	TextureHolder * textureholder;

public:
	void onKeyDown(SDL_Event* evt) {
		PressedKeys[evt->key.keysym.sym] = 1;
	}

	void onKeyUp(SDL_Event* evt) {
		PressedKeys[evt->key.keysym.sym] = 0;
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
	
	GameWindow() :window(NULL), renderer(NULL) {
		int flags = SDL_WINDOW_SHOWN;

		if (SDL_Init(SDL_INIT_EVERYTHING)) { return; }
		//int img_flags = IMG_INIT_PNG || IMG_INIT_JPG;
		//int img_flags = IMG_INIT_JPG;
		int img_flags = IMG_INIT_PNG;

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

		drawRectangle(33, 66, 33, 33, 255, 123, 255);
		drawRectangle(66, 66, 33, 33, 168, 142, 163);
		drawRectangle(99, 66, 33, 33, 0, 255, 255);

		drawTexture(33, 33, 33, 33, "spell.jpg");
		drawTexture(66, 33, 33, 33, "stickman.png");
		drawTexture(99, 33, 33, 33, "s.png");

		SDL_RenderPresent(renderer);
	}

	void run() {
		SDL_Event event;
		int lastDraw = SDL_GetTicks();
		int now;
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
			//test();
			if (now - lastDraw >= UPDATE_INTERVAL) {
				lastDraw = SDL_GetTicks();
				draw();
			}

		}

	}
};
