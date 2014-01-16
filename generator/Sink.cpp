#include "Sink.h"

Define_Module(Sink);

Sink::~Sink()
{
    for (PriorityStatsMap::iterator i = priorityStats.begin(); i != priorityStats.end(); i++) {
        delete i->second;
    }
}

void Sink::initialize()
{
    eventSignal = registerSignal("event");
}

void Sink::finish()
{
    char name[25];
    for (PriorityStatsMap::iterator i = priorityStats.begin(); i != priorityStats.end(); i++) {
        sprintf(name, "priority-%d", i->first);
        i->second->recordAs(name);
    }
}

void Sink::handleMessage(cMessage* msg)
{
    double currentTime = simTime().dbl();
	Packet* packet = check_and_cast<Packet*>(msg);
	double delay = currentTime-packet->getCreationTime();
	int priority = packet->getPriority();
	cLongHistogram* stat = getHistogram(priority);

	EV << "Send time: " << delay << endl;
	emit(eventSignal, delay);
	stat->collect(delay);

	delete msg;
}

cLongHistogram* Sink::getHistogram(int priority)
{
  return priorityStats.count(priority) ? priorityStats[priority] : createHistogram(priority);
}

cLongHistogram* Sink::createHistogram(int priority)
{
    cLongHistogram* stat = new cLongHistogram();
    priorityStats[priority] = stat;
    return stat;
}
