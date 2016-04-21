#include <iostream>
#include "osc.h"

using namespace std;

int numElements=4;
int* lijst= new int[numElements];

int velocityOSC;

// subclass OSC into a local class so we can provide our own callback
class localOSC : public OSC
{
  int realcallback(const char *path,const char *types,lo_arg **argv,int argc)
  {
  string msgpath=path;

    //cout << "path: " << msgpath << endl;
    if(!msgpath.compare("/velocity")){
      velocityOSC = argv[0]->i;
      //cout << "Message: " << velocityOSC << fixed << std::endl;
    } // if

    return 0;
  } // realcallback()
};

void inputLijst()
{
  for (int i=0; i<numElements; i++)
      cin >> lijst[i];
}
void outputLijst()
{
  for (int i=0; i<numElements; i++)
      cout << lijst[i] << std::endl;
}

int main()
{
cout << "Hoe lang wil je je lijst?" << std::endl;
cin >> numElements;
cout << "stop je getallen er maar in hoor." << std::endl;

inputLijst();
cout << "processing......" << std::endl;
outputLijst();



cout << "" << std::endl;

//OSC gebeuren
  localOSC osc;
  string serverport="6666";

    osc.init(serverport);
    osc.set_callback("/velocity","i");

    osc.start();
    cout << "Listening on port " << serverport << endl;
//einde OSC gebeuren

int x=0;

while(1)
{
  //cout << params[0] << std::endl;
    if(velocityOSC>0)
    {
      cout << "" << std::endl;
      cout << lijst[x] << std::endl;

      x++;

        if(x>=numElements)
        x=0;
        
      velocityOSC=0;
    }
}

delete [] lijst;
}
