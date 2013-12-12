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

#ifndef ADMISSIONCONTROL_H_
#define ADMISSIONCONTROL_H_

#include <vector>
#include <omnetpp.h>
#include "Packet_m.h"

class AdmissionControl: public cSimpleModule
{
	public:
		AdmissionControl();
		virtual ~AdmissionControl();
	protected:
		std::vector<Packet*> queue;
		int queue_size;
		simtime_t delay;
		unsigned long long packet_no;
		unsigned int accepted;
		unsigned int rejected;

		virtual void initialize();

		virtual void handleMessage(cMessage* msg);
		virtual bool check(Packet* packet);

	private:
		simsignal_t signalQSize;
		simsignal_t signalAccepted;
		simsignal_t signalRejected;
};

#endif /* ADMISSIONCONTROL_H_ */
