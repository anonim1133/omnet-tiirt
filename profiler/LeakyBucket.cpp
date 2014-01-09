/*
 * LeakyBucket.cpp
 *
 *  Created on: Dec 10, 2013
 *      Author: anonim1133
 */

#include "LeakyBucket.h"

Define_Module(LeakyBucket);

LeakyBucket::LeakyBucket():cSimpleModule(1024) {
//	max_queue_size = 32;//par("max_queue_size");
	last_sent = 0.0;
//	interval= 0.1;
	queue_size = 0;
	rejected = 0;
	queued = 0;
	queued = 0;
	sent = 0;
}

LeakyBucket::~LeakyBucket(){
	// TODO Auto-generated destructor stub
}

void LeakyBucket::initialize() {
    max_queue_size = par("max_queue_size");
    interval= par("interval");
}

void LeakyBucket::activity(){
	while(true){
		EV<<"LeakyQsize: "<<queue_size<<" simTime:"<< simTime() <<" last_sent:"<< last_sent <<std::endl;
		cMessage* msg = receive();
		if(msg != NULL && (queue_size < max_queue_size)){
			Packet* packet = check_and_cast<Packet*>(msg);
			queue.push_back(packet);
			queued++;
		}else rejected++;

		if((simTime()-last_sent) > interval){
			Packet* packet = queue.front();
			queue.erase(queue.begin());
			send(packet, "out");

			last_sent = simTime();
			sent++;
		}

		queue_size = queue.size();
	}
}
