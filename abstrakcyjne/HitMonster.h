#pragma once
#include "Event.h"
#include "Hero.h"
#include "Field.h"
#include "GameModel.h"
#include <iostream>

class HitMonster :
	public Event
{
private:
	Field * field;

public:
	HitMonster(GameModel *gamemodel, GraphicEventQ * graphiceventq, int processtime);
	~HitMonster();

	void addField(Field * field) {
		this->field = field;
	}

	virtual void processEvent() {
		Hero * hero = gamemodel->getHero();
		int monster_hp = field->GetMonster()->getCurrHp();
		int atk_val = hero->getAtkVal();
		field->GetMonster()->setCurrHp(monster_hp - atk_val);
		if (field->GetMonster()->getCurrHp() <= 0) {
			field->setMonster(nullptr);
			gamemodel->getHero()->clearTarget();
			gamemodel->getEventQ()->deleteEventsWithType("HitPlayer");
		}
		else
		{
			HitMonster * event = new HitMonster(gamemodel, graphiceventq, processingTime + 1000);
			event->addField(field);
			gamemodel->getEventQ()->addEvent(event);
		}
	
	}
};

