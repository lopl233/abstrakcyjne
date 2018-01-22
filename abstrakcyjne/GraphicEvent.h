#pragma once
#include <string>

class GraphicEvent
{
private:
	int startTime;
	int endTime;


public:
	GraphicEvent();
	virtual ~GraphicEvent();

	virtual double getX(int now) = 0;
	virtual double getY(int now) = 0;
	virtual int getAngle(int now) = 0;
	virtual std::string getTextureName() = 0;
	virtual int getStartTime() { return startTime; }
	virtual void setStartTime(int sTime) { startTime = sTime; }
	virtual int getEndTime() { return endTime; }
	virtual void setEndTime(int eTime) { endTime = eTime; }
	virtual int getSize(int now) = 0;
};

