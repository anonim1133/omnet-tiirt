#include <omnetpp.h>
#include "SimpleGen.h"
#include "Packet_m.h"

class ExponentialGen: public SimpleGen{
protected:
	virtual void initialize();
	virtual double getDelay();
private:
	double mean;
};
