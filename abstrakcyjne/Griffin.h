#pragma once
#include "Monster.h"

class Griffin :
	public Monster
{
public:
	Griffin();
	Griffin(int maxHP, int lvl);
	int getAtkVal() override;
	~Griffin();
};

