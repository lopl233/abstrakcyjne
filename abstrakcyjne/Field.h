#pragma once
#include <string>
#include "Monster.h"
#include <memory>
#include "Potion.h"

class Field
{
protected:
	std::string filename;
	bool canBeSteped;
	std::shared_ptr<Monster> monster = nullptr;
	std::shared_ptr<Potion> potion = nullptr;
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

	virtual void setMonster(std::shared_ptr<Monster> monster)
	{
		this->monster = monster;
	}
	virtual void AddMonster(const std::shared_ptr<Monster> monster)
	{
		if (potion == nullptr)
			this->monster = monster;
	}

	virtual void AddPotion(const std::shared_ptr<Potion> potion)
	{
		if(monster == nullptr)
			this->potion = potion;
	}
	virtual std::shared_ptr<Potion> GetPotion()
	{
		return potion;
	}
	virtual ~Field();
};

