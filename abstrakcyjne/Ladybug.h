#pragma once
#include "Monster.h"
class Ladybug :
	public Monster
{
public:
	Ladybug();
	Ladybug(int maxHP, int lvl);
	int getAtkVal() { return (int)(getLevel() * 0.5); };
	~Ladybug();
};

