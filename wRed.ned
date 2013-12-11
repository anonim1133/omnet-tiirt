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
import ned.DelayChannel;


//
// TODO documentation
//
network wRedNetwork
{
    @display("bgb=606,504");
    submodules:
        exponentialGen: ExponentialGen {
            @display("p=31,29");
        }
        mmppGen: MMPPGen {
            @display("p=31,107");
        }
        onOffGen: OnOffGen {
            @display("p=31,174");
        }
        poissonGen: PoissonGen {
            @display("p=31,234");
        }
        sink: Sink {
            @display("p=529,146");
        }
        wred: wRED {
            @display("p=292,146");
        }
        poissonGen1: PoissonGen {
            @display("p=30,287");
        }
        poissonGen2: PoissonGen {
            @display("p=30,342");
        }
        poissonGen3: PoissonGen {
            @display("p=31,397");
        }
        poissonGen4: PoissonGen {
            @display("p=30,458");
        }
    connections:
        wred.out --> sink.in++;
        exponentialGen.out --> wred.in++;
        mmppGen.out --> wred.in++;
        onOffGen.out --> wred.in++;
        poissonGen.out --> wred.in++;
        poissonGen1.out --> wred.in++;
        poissonGen2.out --> wred.in++;
        poissonGen3.out --> wred.in++;
        poissonGen4.out --> wred.in++;
}

