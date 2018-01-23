#pragma once
#include "Hero.h"

class Warrior :
	public Hero
{
private:
	void lvlUp(){
		setMAX_HP(getMAX_HP() + 50);
		setAtkVal(getAtkVal() + 5);
	}

public:
	Warrior();
	~Warrior();
};

