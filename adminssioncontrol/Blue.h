#ifndef Blue_H_
#define Blue_H_

#include "AdmissionControl.h"

class Blue: public AdmissionControl{
	public:
		Blue();
		virtual ~Blue();
	protected:
		simtime_t last_time;
		double freezeTime;
		double value;
		double step;
		unsigned max_queue_size;
		unsigned last_queue_size;

		virtual void initialize();

		bool check(Packet* packet);
};

#endif /* Blue_H_ */
