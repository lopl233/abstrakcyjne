#pragma once
#include "Event.h"
#include <iostream>
#include "Hero.h"
#include "GameModel.h"

class AddHpEvent :
	public Event
{
public:
	AddHpEvent(GameModel *gamemodel, GraphicEventQ * graphiceventq, int processtime);
	~AddHpEvent();

	virtual void processEvent() {
		Hero * hero = gamemodel->getHero();
		int maxhp = hero->getMAX_HP();
		hero->addHP(maxhp * 0.05);
		if (hero->getCURRENT_HP() > maxhp)hero->setCURRENT_HP(maxhp);
		gamemodel->getEventQ()->addEvent(new AddHpEvent(gamemodel, graphiceventq, processingTime + 5000));
		
	}
};

