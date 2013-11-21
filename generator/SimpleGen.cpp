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

void SimpleGen::handleMessage(cMessage* msg){
	if (msg == event){
		// It's time to send message, so prepare new one and send
		// Send next message after delay
		double delay = getDelay();

		if(delay < 0){//to dla onOffa
			scheduleAt(simTime()+5, event);
		}else{
			send(generateMessage(), "out");
			scheduleAt(simTime()+delay, event);
		}
	}
	else{
		// This should never happen, but for sure delete
		delete msg;
	}
}

Packet* SimpleGen::generateMessage(){
	char name[20];
    int src = getId();
    int dest = 31337;
    int priority = intrand(5)+1;
    int Payload = 1;
    int ByteLength = intuniform(0,1000);
    int ds = intrand(2);
	packetId += 1;

	// Generate simple message name
	sprintf(name, "msg-%d", packetId);

	//Create new packet
	Packet* packet= new Packet(name);

	// Set properties
	packet->setSessionID(sessionId);
	packet->setPacketID(packetId);
    packet->setSrc(src);
    packet->setDst(dest);
    packet->setSessionID(sessionId);
    packet->setPacketID(packetId);
    packet->setPriority(priority);
    packet->setPayload(Payload);
    packet->setByteLength(ByteLength);
    packet->setDs(ds);
    packet->setCreationTime(simTime().dbl());

    return packet;
}
