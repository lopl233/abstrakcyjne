#pragma once
#include "Event.h"
#include "Hero.h"
#include "Field.h"
#include "GameModel.h"
#include <iostream>
#include "PointToPointEvent.h"

class HitMonster :
	public Event
{
private:
	Field * field;
	int x;
	int y;

public:
	HitMonster(GameModel *gamemodel, GraphicEventQ * graphiceventq, int processtime, int x, int y);
	~HitMonster();

	void addField(Field * field) {
		this->field = field;
	}

	virtual void processEvent(int now) {
		Hero * hero = gamemodel->getHero();
		int monster_hp = field->GetMonster()->getCurrHp();
		int atk_val = hero->getAtkVal();
		field->GetMonster()->setCurrHp(monster_hp - atk_val);
		if (field->GetMonster()->getCurrHp() <= 0) {
			hero->addExp(field->GetMonster()->getExp());
			field->setMonster(nullptr);
			gamemodel->getHero()->clearTarget();
			gamemodel->getEventQ()->deleteEventsWithType("HitHero");

		}
		else
		{
			HitMonster * event = new HitMonster(gamemodel, graphiceventq, processingTime + 1000,x,y);
			event->addField(field);
			gamemodel->getEventQ()->addEvent(event);
			graphiceventq->addEvent(new PointToPointEvent(now, now + 1000, hero->getX(), x, hero->getY(), y, "shuriken.png"));
		}
	
	}
};

