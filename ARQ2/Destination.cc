#include "Destination.h"

Define_Module(Destination);

void Destination::initialize()
{
    delayStats.setName("Delay");
    histogram.setRangeAuto(100, 1.5);
    histogram.setNumCells(10);
}

void Destination::handleMessage(cMessage* msg)
{
    cPacket* pkt_r = check_and_cast<cPacket *> (msg);
    if (pkt_r->hasBitError()) {
        EV<<"Packet received in error";
        pkt_r ->setKind(1); //NACK
    }
    else {
        EV<<"Packet received correctly";
        pkt_r ->setKind(0); //ACK
        simtime_t delay = simTime()- pkt_r->getCreationTime();
        EV<<"delay =";
        EV<< delay;
        delayStats.collect(delay);
        histogram.collect(delay);
    }
    send(pkt_r, "out");
 }

void Destination::finish()
{
   recordScalar("mean delay",delayStats.getMean());
   recordScalar("max delay",delayStats.getMax());
   recordScalar("std destination",delayStats.getStddev());
   recordScalar("variance",delayStats.getVariance());
   histogram.record();

   EV << "histogram number of overflows = " << histogram.getOverflowCell() <<endl ;
   EV<<"mean delay = \n" << delayStats.getMean() << endl;

}



