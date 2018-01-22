#include "PointToPointEvent.h"



PointToPointEvent::PointToPointEvent(int startTime, int endTime, int xStart, int xEnd, int yStart, int yEnd,std::string textureName)
{
	this->yStart = yStart;
	this->yEnd = yEnd;
	this->xStart = xStart;
	this->xEnd = xEnd;
	setStartTime(startTime);
	setEndTime(endTime);
	texturename = textureName;
}


PointToPointEvent::~PointToPointEvent()
{
}
