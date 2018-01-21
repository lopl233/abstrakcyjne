#include "Griffin.h"


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
