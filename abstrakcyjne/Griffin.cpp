#include "Griffin.h"


Griffin::Griffin() : Griffin(48, 1)
{
}

Griffin::Griffin(const int maxHP, const int lvl): Monster(maxHP,lvl, "griffin.png")
{
	setExp(50 * lvl);
}


Griffin::~Griffin()
{
}
