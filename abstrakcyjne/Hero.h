#pragma once
#include <string>

enum Direction {
	WEST,
	NORTH,
	EAST,
	SOUTH
};


class Hero
{
private:
	int maxHp;
	int maxMp;
	int currentHp;
	int currentMp;
	Direction direction;
	int x;
	int y;
	int lvl;
	int exp;
	int next_lvl_exp;
	std::string filename;
	virtual void lvlUp() = 0;


protected:
	Hero(int maxHp, int maxMp, std::string filename);

public:
	~Hero();
	virtual int getMAX_HP() { return maxHp; }
	virtual void setMAX_HP(int MAX_HP) { maxHp = MAX_HP; }
	virtual int getCURRENT_HP() { return currentHp; }
	virtual void setCURRENT_HP(int CURRENT_HP) { currentHp = CURRENT_HP; }
	virtual int getMAX_MP() { return maxMp; }
	virtual void setMAX_MP(int MAX_MP) { maxHp = MAX_MP; }
	virtual int getCURRENT_MP() { return currentMp; }
	virtual void setCURRENT_MP(int CURRENT_MP) { currentMp = CURRENT_MP; }
	virtual int getEXP() { return exp; }
	virtual int getNEXTLVLEXP() { return next_lvl_exp; }
	virtual int getLVL() { return lvl; }
	virtual int getX() { return x; }
	virtual int getY() { return y; }
	virtual void addHP(int val) { currentHp += val; if (currentHp > maxHp) currentHp = maxHp;}
	virtual void addMP(int val) { currentMp += val; if (currentMp > maxMp) currentMp = maxMp; }
	virtual void addExp(int EXP) {
		exp += EXP;
		while (exp >= next_lvl_exp) {
			exp = -next_lvl_exp;
			lvlUp();
			lvl += 1;
			next_lvl_exp = (int)(next_lvl_exp*1.2);
		}
	}
	virtual std::string getFilename()
	{
		return filename;
	}
};