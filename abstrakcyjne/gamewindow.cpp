#include <SDL.h> 
#include <map>  
#include <iostream>
#include "constants.cpp"



class GameWindow {

private:
	SDL_Window * window;
	SDL_Renderer* renderer;
	std::map<int, int> PressedKeys;
	bool running = true;


public:
	void onKeyDown(SDL_Event* evt) {
		PressedKeys[evt->key.keysym.sym] = 1;
	}

	void onKeyUp(SDL_Event* evt) {
		PressedKeys[evt->key.keysym.sym] = 0;
	}
	GameWindow() :window(NULL), renderer(NULL) {
		int flags = SDL_WINDOW_SHOWN;
		if (SDL_Init(SDL_INIT_EVERYTHING)) { return; }
		if (SDL_CreateWindowAndRenderer(DISPLAY_WIDTH, DISPLAY_HEIGHT, flags, &window, &renderer)) { return; }
	}

	~GameWindow() {
		if (NULL != renderer) { SDL_DestroyRenderer(renderer); renderer = NULL; }
		if (NULL != window) { SDL_DestroyWindow(window);	window = NULL; }
		SDL_Quit();
	}

	void draw() {
		// Clear screen  
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		// Render hero  
		SDL_Rect kwadrat;
		kwadrat.x = 20;
		kwadrat.y = 20;
		kwadrat.w = 20;
		kwadrat.h = 20;
		SDL_SetRenderDrawColor(renderer, 168, 142, 163, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(renderer, &kwadrat);

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
			if (now - lastDraw >= UPDATE_INTERVAL) {
				lastDraw = SDL_GetTicks();
				draw();
			}

		}

	}





};
