#pragma once
#include <string>
#include "Monster.h"

class Field
{
protected:
	std::string filename;
	bool canBeSteped;
	Monster* monster = nullptr;
public:
	Field();
	virtual std::string getFilename()
	{
		return filename;
	}
	virtual bool CanBeStepped()
	{
		return canBeSteped;
	}
	virtual Monster* GetMonster()
	{
		return monster;
	}
	virtual void AddMonster(Monster* monster)
	{
		this->monster = monster;
	}
	virtual ~Field() = 0;
};

