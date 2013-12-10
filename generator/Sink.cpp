#include "Sink.h"

Define_Module(Sink)
;

void Sink::handleMessage(cMessage* msg)
{
	LabMsg* labMsg = check_and_cast<LabMsg*>(msg);
	delete msg;
}
