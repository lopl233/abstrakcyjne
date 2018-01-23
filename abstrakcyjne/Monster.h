#pragma once
#include <string>

class Monster {
public:
	virtual ~Monster() = default;

	virtual int getMaxHp()
	{
		return maxHp;
	}

	virtual int getCurrHp()
	{
		return currentHp;
	}

	virtual void setCurrHp(int val) 
	{
		currentHp = val;
	}

	virtual int getLevel()
	{
		return level;
	}

	virtual std::string getFilename()
	{
		return filename;
	}

	virtual int getAtkVal() = 0;
	
	virtual int getExp()
	{
		return exp;
	}

	virtual void setExp(int val) { exp = val; }


protected:
	Monster() {}
	Monster(int maxHP, int lvl, std::string filename) : level(lvl), maxHp(maxHP), currentHp(maxHP), filename(filename){}
private:
	int maxHp;
	int currentHp;
	int level;
	int exp;
	std::string filename;
};
