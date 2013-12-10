/*
 * SourceBanlist.cpp
 *
 *  Created on: Dec 10, 2013
 *      Author: anonim1133
 */

#include "SourceBanlist.h"

Define_Module(SourceBanlist);

SourceBanlist::SourceBanlist(){
	ban_list.push_back(4);
	ban_list.push_back(7);
	ban_list.push_back(11);
}

SourceBanlist::~SourceBanlist(){
	// TODO Auto-generated destructor stub
}

bool SourceBanlist::check(Packet* packet){
	for(unsigned i=0; i < ban_list.size(); i++){
		if(ban_list.at(i) == packet->getSrc())
			return false;
	}
	return true;
}
