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

import org.omnetpp.queueing.Queue;
import org.omnetpp.queueing.Sink;
import org.omnetpp.queueing.Source;


network MM1_S22
{
    @display("bgb=475,267");
    submodules:
        source: Source {
            @display("p=45,85");
        }
        queue: Queue {
            @display("p=135,85");
        }
        sink: Sink {
            @display("p=220,85");
        }
    connections:
        source.out --> queue.in++;
        queue.out --> sink.in++;
}
