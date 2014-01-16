#include <omnetpp.h>
#include "Packet_m.h"

#include <map>

typedef std::map<int, cLongHistogram*> PriorityStatsMap;

class Sink : public cSimpleModule
{
    public:
        virtual ~Sink();
	protected:
        virtual void initialize();
        virtual void finish();
		virtual void handleMessage(cMessage* msg);
	private:
		simsignal_t eventSignal;
        PriorityStatsMap priorityStats;

        cLongHistogram* getHistogram(int priority);
        cLongHistogram* createHistogram(int priority);
};

