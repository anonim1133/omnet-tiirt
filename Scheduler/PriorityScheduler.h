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

#ifndef PriorityScheduler_H_
#define PriorityScheduler_H_

#include <vector>
#include <map>
#include <limits>
#include <omnetpp.h>
#include "Packet_m.h"
#include "FCFS.h"

using namespace std;

class PriorityScheduler: public FCFS
{
	public:
		PriorityScheduler();

	protected:
		int chooseQueue();

		map< int, vector<Packet*> >::iterator current;
};

#endif /* PriorityScheduler_H_ */
