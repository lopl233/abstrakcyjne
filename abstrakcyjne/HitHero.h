#pragma once
#include "Event.h"
#include "Hero.h"
#include "Field.h"
#include "GameModel.h"
#include <iostream>
#include "constants.cpp"

class HitHero :
	public Event
{
private:
	Field * field;

public:
	HitHero(GameModel *gamemodel, GraphicEventQ * graphiceventq, int processtime);
	~HitHero();

	void addField(Field * field) {
		this->field = field;
	}
	virtual void processEvent() {
		Hero * hero = gamemodel->getHero();
		int hero_hp = hero->getCURRENT_HP();
		auto monster = field->GetMonster();
		int atk_val = monster-> getAtkVal();
		std::cout << "Attack val = " << atk_val << std::endl;
		hero->setCURRENT_HP(hero_hp - atk_val);
		if (hero->getCURRENT_HP() <= 0) {
			hero->clearTarget();
			gamemodel->getEventQ()->deleteEventsWithType("HitHero");
			gamemodel->getEventQ()->deleteEventsWithType("HitMonster");
			hero->setX(20);
			hero->setY(20);
			hero->setCURRENT_HP(hero->getMAX_HP());
			hero->setCURRENT_MP(hero->getMAX_MP());
		}
		else
		{
			HitHero * event = new HitHero(gamemodel, graphiceventq, processingTime + 1000);
			event->addField(field);
			gamemodel->getEventQ()->addEvent(event);
		}

		std::cout << "Hero hp = " << hero->getCURRENT_HP() << std::endl;

	}

};

