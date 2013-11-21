#include <omnetpp.h>
#include "SimpleGen.h"
#include "Packet_m.h"
#include <sys/time.h>

class OnOffGen : public SimpleGen{

  private:
    Packet *event;
	time_t t;
    double mean;
    bool state;

  public:
    virtual void initialize();
	virtual double getDelay();
	virtual bool checkState();
	virtual void changeState();
};
