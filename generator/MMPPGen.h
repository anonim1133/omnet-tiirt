#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <omnetpp.h>
#include "SimpleGen.h"
#include "Packet_m.h"

using namespace std;

class MMPPGen: public SimpleGen{
    private:
        int states;
        vector<double> mmPPLambda;
        int actualstate;
        int mmppStates;
        double** generatorMatrix;
    public:
        MMPPGen();
        MMPPGen(int states, vector<double> mmPPLambda);
        void initialize();
        double** calculateMatrix(int states, double** generatorMatrix);
        virtual void handleMessage(cMessage *msg);
        virtual void sendMessage();
        double getDelay();
};
