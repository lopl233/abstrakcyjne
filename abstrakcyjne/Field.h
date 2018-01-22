#pragma once
#include <string>
#include "Monster.h"
#include <memory>

class Field
{
protected:
	std::string filename;
	bool canBeSteped;
	std::shared_ptr<Monster> monster = nullptr;
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
	virtual std::shared_ptr<Monster> GetMonster()
	{
		return monster;
	}
	virtual void AddMonster(const std::shared_ptr<Monster> monster)
	{
		this->monster = monster;
	}
	virtual ~Field() = 0;
};

