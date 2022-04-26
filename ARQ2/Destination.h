#ifndef __ARQ2_DESTINATION_H_
#define __ARQ2_DESTINATION_H_

#include <omnetpp.h>

using namespace omnetpp;

class Destination : public cSimpleModule
{
  private:
    cStdDev delayStats;
    cHistogram histogram;
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage* msg);
    virtual void finish();
};

#endif

