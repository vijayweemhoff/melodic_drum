#include <iostream>
#include "osc.h"

using namespace std;

int numElements=4;
int* lijst= new int[numElements];

int aantal=0;
int* pitches= new int[aantal];

int velocityOSC;
int pitchOSC;
int showPitch;

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
    if(!msgpath.compare("/kslider_pitch")){
       pitchOSC = argv[0]->i;
       //cout << "Message: " << pitchOSC << fixed << std::endl;
    } // if
    if(!msgpath.compare("/show_pitches")){
       showPitch = argv[0]->i;
       //cout << "Yes show me pitches" << showPitch << fixed << std::endl;
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
      cout << lijst[i] << " ";
}

void outputPitches()
{
  cout << "" << std::endl;
  cout << "dit zit er in pitches array" << std::endl;
  for (int i=0; i<aantal; i++)
      cout << pitches[i] << " ";
  cout << "" << std::endl;

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
    osc.set_callback("/kslider_pitch","i");
    osc.set_callback("/show_pitches","i");

    osc.start();
    cout << "Listening on port " << serverport << endl;
//einde OSC gebeuren

int x=0;
int y=0;
int welkePitch=0;

while(1)
{
  if(pitchOSC>0)
  {
    aantal++;
    cout << "While message: " << pitchOSC << fixed << std::endl;
    pitches[y]=pitchOSC;
    y++;
    pitchOSC=0;
  }

  if(showPitch==1)
  {
    outputPitches();
    showPitch=0;
  }

  //cout << params[0] << std::endl;
    if(velocityOSC>0)
    {
      cout << "" << std::endl;
      cout << lijst[x] << std::endl;
      cout << pitches[welkePitch] << std::endl;

      x++;
      welkePitch++;

        if(x>=numElements)
        x=0;

        if(welkePitch>=aantal)
        welkePitch=0;

      velocityOSC=0;
    }
}

delete [] lijst;
delete [] pitches;
}

/* git:
git add (als er iets bij moet)
git commit (als er wat verandert is)

als het naar github moet:

git push -u origin master

*/
