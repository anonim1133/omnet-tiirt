#ifndef TokenBucket_H_
#define TokenBucket_H_

#include <vector>
#include <omnetpp.h>
#include "LeakyBucket.h"

class TokenBucket: public LeakyBucket {
	public:
		TokenBucket();
		virtual ~TokenBucket();
	protected:
		std::vector<bool> tokens;
		unsigned tokens_size;
		unsigned max_ttl;
		unsigned max_queue_size;
		unsigned max_tokens_size;

		virtual void initialize();
		//virtual void handleMessage(cMessage* msg);
		virtual void activity();
};

#endif /* TokenBucket_H_ */
