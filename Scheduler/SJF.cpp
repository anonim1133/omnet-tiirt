//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "SJF.h"

Define_Module(SJF);

SJF::SJF(){

}

int SJF::chooseQueue(){
	unsigned size = UINT_MAX;
	int pos = -1;

	for( map<int, vector<Packet*> >::iterator i = queues.begin(); i != queues.end(); ++i){
		if(i->second.size() < size){
			size = i->second.size();
			pos = i->first;
		}
	}
return pos;
}
