#ifndef TokenBucket_H_
#define TokenBucket_H_

#include <vector>
#include <omnetpp.h>
#include "Packet_m.h"

class TokenBucket: public cSimpleModule{
	public:
		TokenBucket();
		virtual ~TokenBucket();
	protected:
		std::vector<Packet*> queue;
		std::vector<bool> tokens;
		unsigned rejected;
		unsigned queued;
		unsigned queue_size;
		unsigned tokens_size;
		unsigned sent;
		simtime_t interval;
		simtime_t last_sent;


		unsigned max_queue_size;
		unsigned max_tokens_size;
		//void handleMessage(cMessage* msg);
		void activity();
};

#endif /* TokenBucket_H_ */
