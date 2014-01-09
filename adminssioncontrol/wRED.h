#ifndef wRED_H_
#define wRED_H_

//#include "AdmissionControl.h"
#include "RED.h"

//class wRED: public AdmissionControl{
class wRED: public RED {
	public:
		wRED();
		virtual ~wRED();
	protected:
//		unsigned mean;
//		unsigned max_queue_size;

		virtual bool check(Packet* packet);
};

#endif /* wRED_H_ */
