/*
 * Lab1.cc
 *
 *  Created on: 07-11-2013
 *      Author: Ola
 */



#include <omnetpp.h>
#include "LabMsg_m.h"

class SimpleGen: public cSimpleModule
{
public:
    SimpleGen();
    virtual ~SimpleGen();

protected:
    cMessage* event;
    int sessionId;
    int packetId;

    virtual void initialize();
    virtual void handleMessage(cMessage* msg);
    virtual LabMsg* generateMessage();
    virtual double getDelay() = 0;
};

SimpleGen::SimpleGen()
{
    // Create event message
    event = new cMessage("event");
    // Initialize...
    sessionId = intuniform(100, 999);
    packetId = 0;
}

SimpleGen::~SimpleGen()
{
    cancelAndDelete(event);
}

void SimpleGen::initialize()
{
    // Start sending messages after 1s
    scheduleAt(1.0, event);
}

void SimpleGen::handleMessage(cMessage* msg)
{
    if (msg == event)
    {
        // It's time to send message, so prepare new one and send
        send(generateMessage(), "out");
        // Send next message after delay
        scheduleAt(simTime()+getDelay(), event);
    }
    else
    {
        // This should never happen, but for sure delete
        delete msg;
    }
}

LabMsg* SimpleGen::generateMessage()
{
    char name[20];
    packetId += 1;
    // Generate simple message name
    sprintf(name, "msg-%d", packetId);
    LabMsg* msg = new LabMsg(name);
    // Set properties
    msg->setSessionId(sessionId);
    msg->setPacketId(packetId);
    return msg;
}

/* ============================================================ */

class Sink: public cSimpleModule
{
protected:
    virtual void handleMessage(cMessage* msg);
};

Define_Module(Sink);

void Sink::handleMessage(cMessage* msg)
{
    LabMsg* labMsg = check_and_cast<LabMsg*>(msg);
    delete msg;
}

/* ============================================================ */

class PoissonGen: public SimpleGen
{
protected:
    virtual void initialize();
    virtual double getDelay();
private:
    double lambda;
};

Define_Module(PoissonGen);

void PoissonGen::initialize()
{
    lambda = par("lambda");
    SimpleGen::initialize();
}

double PoissonGen::getDelay()
{
    return poisson(lambda);
}

/* ============================================================ */

class ExponentialGen: public SimpleGen
{
protected:
    virtual void initialize();
    virtual double getDelay();
private:
    double mean;
};

Define_Module(ExponentialGen);

void ExponentialGen::initialize()
{
    mean = par("mean");
    SimpleGen::initialize();
}

double ExponentialGen::getDelay()
{
    return exponential(mean);
}

/* ============================================================ */

class MMPPGen: public SimpleGen
{
public:
    virtual ~MMPPGen();
protected:
    virtual void initialize();
    virtual double getDelay();
private:
    int state;
    int states;
    double** matrix;
};

Define_Module(MMPPGen);

MMPPGen::~MMPPGen()
{
    for (int i = 0; i < states; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void MMPPGen::initialize()
{
    state = 0;
    states = par("states");

    matrix = new double* [states];
    for (int i = 0; i < states; i++)
    {
        matrix[i] = new double[state];
    }
}

double MMPPGen::getDelay()
{
    return 1.0;
}
