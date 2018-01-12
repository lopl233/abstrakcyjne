#include "gamewindow.cpp"
#undef main //sdl coœ sam miesza z mainem przy imporcie <SDL.h> to trzeba po nim posprz¹taæ


int main() {
	GameWindow gamewindow;
	gamewindow.run();

	return 0;
}