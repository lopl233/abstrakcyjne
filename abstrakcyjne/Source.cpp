#include "gamewindow.cpp"
#undef main //sdl co� sam miesza z mainem przy imporcie <SDL.h> to trzeba po nim posprz�ta�


int main() {
	GameWindow gamewindow;
	gamewindow.run();

	return 0;
}