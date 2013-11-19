#include <omnetpp.h>
#include "SimpleGen.h"
#include "Packet_m.h"

class OnOffGenerator : public SimpleGen{

  private:
    Packet *event;
    int sessionCounter;
    int stopped;
    int lowerB;
	int upperB;
	int threshold;

    double delay;
    long wentOut;
    cDoubleHistogram departureDelay;
    cOutVector departureTime;

  public:
    virtual void initialize();
	virtual double getDelay();
};
