#include "source.h"

Define_Module(Source);

Source::~Source() {
	cancelAndDelete(timeoutEvent);
}

int counter;
int currentCount;

Source::Source() {
	timeoutEvent = nullptr;
}

void Source::initialize() {
	counter = par("num_messages");
	timeout = 1.0;
	timeoutEvent = new cMessage("timeoutEvent");
	EV << "Sending initial packet";
	pkt = new cPacket("packet");
	pkt->setBitLength(100);
	cPacket *pkt_copy = pkt->dup();
	send(pkt_copy, "out");
	scheduleAt(simTime() + timeout, timeoutEvent);
}

void Source::handleMessage(cMessage *msg) {
	if (msg == timeoutEvent) {
		EV << "Time out expired";
		cPacket *pkt_copy = pkt->dup();
		send(pkt_copy, "out");
		scheduleAt(simTime() + timeout, timeoutEvent);
	} else {
		cPacket *pktr = check_and_cast<cPacket *>(msg);
		int type = pktr->getKind();
		if (type == 0) {
			cancelEvent(timeoutEvent);
			currentCount++;
			EV << "Timeout cancled - packet #" << currentCount << " ACKed";
			if (currentCount < counter) {
				pkt = new cPacket("packet");
				pkt->setBitLength(100);
				cPacket *pkt_copy = pkt->dup();
				send(pkt_copy, "out");
				scheduleAt(simTime() + timeout, timeoutEvent);
			} else {
				EV << "All packets ACKed";
				delete msg;
			}

		} else {
			cPacket *pkt_copy = pkt->dup();
			send(pkt_copy, "out");
			cancelEvent(timeoutEvent);
			scheduleAt(simTime() + timeout, timeoutEvent);
		}
	}
}
