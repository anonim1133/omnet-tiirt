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

#include "AdmissionControl.h"

Define_Module(AdmissionControl);

AdmissionControl::AdmissionControl()
{
	delay = 5.5;//par("delay");
	rejected = 0;
	accepted = 0;
	packet_no = 0;
}

AdmissionControl::~AdmissionControl()
{
	// TODO Auto-generated destructor stub
}

void AdmissionControl::handleMessage(cMessage* msg)
{
	Packet* packet = check_and_cast<Packet*>(msg);
	packet_no++;

	if(!msg->isSelfMessage()){
	//EV<<"PRIORITY:"<<packet->getPriority();
		if(this->check(packet->getPriority())){
			accepted += 1;;
			queue.push_back(packet);
			scheduleAt(simTime()+delay, packet);
		}else{
			rejected += 1;
		}
	}else{
			Packet* packet = queue.front();
			queue.erase(queue.begin());
			send(packet, "out");
		EV <<queue.size()<<std::endl;
	}
	EV<<"Qsize: "<<queue.size()<<" Dropped: "<<rejected<<"Accepted: "<<accepted<<std::endl;
}

bool AdmissionControl::check(int priority){
	return true;
}