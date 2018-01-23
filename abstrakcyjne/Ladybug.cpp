#include "Ladybug.h"

Ladybug::Ladybug() : Ladybug(5, 2)
{
}

Ladybug::Ladybug(const int maxHP, const int lvl): Monster(maxHP, lvl, "ladybug.png")
{
}

int Ladybug::getAtkVal()
{
	return getLevel() * 0.5;
}

Ladybug::~Ladybug()
{
}
