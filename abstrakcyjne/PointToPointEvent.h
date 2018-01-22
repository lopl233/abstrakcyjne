#pragma once
#include "GraphicEvent.h"
class PointToPointEvent :
	public GraphicEvent
{
private:
	int xStart;
	int xEnd;
	int yStart;
	int yEnd;
	std::string texturename;


public:
	PointToPointEvent(int startTime,int endTime,  int xStart, int xEnd, int yStar, int yEnd, std::string textureName);
	~PointToPointEvent();
	virtual double getX(int now) {	return xEnd - ((double)(getEndTime() - now)*(xEnd - xStart)) / (getEndTime() - getStartTime());}
	virtual double getY(int now) {  return yEnd - ((double)(getEndTime() - now)*(yEnd - yStart)) / (getEndTime() - getStartTime()); }
	virtual int getAngle(int now) { return 0; }
	virtual std::string getTextureName() { return texturename; }
	virtual int getSize(int now) { return 70; }


};

