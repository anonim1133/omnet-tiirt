//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WAPrioritySchedulerANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "PriorityScheduler.h"

Define_Module(PriorityScheduler);

PriorityScheduler::PriorityScheduler(){
	current = queues.begin();
}

int PriorityScheduler::chooseQueue(){
	int priority = 0;
	int pos = -1;

	for( map<int, vector<Packet*> >::iterator i = queues.begin(); i != queues.end(); ++i){
		if(i->second.size() > 0 && i->second.at(0)->getPriority() > priority){
			priority = i->second.at(0)->getPriority();
			pos = i->first;
		}
	}
return pos;
}
