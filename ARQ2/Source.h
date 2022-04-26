#ifndef __ARQ2_SOURCE_H_
#define __ARQ2_SOURCE_H_

#include <omnetpp.h>

using namespace omnetpp;

class Source : public cSimpleModule
{
  private:
    simtime_t timeout;
    cMessage *timeoutEvent;
    cPacket *pkt;
    int counter;

  public:
    Source();
    virtual ~Source();

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif

