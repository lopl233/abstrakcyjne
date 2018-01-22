#pragma once

#include <set>
#include "GraphicEvent.h"

class GraphicEventQ
{
private:

	std::set< GraphicEvent*> set;

public:
	GraphicEventQ();
	~GraphicEventQ();
	void addEvent(GraphicEvent *event) {
		set.insert(event);
	}

	void removeOldEvents(int now) {
		for (auto it = set.begin(); it != set.end(); ) {
			if ((*it)->getEndTime() < now) {
				set.erase(it++);
			}
			else ++it;
		}
	
	}

	auto begin() {
		return set.begin();
	}
	auto end() {
		return set.end();
	}


};

