#ifndef LeakyBucket_H_
#define LeakyBucket_H_

#include <vector>
#include <omnetpp.h>
#include "Packet_m.h"

class LeakyBucket: public cSimpleModule {
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

		virtual void initialize();
		//virtual void handleMessage(cMessage* msg);
		virtual void activity();

	private:
        simsignal_t signalQSize;
        simsignal_t signalAccepted;
        simsignal_t signalRejected;
};

#endif /* LeakyBucket_H_ */
