#include "OnOffGen.h"

Define_Module(OnOffGen);

void OnOffGen::initialize()
{
	mean = par("mean");
    lowerB = (int) par("lowerBound");
    upperB = (int) par("upperBound");
    threshold = par ("changeValue");
    delay = par("delayTime");
	SimpleGen::initialize();
}

double OnOffGen::getDelay()
{
//bool stopped; 1 = return exponential delay, bez wysłania pakiety;
//	0 - generowanie pakietu przez czas exponential(delay)
    if (stopped == 0)
    {
        Packet *packet = generateMessage();

        send(packet, "out");

        departureDelay.collect(delay);
        wentOut++;
    }

	return exponential(delay);
}



