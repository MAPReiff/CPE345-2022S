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


simple Node3
	{
		parameters:
		    @display("i=block/routing"); // add a default icon
		    int num_msgs = 10;
		gates:
		    input in;
		    output out;
	}

network Classwork3
{
    @display("bgb=342,184");
     submodules:
        node1: Node3 {
     parameters:
    @display("i=,cyan;p=38,69"); // do not change the icon (first arg of i=) just colorize it
 }
     node2: Node3 {
       parameters:
      @display("i=,gold;p=154,69"); // here too
      }
     node3: Node3 {
      parameters:
      @display("i=,red;p=154,143"); // here too
     }
     connections:
        node1.out --> {  delay = 100ms; } --> node2.in;
        node2.out --> {  delay = 100ms; }  --> node3.in;
        node3.out --> {  delay = 100ms; }  --> node1.in;
}

