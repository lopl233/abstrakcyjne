#pragma once
#include "FieldHolder.h"
#include "Hero.h"
#include "EventQ.h"



class GameModel
{
private:
	FieldHolder *fieldholder;
	Hero* hero;
	EventQ * eventQ;


public:
	GameModel();
	~GameModel();
	Hero * getHero() const { return hero; }
	FieldHolder * getFieldHolder() const { return fieldholder; }
	EventQ * getEventQ() { return eventQ; }
};

