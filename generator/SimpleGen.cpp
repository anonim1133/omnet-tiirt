#include "SimpleGen.h"

SimpleGen::SimpleGen()
{
	// Create event message
	event = new cMessage("event");
	// Initialize...
	sessionId = intuniform(100, 999);
	packetId = 0;
}

SimpleGen::~SimpleGen()
{
	cancelAndDelete(event);
}

void SimpleGen::initialize()
{
	// Start sending messages after 1s
	scheduleAt(1.0, event);
}

void SimpleGen::handleMessage(cMessage* msg)
{
	if (msg == event)
	{
		// It's time to send message, so prepare new one and send
		send(generateMessage(), "out");
		// Send next message after delay
		scheduleAt(simTime()+getDelay(), event);
	}
	else
	{
		// This should never happen, but for sure delete
		delete msg;
	}
}

Packet* SimpleGen::generateMessage()
{
	char name[20];
	packetId += 1;
	// Generate simple message name
	sprintf(name, "msg-%d", packetId);
	Packet* msg = new Packet(name);
	// Set properties
	msg->setSessionID(sessionId);
	msg->setPacketID(packetId);
	return msg;
}
