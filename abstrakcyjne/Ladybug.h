#pragma once
#include "Monster.h"
class Ladybug :
	public Monster
{
public:
	Ladybug(int maxHP, int lvl);
	int getAtkVal() override;
	~Ladybug();
};

