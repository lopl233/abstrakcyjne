#include "GameModel.h"
#include "constants.cpp"
#include "Warrior.h"


GameModel::GameModel()
{
	fieldholder = new FieldHolder(MAP_SIZE, 0.03);
	hero = new Warrior();
	eventQ = new EventQ();
}


GameModel::~GameModel()
{
}
