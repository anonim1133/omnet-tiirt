simple PoissonGen
{
    parameters:
        double lambda = default(1.0);
    gates:
        output out;
}

simple ExponentialGen
{
    parameters:
        double mean @unit("s") = default(1s);
    gates:
        output out;
}

simple OnOffGen
{
    parameters:
        double mean @unit("s") = default(1s);
    gates:
        output out;
}

simple MMPPGen
{
    parameters:
		int mmppStates = default(6);
		double mmppLambdaRange = default(3.0);
    gates:
        output out;
}

simple Sink
{
    gates:
        input in;
}
