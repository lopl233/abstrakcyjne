#include "Griffin.h"


Griffin::Griffin() : Griffin(10, 1)
{
}

Griffin::Griffin(const int maxHP, const int lvl): Monster(maxHP,lvl, "griffin.png")
{
}

int Griffin::getAtkVal()
{
	return getLevel() * 2;
}

Griffin::~Griffin()
{
}
