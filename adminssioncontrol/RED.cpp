/*
 * RED.cpp
 *
 *  Created on: Dec 10, 2013
 *      Author: anonim1133
 */

#include "RED.h"

Define_Module(RED);

RED::RED(){
	mean = 1;
	max_queue_size = 32;//par("max_queue_size");
}

RED::~RED(){
	// TODO Auto-generated destructor stub
}

bool RED::check(){
	srand (time(NULL));
	//unsigned r = rand() % max_queue_size;
	//mean = (mean + queue.size());
	//EV<<mean<<":"<<queue.size()<<":"<<packet_no;
	//unsigned prob = r + (mean/packet_no);

	unsigned r = rand() % (queue.size()+1);
	unsigned prob = r + queue.size();


	EV<<"Qsize"<<queue.size()<<" MAX: "<<max_queue_size<<"PROB: "<<prob<<" R: "<<r<<std::endl;

	if(prob>max_queue_size)
		return false;
	else
		return true;
}
