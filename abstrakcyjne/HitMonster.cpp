#include "HitMonster.h"



HitMonster::HitMonster(GameModel *gamemodel, GraphicEventQ * graphiceventq, int processtime, int x, int y):Event(gamemodel, graphiceventq, processtime)
{
	eventType = "HitMonster";
	this->x = x;
	this->y = y;
}


HitMonster::~HitMonster()
{
}

