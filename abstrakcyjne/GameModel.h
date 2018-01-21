#pragma once
#include "FieldHolder.h"
#include "Hero.h"



class GameModel
{
private:
	FieldHolder *fieldholder;
	Hero* hero;


public:
	GameModel();
	~GameModel();
	Hero * getHero() const { return hero; }
	FieldHolder * getFieldHolder() const { return fieldholder; }
};

