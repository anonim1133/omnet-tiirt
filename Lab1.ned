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
    gates:
        input in[];
}

simple AdmissionControl
{
    @class(AdmissionControl);
	@signal[qsize](type="int");
    @statistic[qsize](title="Queue size"; source="qsize"; record=vector,stats,histogram; interpolationmode=none);
    @signal[accepted](type="int");
    @statistic[accepted](title="Accepted packages"; source="accepted"; record=vector,stats,histogram; interpolationmode=none);
    @signal[rejected](type="int");
    @statistic[rejected](title="Rejected Packages"; source="rejected"; record=vector,stats,histogram; interpolationmode=none);
    gates:
        input in[];
        output out;
}

simple RED
{
	@class(RED);
    @signal[queue_size](type="int");
    @statistic[queue_size](title="Queue size"; source="queue_size"; record=vector,stats,histogram; interpolationmode=none);
    @signal[accpeted](type="int");
    @statistic[accpeted](title="Accepted packages"; source="accepted"; record=vector,stats,histogram; interpolationmode=none);
    @signal[rejected](type="int");
    @statistic[rejected](title="Rejected Packages"; source="rejected"; record=vector,stats,histogram; interpolationmode=none);
    gates:
        input in[];
        output out;
}

simple wRED
{
    @class(wRED);
    @signal[queue_size](type="int");
    @statistic[queue_size](title="Queue size"; source="queue_size"; record=vector,stats,histogram; interpolationmode=none);
    @signal[accpeted](type="int");
    @statistic[accpeted](title="Accepted packages"; source="accepted"; record=vector,stats,histogram; interpolationmode=none);
    @signal[rejected](type="int");
    @statistic[rejected](title="Rejected Packages"; source="rejected"; record=vector,stats,histogram; interpolationmode=none);
    gates:
        input in[];
        output out;
}

simple Blue
{
    @class(Blue);
	@signal[queue_size](type="int");
    @statistic[queue_size](title="Queue size"; source="queue_size"; record=vector,stats,histogram; interpolationmode=none);
    @signal[accpeted](type="int");
    @statistic[accpeted](title="Accepted packages"; source="accepted"; record=vector,stats,histogram; interpolationmode=none);
    @signal[rejected](type="int");
    @statistic[rejected](title="Rejected Packages"; source="rejected"; record=vector,stats,histogram; interpolationmode=none);
    gates:
        input in[];
        output out;
}

simple SourceBanlist
{
    @class(SourceBanlist);
    @signal[queue_size](type="int");
    @statistic[queue_size](title="Queue size"; source="queue_size"; record=vector,stats,histogram; interpolationmode=none);
    @signal[accpeted](type="int");
    @statistic[accpeted](title="Accepted packages"; source="accepted"; record=vector,stats,histogram; interpolationmode=none);
    @signal[rejected](type="int");
    @statistic[rejected](title="Rejected Packages"; source="rejected"; record=vector,stats,histogram; interpolationmode=none);
    gates:
        input in[];
        output out;
}

simple LeakyBucket
{
	@class(LeakyBucket);
    @signal[queue_size](type="int");
    @statistic[queue_size](title="Queue size"; source="queue_size"; record=vector,stats,histogram; interpolationmode=none);
    
    @signal[queued](type="int");
    @statistic[queued](title="Queued"; source="accepted"; record=vector,stats,histogram; interpolationmode=none);
    
    @signal[rejected](type="int");
    @statistic[rejected](title="Rejected Packages"; source="rejected"; record=vector,stats,histogram; interpolationmode=none);
    
    @signal[sent](type="int");
    @statistic[sent](title="Sent Packages"; source="rejected"; record=vector,stats,histogram; interpolationmode=none);
    gates:
        input in;
        output out;
}

simple TokenBucket
{
    gates:
        input in;
        output out;
}

simple HTokenBucket
{
    gates:
        input in;
        output out;
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