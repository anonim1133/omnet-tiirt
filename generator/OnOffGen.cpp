#include "OnOffGen.h"

Define_Module(OnOffGen)
;

OnOffGen::~OnOffGen()
{
}

bool OnOffGen::canSendMessage()
{
	// Send only in "On" state
	return MMPPGen::canSendMessage() && state == 0;
}
