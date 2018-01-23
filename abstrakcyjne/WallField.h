#pragma once
#include "Field.h"
class WallField :
	public Field
{
public:
	WallField();
	void AddMonster(std::shared_ptr<Monster> monster) override;
	void AddPotion(std::shared_ptr<Potion>) override;
	~WallField();
};

