simple Source {
  parameters:
    @display("i=block/source");
  gates:
    input in;
    output out;
}

simple Destination {
  parameters:
    @display("i=block/sink");
    double prob;    // = default(0.1);
  gates:
    input in;
    output out;
}

network ARQ1 {
  @display("bgb=179,108");
  submodules:
    source: Source {
      @display("p=40,42");
    }
    destination: Destination {
      @display("p=124,42");
    }
  connections:
    source.out --> destination.in;
    destination.out --> source.in;
}
