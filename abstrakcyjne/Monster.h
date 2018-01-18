#pragma once
class Monster {
	virtual int getMaxHp() = 0;

	virtual int getCurrHp() = 0;

	virtual int getAtkVal() = 0;

	virtual void addHp(int hp) = 0;
};