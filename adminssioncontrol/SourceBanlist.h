#ifndef SourceBanlist_H_
#define SourceBanlist_H_

#include <vector>
#include "AdmissionControl.h"

class SourceBanlist: public AdmissionControl{
	public:
		SourceBanlist();
		virtual ~SourceBanlist();
	protected:
		std::vector<int> ban_list;

		virtual bool check(Packet* packet);
};

#endif /* SourceBanlist_H_ */
