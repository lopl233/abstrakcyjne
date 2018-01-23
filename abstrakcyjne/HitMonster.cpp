#include "HitMonster.h"



HitMonster::HitMonster(GameModel *gamemodel, GraphicEventQ * graphiceventq, int processtime):Event(gamemodel, graphiceventq, processtime)
{
	eventType = "HitMonster";
}


HitMonster::~HitMonster()
{
}

