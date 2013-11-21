#include "OnOffGen.h"

Define_Module(OnOffGen);

void OnOffGen::initialize()
{
	mean = par("mean");
	t = time(NULL)+5;
	state = true;
	SimpleGen::initialize();
}

double OnOffGen::getDelay()
{
	if(checkState()){
		changeState();
	}

	if(state)
		return exponential(mean);
	else return float(-1);
}

bool OnOffGen::checkState(){
	if(t <= time(NULL)){
		return true;
	}
	return false;
}

void OnOffGen::changeState(){
	if(state) state = false;
	else state = true;
}
