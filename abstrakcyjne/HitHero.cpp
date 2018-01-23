#include "HitHero.h"



HitHero::HitHero(GameModel *gamemodel, GraphicEventQ * graphiceventq, int processtime, int x, int y) : Event(gamemodel, graphiceventq, processtime)
{
	eventType = "HitHero";
	this->x = x;
	this->y = y;
}


HitHero::~HitHero()
{
}
