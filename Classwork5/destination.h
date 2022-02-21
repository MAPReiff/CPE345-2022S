#ifndef __ARQ2_DESTINATION_H_
#define __ARQ2_DESTINATION_H_

#include <omnetpp.h>

using namespace omnetpp;

class Destination: public cSimpleModule {
	protected:
		virtual void handleMessage(cMessage *msg);
};

#endif