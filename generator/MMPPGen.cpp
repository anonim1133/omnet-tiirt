#include "MMPPGen.h"

Define_Module(MMPPGen);

MMPPGen::MMPPGen()
{
}

MMPPGen::MMPPGen(int states, vector<double> mmPPLambda)
{
    MMPPGen::states = states;
    MMPPGen::mmPPLambda = mmPPLambda;
}


double MMPPGen::getDelay()
{
	return (double)1;
}

void MMPPGen::initialize(){
	SimpleGen::initialize();

    actualstate = 0;

    mmppStates = par("mmppStates");
	double range = par("mmppLambdaRange");

    generatorMatrix = new double* [mmppStates];

    for(int i=0; i<mmppStates; i++)
    {
        mmPPLambda.push_back(uniform(0,range));
    }

    for( int i = 0; i<mmppStates; i++)
    {
        generatorMatrix[i] = new double [mmppStates];
    }

    //double generatorMatrix[mmppStates][mmppStates];
    calculateMatrix(mmppStates, generatorMatrix);

    EV << "Wybrano rozklad MMPP liczba stanow:" << mmppStates << "\n";
    //wypisanie lambd
    EV<<"lambdy: \n";
    for(unsigned int i=0; i<mmPPLambda.size();i++)
    {
        EV<<mmPPLambda.at(i)<<" ";
    }
    EV<<"\n\n";
    //wypisanie tablicy
    for(int i=0; i<mmppStates-1;i++)
    {
        for(int j=0; j<mmppStates;j++)
        {
            EV<<generatorMatrix[i][j]<<" ";
        }
        EV<<"\n";
     }

    sendMessage();
}

double** MMPPGen::calculateMatrix(int states, double** generatorMatrix)
{
       //wyzerowanie tablicy
       for(int i=0; i<states;i++)
       {
           for(int j=0; j<states;j++)
           {
               generatorMatrix[i][j] = 0;
           }
       }

       //uzupe�nienie macierzy przej�
       for(int i=0; i<states-1;i++)
       {
               vector<double> values;

               /*
                * obliczenie wartoci wiersza
                *
                * obliczenie 2 pr. stanu: pozostanie oraz przejcie
                */
               if(i==0)
               {
                   double number = uniform(0,0.5);
                   generatorMatrix[i][i] = number;
                   generatorMatrix[i][i+1] = 1.0-number;
               }
               else if(i==states-2)
               {
                   double number = uniform(0,0.5);
                   generatorMatrix[i][i+1] = number;
                   generatorMatrix[i][i] = 1.0-number;
               }
               else
               {
                   bool work = true;

                   //wyznaczenie 3 pr. dla stanu
                   while(work)
                   {
                       double sum = 0.0;
                       for(int k=0;k<2;k++)
                       {
                           //int number = rand() % 100 + 1;
                           double number = uniform(0,1);
                           values.push_back(number);
                           sum = sum+(double)number;
                       }
                       if(sum<1.0)
                       {
                           values.push_back(1.0-sum);
                           sort(values.begin(), values.end());
                           work = false;
                       }
                       else
                       {
                           values.clear();
                       }
                   }

                   generatorMatrix[i][i-1] = values.at(1);
                   generatorMatrix[i][i] = values.at(0);
                   generatorMatrix[i][i+1] = values.at(2);

                   values.clear();
               }
       }
       return generatorMatrix;
}


    void MMPPGen::handleMessage(cMessage *msg)
    {
          /*
           * wyznaczanie stanu
           *
           */

          double number = uniform(0,1);

          //sytuacja dla stanu 0
          if(actualstate==0)
          {
              //zmiana stanu
              if(number>generatorMatrix[0][0])
              {
                  EV<<"Zmieniono stan na 1 "<< number <<"\n";
                  actualstate = 1;
              }
              else //pozostanie w tym samym stanie
              {
                  EV<<"Ten sam stan "<< number <<"\n";
              }
          }
          else //pozosta�e sytuacje
          if(actualstate>0 && actualstate<(mmppStates-1))
          {
              vector<double> start;
              vector<double> end;

              start.push_back(0.0);
              end.push_back(generatorMatrix[actualstate][actualstate-1]);
              EV<<"przedzial: "<<start.at(0)<<"-"<<end.at(0)<<"; ";

              start.push_back(generatorMatrix[actualstate][actualstate-1]);
              end.push_back(generatorMatrix[actualstate][actualstate-1]+generatorMatrix[actualstate][actualstate]);
              EV<<"przedzial: "<<start.at(1)<<"-"<<end.at(1)<<"; ";

              start.push_back(generatorMatrix[actualstate][actualstate-1]+generatorMatrix[actualstate][actualstate]);
              end.push_back(1.0);
              EV<<"przedzial: "<<start.at(2)<<"-"<<end.at(2)<<"\n ";

              if(number>start.at(2))
              {
                  actualstate++;
                  EV<<"Zmieniono stan na x"<<actualstate <<" "<<number<<"\n";
              }
              else if(number>start.at(1))
              {
                  EV<<"Ten sam stan"<<actualstate <<" "<<number<<"\n";
              }
              else
              {
                  actualstate--;
                  EV<<"Zmieniono stan na v"<<actualstate <<" "<<number<<"\n";
              }
          }
          else //sytuacja dla stanu n
          if(actualstate==(mmppStates-1))
          {
              //zmiana stanu
              if(number>generatorMatrix[mmppStates-1][mmppStates-2])
              {
                  actualstate--;
                  EV<<"Zmieniono stan na "<< actualstate<<"\n";
              }
              else //pozostanie w tym samym stanie
              {
                  EV<<"Ten sam stan\n";
              }
          }
          delete msg;
          sendMessage();
    }

    void MMPPGen::sendMessage()
    {

        std::stringstream ss;

        simtime_t delay = poisson(mmPPLambda.at(actualstate),0.5);
        ss << "Self "<< delay;

        std::string s = ss.str();
        cMessage *sel = new cMessage(s.c_str());
        cMessage *packet = generateMessage();
        sendDelayed(packet, delay, "out");
        scheduleAt(simTime()+delay, sel);
    }
