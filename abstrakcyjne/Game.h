#pragma once

#include "GameModel.h"
#include "gamewindow.cpp"

class Game
{
	GameModel * gamemodel;
	GameWindow * gamewindow;
public:
	Game();
	~Game();
	void run() {
		gamewindow->run();
	}
};

