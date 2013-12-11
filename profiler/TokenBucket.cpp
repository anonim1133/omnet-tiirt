/*
 * TokenBucket.cpp
 *
 *  Created on: Dec 10, 2013
 *      Author: anonim1133
 */

#include "TokenBucket.h"

Define_Module(TokenBucket);

TokenBucket::TokenBucket():cSimpleModule(1024){
	max_queue_size = 32;
	max_tokens_size = 32;
	last_sent = 0.0;
	interval= 0.1;
	queue_size = 0;
	tokens_size = 0;
	rejected = 0;
	queued = 0;
	queued = 0;
	sent = 0;
}

TokenBucket::~TokenBucket(){
	// TODO Auto-generated destructor stub
}

void TokenBucket::activity(){
	while(true){
		EV<<"LeakyQsize: "<<queue_size<<" simTime:"<< simTime() <<" last_sent:"<< last_sent <<std::endl;
		cMessage* msg = receive();
		if(msg != NULL && (queue_size < max_queue_size)){
			Packet* packet = check_and_cast<Packet*>(msg);
			queue.push_back(packet);
			queued++;
		}else rejected++;

		if((simTime()-last_sent) > interval && tokens_size < max_tokens_size){
			tokens.push_back(true);

			last_sent = simTime();
		}

		if(tokens_size>0){
			Packet* packet = queue.front();
			queue.erase(queue.begin());

			send(packet, "out");

			sent++;
			tokens.erase(tokens.begin());
		}

		tokens_size = tokens.size();
		queue_size = queue.size();
	}
}

/*
void handleMessage(cMessage* msg)
{
	Packet* packet = check_and_cast<Packet*>(msg);

	if(!msg->isSelfMessage()){
			scheduleAt(simTime(), packet);//wy��lij, po simTime mo��na doda�� delay
	}else{//Przyjmij pakiet do kolejki
			Packet* packet = queue.front();
			queue.erase(queue.begin());
			send(packet, "out");
		EV <<queue.size()<<std::endl;
	}
}
*/
