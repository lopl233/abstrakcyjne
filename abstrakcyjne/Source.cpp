#include "Game.h"
#undef main //sdl co� sam miesza z mainem przy imporcie <SDL.h> to trzeba po nim posprz�ta�


int main() {
	Game *game = new Game();
	game->run();

	return 0;
}