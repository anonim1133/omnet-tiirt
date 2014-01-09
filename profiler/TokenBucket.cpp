/*
 * TokenBucket.cpp
 *
 *  Created on: Dec 10, 2013
 *      Author: anonim1133
 */

#include "TokenBucket.h"

Define_Module(TokenBucket);

TokenBucket::TokenBucket() {
	tokens_size = 0;
}

TokenBucket::~TokenBucket(){
	// TODO Auto-generated destructor stub
}

void TokenBucket::initialize() {
    max_tokens_size = par("max_tokens_size");
    max_ttl = par("max_ttl");
}

void TokenBucket::activity(){
	while(true){
		EV<<"TokenQsize: "<<queue_size<<" simTime:"<< simTime() <<" last_token:"<< last_sent <<std::endl;
		cMessage* msg = receive();
		if(msg != NULL && (queue_size < max_queue_size)){
			Packet* packet = check_and_cast<Packet*>(msg);
			queue.push_back(packet);

			EV<<"Token packet queued"<<std::endl;
			queued++;
		}else{
			EV<<"Token packet rejected"<<std::endl;
			rejected++;
		}

		if((simTime()-last_sent) > interval && tokens_size < max_tokens_size){
			tokens.push_back(true);

			last_sent = simTime();
			EV<<"Token added"<<std::endl;
		}

		if(tokens_size>0){
			Packet* packet = queue.front();
			queue.erase(queue.begin());

			send(packet, "out");

			sent++;
			tokens.erase(tokens.begin());
			EV<<"Token packet sent"<<std::endl;
		}

		for(unsigned i=0; i<tokens.size(); i++){
			if((simTime() - queue[i]->getCreationTime()) > max_ttl)
				queue.erase(queue.begin()+i);
		}

		tokens_size = tokens.size();
		queue_size = queue.size();
	}
}
