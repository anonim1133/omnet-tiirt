#include <omnetpp.h>
#include "Packet_m.h"

class Sink : public cSimpleModule
{
	protected:
        virtual void initialize();
		virtual void handleMessage(cMessage* msg);
	private:
		simsignal_t eventSignal;
};

