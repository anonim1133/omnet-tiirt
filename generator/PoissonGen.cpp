#include "PoissonGen.h"

Define_Module(PoissonGen);

void PoissonGen::initialize()
{
	lambda = par("lambda");
	SimpleGen::initialize();
}

double PoissonGen::getDelay()
{
	return poisson(lambda);
}
