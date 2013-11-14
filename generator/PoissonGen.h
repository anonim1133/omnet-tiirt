#include <omnetpp.h>
#include "SimpleGen.h"
#include "Packet_m.h"

class PoissonGen: public SimpleGen{
protected:
	virtual void initialize();
	virtual double getDelay();
private:
	double lambda;
};
