simple Node {
    parameters:
        @display("i=block/routing");
        string name;
    gates:
        input in;
        output out;
}

simple initNode {
  parameters:
      @display("i=block/routing");
      string name;
  gates:
      // input in;
      output out;
}

simple endNode {
    parameters:
        @display("i=block/routing");
        string name;
    gates:
        input in;
        // output out;
}

network Homework4 {
    @display("bgb=600,400");
    submodules:
        Node0: initNode {
            parameters:
                @display("i=,cyan;p=175,100");
                 name = "Node 0";
        }
        Node1: Node {
            parameters:
                @display("i=,red;p=250,100");
                 name = "Node 1";
        }
        Node2: Node {
            parameters:
                @display("i=,green;p=325,100");
                 name = "Node 2";
        }
        Node3: Node {
            parameters:
                @display("i=,blue;p=400,100");
                 name = "Node 3";
        }
        Node4: Node {
            parameters:
                @display("i=,yellow;p=475,175");
                 name = "Node 4";
        }
        Node5: Node {
            parameters:
                @display("i=,magenta;p=400,250");
                 name = "Node 5";
        }
        Node6: Node {
            parameters:
                @display("i=,orange;p=325,250");
                 name = "Node 6";
        }
        Node7: Node {
            parameters:
                @display("i=,pink;p=250,250");
                 name = "Node 7";
        }
        Node8: Node {
            parameters:
                @display("i=,gold;p=175,250");
                 name = "Node 8";
        }
        Node9: endNode {
            parameters:
                @display("i=,brown;p=100,175");
                 name = "Node 9";
        }
    connections allowunconnected: 
      Node0.out --> Node1.in;
      Node1.out --> Node2.in;
      Node2.out --> Node3.in;
      Node3.out --> Node4.in;
      Node4.out --> Node5.in;
      Node5.out --> Node6.in;
      Node6.out --> Node7.in;
      Node7.out --> Node8.in;
      Node8.out --> Node9.in;

}
