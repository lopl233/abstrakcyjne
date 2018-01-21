#pragma once
#include "Monster.h"

class Griffin :
	public Monster
{
public:
	Griffin(int maxHP, int lvl);
	int getAtkVal() override;
	~Griffin();
};

