#include "Game.h"

Game::Game()
{
	gamemodel = new GameModel();
	gamewindow = new GameWindow(gamemodel);
}


Game::~Game()
{
}
