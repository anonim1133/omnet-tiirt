#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <omnetpp.h>
#include "SimpleGen.h"
#include "Packet_m.h"

using namespace std;

class MMPPGen : public SimpleGen
{
	public:
		virtual ~MMPPGen();

	protected:
		int state;
		int states;
		double** matrix;
		double* lambdas;

		virtual void initialize();
		virtual bool canSendMessage();
		virtual double getDelay();

	private:
		simsignal_t stateSignal;

		double** generateMatrix();
		void dumpMatrix();
		void deleteMatrix();
		double inline getOutIntensity();
		double inline getNextIntensity();
		double inline getPrevIntensity();
};
