#include "Sink.h"

Define_Module(Sink);

void Sink::initialize()
{
    eventSignal = registerSignal("event");
}

void Sink::handleMessage(cMessage* msg)
{
    double currentTime = simTime().dbl();
	Packet* packet = check_and_cast<Packet*>(msg);
	double delay = currentTime-packet->getCreationTime();

	EV << "Send time: " << delay << endl;
	emit(eventSignal, delay);

	delete msg;
}
