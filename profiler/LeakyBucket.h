#ifndef LeakyBucket_H_
#define LeakyBucket_H_

#include <vector>
#include <omnetpp.h>
#include "Packet_m.h"

class LeakyBucket: public cSimpleModule{
	public:
		LeakyBucket();
		virtual ~LeakyBucket();
	protected:
		std::vector<Packet*> queue;
		unsigned rejected;
		unsigned queued;
		unsigned queue_size;
		unsigned sent;
		simtime_t interval;
		simtime_t last_sent;


		unsigned max_queue_size;
		//void handleMessage(cMessage* msg);
		void activity();
};

#endif /* LeakyBucket_H_ */
