#include "Event.h"



Event::Event(GameModel *gamemodel, GraphicEventQ * graphiceventq, int processtime) :gamemodel(gamemodel), graphiceventq(graphiceventq), processingTime(processtime)
{
}


Event::~Event()
{
}
