#include "GameModel.h"
#include "constants.cpp"
#include "Warrior.h"



GameModel::GameModel()
{
	fieldholder = new FieldHolder(MAP_SIZE, 0.1);
	hero = new Warrior();
}


GameModel::~GameModel()
{
}
