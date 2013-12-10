#include <omnetpp.h>
#include "SimpleGen.h"
#include "Packet_m.h"
#include <sys/time.h>
#include "MMPPGen.h"

class OnOffGen : public MMPPGen
{
	public:
		virtual ~OnOffGen();
	protected:
		virtual bool canSendMessage();
};
