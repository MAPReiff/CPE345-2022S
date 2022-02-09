simple Node {
  parameters:
    @display("i=block/routing");
    int num_msgs = 10;
    gates:
      input in[];
      output out[];
}

network Homework3 {
  parameters:
    int nodeCount = 10;
    double odds = 0.5;
    @display("bgb=400,200");
    submodules:
      node[nodeCount]: Node {
        @display("p=100,100");
        gates:
          in[nodeCount];
          out[nodeCount];
      }

      connections allowunconnected:
      for i=0..nodeCount-1, for j=0..nodeCount-1 {
        node[i].out[j] --> node[j].in[i] 
          if i!=j && uniform(0,1) < odds;
      }
}