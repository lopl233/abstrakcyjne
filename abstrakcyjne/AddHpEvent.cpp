#include "AddHpEvent.h"



AddHpEvent::AddHpEvent(GameModel *gamemodel, GraphicEventQ * graphiceventq, int processtime):Event(gamemodel, graphiceventq, processtime)
{
	eventType = "AddHpEvent";

}


AddHpEvent::~AddHpEvent()
{
}
