#ifndef __SIMPLEGEN_H__
#define __SIMPLEGEN_H__

#include <omnetpp.h>
#include "Packet_m.h"

class SimpleGen : public cSimpleModule
{
	public:
		SimpleGen();
		virtual ~SimpleGen();

	protected:
		int sessionId;
		int packetId;

		virtual void initialize();
		virtual void handleMessage(cMessage* msg);

		virtual Packet* generateMessage();
		virtual bool canSendMessage();
		virtual double getDelay() = 0;

	private:
		cMessage* event;
		simsignal_t eventSignal;
};

#endif // __ SIMPLEGEN _H__
