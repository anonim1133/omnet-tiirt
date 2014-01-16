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

package lab1;

simple SimpleGen
{
    parameters:
    	@signal[event](type="SimTime");
    	@statistic[delay](title="event delay"; source="event"; record=vector,stats; interpolationmode=none);
    gates:
        output out;
}

simple PoissonGen extends SimpleGen
{
    parameters:
        @class(PoissonGen);
        double lambda = default(1.0);
}

simple ExponentialGen extends SimpleGen
{
    parameters:
        @class(ExponentialGen);
        double mean @unit("s") = default(1s);
}

simple MMPPGen extends SimpleGen
{
    parameters:
    	@class(MMPPGen);
    	@signal[state](type="int");
    	@statistic[state](title="state count"; source="state"; record=vector,stats; interpolationmode=none);
        int states = default(3);
}

simple OnOffGen extends MMPPGen
{
    parameters:
    	@class(OnOffGen);
        states = 2;
}

simple Sink
{
    parameters:
        @class(Sink);
    	@signal[event](type="SimTime");
    	@statistic[delay](title="Delay"; source="event"; record=vector,stats; interpolationmode=none);
    gates:
        input in[];
}

simple AdmissionControl
{
    parameters:
    	@class(AdmissionControl);
		@signal[qsize](type="int");
    	@statistic[qsize](title="Queue size"; source="qsize"; record=vector,stats,histogram; interpolationmode=none);
    	@signal[accepted](type="int");
    	@statistic[accepted](title="Accepted packages"; source="accepted"; record=vector,stats,histogram; interpolationmode=none);
    	@signal[rejected](type="int");
    	@statistic[rejected](title="Rejected Packages"; source="rejected"; record=vector,stats,histogram; interpolationmode=none);
    	double delay = default(1.0);
    gates:
        input in[];
        output out;
}

simple RED extends AdmissionControl
{
    parameters:
		@class(RED);
		int mean = default(1);
		int max_queue_size = default(16);
}

simple wRED extends RED
{
    parameters:
        @class(wRED);
}

simple Blue extends AdmissionControl
{
    parameters:
        @class(Blue);
        int max_queue_size = default(16);
        double freeze_time = default(0.25);
        double step = default(0.05);
}

simple SourceBanlist extends AdmissionControl
{
    @class(SourceBanlist);
}

simple LeakyBucket
{
    parameters:
    	@class(LeakyBucket);
		@signal[qsize](type="int");
    	@statistic[qsize](title="Queue size"; source="qsize"; record=vector,stats,histogram; interpolationmode=none);
    	@signal[accepted](type="int");
    	@statistic[accepted](title="Accepted packages"; source="accepted"; record=vector,stats,histogram; interpolationmode=none);
    	@signal[rejected](type="int");
    	@statistic[rejected](title="Rejected Packages"; source="rejected"; record=vector,stats,histogram; interpolationmode=none);
        int max_queue_size = default(16);
        double interval = default(0.5);
    gates:
        input in;
        output out;
}

simple TokenBucket extends LeakyBucket
{
    parameters:
        @class(TokenBucket);
		int max_tokens_size = default(24);
		int max_ttl = default(4);
}

simple HTokenBucket extends TokenBucket
{
    parameters:
        @class(HTokenBucket);
}

simple FCFS
{
    gates:
        input in;
        output out;
}

simple SJF
{
    gates:
        input in;
        output out;
}

simple RR
{
    gates:
        input in;
        output out;
}

simple PriorityScheduler
{
    gates:
        input in;
        output out;
}