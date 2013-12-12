//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "FCFS.h"

Define_Module(FCFS);

FCFS::FCFS():cSimpleModule(1024){

}

FCFS::~FCFS()
{
	// TODO Auto-generated destructor stub
}

void FCFS::activity(){
	while(true){
		EV<<"PENTLA ";
		cMessage* msg = receive();
		if(msg != NULL){
			Packet* packet = check_and_cast<Packet*>(msg);
			queues[packet->getArrivalGateId()].push_back(packet);
		}

		int choosen = chooseQueue();

		Packet* packet = queues[choosen].front();
		queues[choosen].erase(queues[choosen].begin());
		send(packet, "out");
	}
}

int FCFS::chooseQueue(){
	double p_time = 946080000.0;
	int pos = -1;

	for( map<int, vector<Packet*> >::iterator i = queues.begin(); i != queues.end(); ++i){
		if(i->second.size() > 0 && i->second.at(0)->getCreationTime() < p_time){
			p_time = i->second.at(0)->getCreationTime();
			pos = i->first;
		}
	}
return pos;
}
