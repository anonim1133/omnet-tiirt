#ifndef HTokenBucket_H_
#define HTokenBucket_H_

#include <vector>
#include <omnetpp.h>
#include "TokenBucket.h"

class HTokenBucket: public TokenBucket {
	public:
		HTokenBucket();
		virtual ~HTokenBucket();
	protected:

		//virtual void handleMessage(cMessage* msg);
		virtual void activity();
};

#endif /* HTokenBucket_H_ */
