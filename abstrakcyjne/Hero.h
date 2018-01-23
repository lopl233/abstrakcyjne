#pragma once
#include <string>
#include "Direction.h"
#include "Field.h"
#include <iostream>

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
	bool have_target = false;
	int target_x;
	int target_y;
	int atk_val;

	virtual void lvlUp() = 0;



protected:
	Hero(int maxHp, int maxMp, std::string filename);

public:
	virtual ~Hero();
	virtual int getMAX_HP() { return maxHp; }
	virtual void setMAX_HP(const int MAX_HP) { maxHp = MAX_HP; }
	virtual int getCURRENT_HP() { return currentHp; }
	virtual void setCURRENT_HP(const int CURRENT_HP) { currentHp = CURRENT_HP; }
	virtual int getMAX_MP() { return maxMp; }
	virtual void setMAX_MP(const int MAX_MP) { maxHp = MAX_MP; }
	virtual int getCURRENT_MP() { return currentMp; }
	virtual void setCURRENT_MP(const int CURRENT_MP) { currentMp = CURRENT_MP; }
	virtual int getEXP() { return exp; }
	virtual int getNEXTLVLEXP() { return next_lvl_exp; }
	virtual int getLVL() { return lvl; }
	virtual int getX() { return x; }
	virtual void setX(int val) { x = val; }
	virtual int getY() { return y; }
	virtual void setY(int val) { y = val; }
	virtual int getAtkVal() { return atk_val; }
	virtual void setAtkVal(int val) { atk_val = val; }
	virtual Direction getDirection() { return direction; }

	virtual void addHP(const int val) { currentHp += val; if (currentHp > maxHp) currentHp = maxHp; }
	virtual void addMP(const int val) { currentMp += val; if (currentMp > maxMp) currentMp = maxMp; }
	virtual void setTarget(int x, int y) { have_target = true; target_x = x; target_y = y; }
	virtual void clearTarget() { have_target = false; }
	virtual bool haveTarget() { return have_target; }
	virtual int getTargetX() { return target_x; }
	virtual int getTargetY() { return target_y; }
	virtual void addExp(const int EXP) {
		exp += EXP;
		std::cout << "adding exp : " << EXP << "exp :" << exp << "lvl " << lvl << std::endl;
		while (exp >= next_lvl_exp) {
			
			lvlUp();
			lvl += 1;
			next_lvl_exp += (int)(next_lvl_exp*1.2);
		}
	}
	virtual std::string getFilename()
	{
		return filename;
	}
	virtual void move(const Direction d)
	{
		direction = d;
		switch (d)
		{
		case NORTH:
			y++;
			break;
		case WEST:
			x++;
			break;
		case EAST:
			x--;
			break;
		case SOUTH:
			y--;
			break;
		}
	}
};
