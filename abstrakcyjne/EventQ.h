#pragma once

#include <map>
#include "Event.h"
#include <string>

class EventQ
{
private:

	std::multimap<int, Event*> *events = new std::multimap<int, Event*>;
public:

	EventQ();
	~EventQ();
	void addEvent(Event * event) {
		events->insert(std::pair<int, Event*>(event->getProcessingTime(),event));
	}

	void proccessQ(int now) {
		auto it = events->begin();
		while ((!events->empty())&&(*it).first < now)
		{
			(*it).second->processEvent();
			events->erase(it);
			it = events->begin();
		}
	}

	void deleteEventsWithType(std::string eventType) {
		for (auto it = events->begin(); it != events->end();) {
			if ((*it).second->getEventType().compare(eventType) == 0)
				it = events->erase(it);
			else
				++it;
		}
	}

};

