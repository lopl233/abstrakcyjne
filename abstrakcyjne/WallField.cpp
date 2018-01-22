#include "WallField.h"



WallField::WallField()
{
	filename = "wall.png";
	canBeSteped = false;
}

void WallField::AddMonster(std::shared_ptr<Monster> monster)
{
}

WallField::~WallField()
{
}
