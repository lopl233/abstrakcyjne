#include "Game.h"
#undef main //sdl coœ sam miesza z mainem przy imporcie <SDL.h> to trzeba po nim posprz¹taæ


int main() {
	Game *game = new Game();
	game->run();

	return 0;
}