#include "WallField.h"



WallField::WallField()
{
	filename = "wall.png";
	canBeSteped = false;
}

void WallField::AddMonster(std::shared_ptr<Monster>)
{
}

void WallField::AddPotion(std::shared_ptr<Potion>)
{
}

WallField::~WallField()
{
}
