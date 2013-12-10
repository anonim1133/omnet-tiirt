#ifndef RED_H_
#define RED_H_

#include "AdmissionControl.h"

class RED: public AdmissionControl{
	public:
		RED();
		virtual ~RED();
	protected:
		unsigned mean;
		unsigned max_queue_size;

		bool check(int priority);
};

#endif /* RED_H_ */
