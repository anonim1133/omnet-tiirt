#ifndef wRED_H_
#define wRED_H_

#include "AdmissionControl.h"

class wRED: public AdmissionControl{
	public:
		wRED();
		virtual ~wRED();
	protected:
		unsigned mean;
		unsigned max_queue_size;

		bool check(int priority);
};

#endif /* wRED_H_ */
