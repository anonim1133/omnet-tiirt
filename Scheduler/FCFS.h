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

#ifndef FCFS_H_
#define FCFS_H_

#include <vector>
#include <map>
#include <omnetpp.h>
#include "Packet_m.h"

using namespace std;

class FCFS: public cSimpleModule
{
	public:
		FCFS();
		virtual ~FCFS();
	protected:
		map< int, vector<Packet*> > queues;

		void activity();
		int chooseQueue();
};

#endif /* FCFS_H_ */
