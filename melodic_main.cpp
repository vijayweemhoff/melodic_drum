#include <iostream>

using namespace std;

int numElements=4;
int* lijst= new int[numElements];


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

int x=0;
int velocity;

cout << "" << std::endl;

while(1)
{
  cin >> velocity;
    if(velocity>0)
    {
      cout << lijst[x] << std::endl;
      x++;
        if(x>=numElements)
        x=0;
    }
}

delete [] lijst;
}
