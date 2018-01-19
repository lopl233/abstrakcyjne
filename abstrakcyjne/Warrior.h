#pragma once
#include "Hero.h"

class Warrior :
	public Hero
{
private:
	void lvlUp(){
		setMAX_HP(getMAX_HP() + 50);
	}

public:
	Warrior();
	~Warrior();
};

