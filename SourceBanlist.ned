//
// This program is free software: you can sbistribute it and/or modify
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
network SourceBanlistNetwork
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
        sb: SourceBanlist {
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
        sb.out --> sink.in++;
        exponentialGen.out --> sb.in++;
        mmppGen.out --> sb.in++;
        onOffGen.out --> sb.in++;
        poissonGen.out --> sb.in++;
        poissonGen1.out --> sb.in++;
        poissonGen2.out --> sb.in++;
        poissonGen3.out --> sb.in++;
        poissonGen4.out --> sb.in++;
}

