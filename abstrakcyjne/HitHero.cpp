#include "HitHero.h"



HitHero::HitHero(GameModel *gamemodel, GraphicEventQ * graphiceventq, int processtime) : Event(gamemodel, graphiceventq, processtime)
{
	eventType = "HitHero";
}


HitHero::~HitHero()
{
}
