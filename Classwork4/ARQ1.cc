#include <omnetpp.h>
#include <stdio.h>
#include <string.h>

using namespace omnetpp;

class Source: public cSimpleModule {
  private:
   simtime_t timeout;
   cMessage *timeoutEvent;

  public:
   Source();
   virtual ~Source();

  protected:
   virtual void initialize() override;
   virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Source);

Source::Source() {
   timeoutEvent = nullptr;
}

Source::~Source() {
   cancelAndDelete(timeoutEvent);
}

void Source::initialize() {
   //   prob = par("prob");
   timeout = 1.0;
   timeoutEvent = new cMessage("timeoutEvent");

   EV << "Sending intial message\n";
   cMessage *msg = new cMessage("packet");
   send(msg, "out");

   scheduleAt(simTime() + timeout, timeoutEvent);
}

void Source::handleMessage(cMessage *msg) {
   if (msg == timeoutEvent) {

	  EV << "Timeout expired, re sending message and restarting timer\n";
	  cMessage *newMsg = new cMessage("packet");
	  send(newMsg, "out");
	  scheduleAt(simTime() + timeout, timeoutEvent);

   } else {

	  EV << "Timeout cancled\n";
	  cancelEvent(timeoutEvent);
	  delete msg;

	  cMessage *newMsg = new cMessage("packet");
	  send(newMsg, "out");
	  scheduleAt(simTime() + timeout, timeoutEvent);
   }
}

class Destination: public cSimpleModule {
  protected:
   virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Destination);

void Destination::handleMessage(cMessage *msg) {
   double counter = par("prob");
   //   if (uniform(0, 1) < 0.1) {
   if (counter == 0) {
	  EV << "\"Message\" lost.\n";
	  bubble("message lost");
	  delete msg;
   } else {
	  EV << "Sending back same message as ACK.\n";
	  send(msg, "out");
   }
}

