#include <omnetpp.h>
#include <stdio.h>
#include <string.h>

using namespace omnetpp;

class initNode: public cSimpleModule {
  private:
    simtime_t timeout;
    cMessage *timeoutEvent;

  public:
    initNode();
    virtual ~initNode();

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(initNode);

initNode::initNode() {
  timeoutEvent = nullptr;
}

initNode::~initNode() {
  cancelAndDelete(timeoutEvent);
}


void initNode::initialize() {
  timeout = 1.0;
  timeoutEvent = new cMessage("timeoutEvent");

  EV << "Node received packet - forward to next node\n";
  cMessage *msg = new cMessage("packet");
  send(msg, "out");
  
  scheduleAt(simTime() + timeout, timeoutEvent);
}

void initNode::handleMessage(cMessage *msg) {

  std::string name = par("name");
  EV << name << " received packet - forward to next node\n";
	cancelEvent(timeoutEvent);
	delete msg;
   
}

class Node: public cSimpleModule {
  protected:
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Node);

void Node::handleMessage(cMessage *msg) {

  std::string name = par("name");
  EV << name << " received packet - forward to next node\n";
	// delete msg;

	cMessage *newMsg = new cMessage("packet");
	send(msg, "out");
   
}

class endNode: public cSimpleModule {
  protected:
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(endNode);

void endNode::handleMessage(cMessage *msg) {
  std::string name = par("name");
  EV << name << " last to receive message\n";
  // delete msg;
}