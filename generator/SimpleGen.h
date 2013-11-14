#include <omnetpp.h>
#include "Packet_m.h"

class SimpleGen: public cSimpleModule{
public:
	SimpleGen();
	virtual ~SimpleGen();

protected:
	cMessage* event;
	int sessionId;
	int packetId;

	virtual void initialize();
	virtual void handleMessage(cMessage* msg);
	virtual Packet* generateMessage();
	virtual double getDelay() = 0;
};
