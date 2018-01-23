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

	virtual int getLevel()
	{
		return level;
	}

	virtual std::string getFilename()
	{
		return filename;
	}

	virtual int getAtkVal() = 0;

protected:
	Monster() {}
	Monster(int maxHP, int lvl, std::string filename) : maxHp(maxHP), currentHp(maxHP), filename(filename){}
private:
	int maxHp;
	int currentHp;
	int level;
	std::string filename;
};
