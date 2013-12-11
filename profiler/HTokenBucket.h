#ifndef HTokenBucket_H_
#define HTokenBucket_H_

#include <vector>
#include <omnetpp.h>
#include "Packet_m.h"

class HTokenBucket: public cSimpleModule{
	public:
		HTokenBucket();
		virtual ~HTokenBucket();
	protected:
		std::vector<Packet*> queue;
		std::vector<bool> tokens;

		simtime_t interval;
		simtime_t last_sent;

		unsigned rejected;
		unsigned queued;
		unsigned queue_size;
		unsigned tokens_size;
		unsigned sent;

		unsigned max_ttl;
		unsigned max_queue_size;
		unsigned max_tokens_size;
		//void handleMessage(cMessage* msg);
		void activity();
};

#endif /* HTokenBucket_H_ */
