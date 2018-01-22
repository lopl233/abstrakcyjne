#pragma once
#include "Field.h"
class WallField :
	public Field
{
public:
	WallField();
	void AddMonster(std::shared_ptr<Monster> monster) override;
	~WallField();
};

