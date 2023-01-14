#include "funzioni.h"
#include <fstream>
#include <iostream>

using namespace std;

void read_from_file() {

fstream finput;
finput.open("punti.dat", ios::in);
int counter;

punti *p = new punti[counter];

if (!finput.good())
    {
      cerr << "Cannot open myinput.dat" << endl;
    } else {

  for (int i=0; ;i++)
    {
      finput >> p[i].x >> p[i].y >> p[i].m;
      counter++;
      if (finput.eof()) break;
    }
   }

   cout << counter << endl;

finput.close();

}
