network MMPPNetwork
{
    @display("bgb=276,124");
    submodules:
        sink: Sink {
            @display("p=223,56");
        }
        gen: MMPPGen {
            @display("p=43,56");
        }
    connections:
        gen.out --> {  delay = 100ms; } --> sink.in;
}
