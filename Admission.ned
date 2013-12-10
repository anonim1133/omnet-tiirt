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
//
// TODO documentation
//
network Admission
{
    @display("bgb=606,385");
    submodules:
        exponentialGen: ExponentialGen {
            @display("p=62,92");
        }
        mmppGen: MMPPGen {
            @display("p=53,169");
        }
        onOffGen: OnOffGen {
            @display("p=62,258");
        }
        poissonGen: PoissonGen {
            @display("p=47,339");
        }
        sink: Sink {
            @display("p=448,202");
        }
	connections:
        exponentialGen.out --> sink.in++;
        mmppGen.out --> sink.in++;
        onOffGen.out --> sink.in++;
        poissonGen.out --> sink.in++;
}

