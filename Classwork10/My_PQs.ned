//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

import org.omnetpp.queueing.Classifier;
import org.omnetpp.queueing.PassiveQueue;
import org.omnetpp.queueing.Server;
import org.omnetpp.queueing.Sink;
import org.omnetpp.queueing.Source;


network My_PQs
{
    @display("bgb=510,302");
    submodules:
        source: Source {
            @display("p=75,78");
        }
        source1: Source {
            @display("p=75,157");
        }
        classifier: Classifier {
            @display("p=158,118");
        }
        passiveQueue: PassiveQueue {
            @display("p=266,78");
        }
        passiveQueue1: PassiveQueue {
            @display("p=266,157");
        }
        server: Server {
            @display("p=371,118");
        }
        sink: Sink {
            @display("p=449,118");
        }
    connections:
        source.out --> classifier.in++;
        source1.out --> classifier.in++;
        classifier.out++ --> passiveQueue.in++;
        classifier.rest --> passiveQueue1.in++;
        passiveQueue1.out++ --> server.in++;
        passiveQueue.out++ --> server.in++;
        server.out --> sink.in++;
}
