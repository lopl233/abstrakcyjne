#pragma once
#include "Field.h"
class WallField :
	public Field
{
public:
	WallField();
	void AddMonster(Monster* monster) override;
	~WallField();
};

