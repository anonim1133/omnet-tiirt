#include <omnetpp.h>
#include "Packet_m.h"

class Sink : public cSimpleModule
{
	protected:
		virtual void handleMessage(cMessage* msg);
};

