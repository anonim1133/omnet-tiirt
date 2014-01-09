/*
 * HTokenBucket.cpp
 *
 *  Created on: Dec 10, 2013
 *      Author: anonim1133
 */

#include "HTokenBucket.h"

Define_Module(HTokenBucket);

HTokenBucket::HTokenBucket() {
}

HTokenBucket::~HTokenBucket(){
	// TODO Auto-generated destructor stub
}

void HTokenBucket::activity(){
	while(true){
		EV<<"TokenQsize: "<<queue_size<<" simTime:"<< simTime() <<" last_token:"<< last_sent <<std::endl;
		cMessage* msg = receive();
		if(msg != NULL && (queue_size < max_queue_size)){
			Packet* packet = check_and_cast<Packet*>(msg);
			for(unsigned i = 0; i<queue.size(); i++){//wrzuca w odpowiednie miejsce kolejki w zaleznosci od priorytetu
				if(packet->getPriority() > queue[i]->getPriority() && queue_size > 0){
					queue.insert(queue.begin()+i, packet);
					break;
				}
			}

			if(queue.size()==queue_size)//Jak nie znalazl sobie miejsca, to dorzuca pakiet na koncu
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
