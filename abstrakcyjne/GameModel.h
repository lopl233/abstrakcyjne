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
	Hero * getHero() { return hero; }
	FieldHolder * getFieldHolder() { return fieldholder; }
};

