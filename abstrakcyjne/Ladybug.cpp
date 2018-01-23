#include "Ladybug.h"

Ladybug::Ladybug() : Ladybug(5, 2)
{
}

Ladybug::Ladybug(const int maxHP, const int lvl): Monster(maxHP, lvl, "ladybug.png")
{
	setExp(10 * lvl);
}


Ladybug::~Ladybug()
{
}
