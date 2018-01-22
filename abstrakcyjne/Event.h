#pragma once
#include "GraphicEventQ.h"
#include <string>

class GameModel;
class Event
{
protected:
	GameModel * gamemodel;
	GraphicEventQ * graphiceventq;
	std::string eventType;
	int processingTime;

public:
	Event(GameModel* gamemodel, GraphicEventQ * graphiceventq, int processtime);
	virtual ~Event();
	virtual std::string getEventType(){ return eventType; }
	virtual void processEvent() = 0;
	virtual int getProcessingTime() { return processingTime; }
};

