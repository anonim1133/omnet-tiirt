#include "Sink.h"

Define_Module(Sink);

void Sink::handleMessage(cMessage* msg)
{
	//Packet* msg = check_and_cast<Packet*>(msg);
	delete msg;
}