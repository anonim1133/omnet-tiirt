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
        input in;
}
