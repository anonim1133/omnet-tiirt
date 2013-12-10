/*
 * Blue.cpp
 *
 *  Created on: Dec 10, 2013
 *      Author: anonim1133
 */

#include "Blue.h"

Define_Module(Blue);

Blue::Blue(){
	last_time = 0.0;
	max_queue_size = 32;//par("max_queue_size");
	last_queue_size = 0;
	freezeTime = uniform(0,0.5);
	step = 0.05;
	value = 0.0;
}

Blue::~Blue(){
	// TODO Auto-generated destructor stub
}

bool Blue::check(Packet* packet){
	srand (time(NULL));
	//Time to change value
	if(simTime()-last_time > 0){
		if(queue.size() > max_queue_size)//Kolejka rośnie, więc zwiększamy value
			if(value < 1)
				value += step;

		if(last_queue_size <= queue.size())//Kolejka zmniejsza się, trzeba uciąć value
			value -= step;
	}

	last_time = simTime();
	last_queue_size = queue.size();

	ev<<"Qsize: "<<queue.size()<<"value"<<std::endl;

	if(queue.size() > max_queue_size)
		return false; //odrzucamy
	else{
		double prob = uniform(0,1);
			if(prob<value)
				return false;
			else
				return true;
	}
}
