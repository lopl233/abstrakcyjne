#pragma once
#include "GameModel.h"
#include "GraphicEventQ.h"
#include <string>

class Event
{

protected:
	GameModel * gamemodel;
	GraphicEventQ * graphiceventq;
	std::string eventType;
	int processingTime;

public:
	Event(GameModel *gamemodel, GraphicEventQ * graphiceventq, int processtime);
	~Event();
	virtual std::string getEventType(){ return eventType; }
	virtual void processEvent() = 0;
	virtual int getProcessingTime() { return processingTime; }
};

