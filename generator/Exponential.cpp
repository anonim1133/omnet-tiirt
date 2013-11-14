#include "Exponential.h"

Define_Module(ExponentialGen);

void ExponentialGen::initialize()
{
	mean = par("mean");
	SimpleGen::initialize();
}

double ExponentialGen::getDelay()
{
	return exponential(mean);
}



