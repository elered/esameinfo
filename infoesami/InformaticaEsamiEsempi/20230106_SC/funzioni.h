#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct evento {
double p1[4]; // energia-momento particella 1 (E1, p1x, p1y, p1z)
double p2[4]; // energia-momento particella 2 (E2, p2x, p2y, p2z)
bool segnale; // Segnale se 1|true, background se 0|false
double massainv; // Massa invariante
};

/*struct myclass{
    bool operator() (evento i, evento j) {return (i.massainv < j.massainv);}
} myobject;*/

int contatore(string const &filename);

evento *load_data(string const &filename, int &ntot);

void mass(evento *m, int &ntot);

void sort_by_ (evento *m, int &ntot);

double media(evento *m, int &ntot);

double stdev(evento *m, int &ntot);

double max_value(evento *m, int ntot);

double min_value(evento *m, int ntot);

bool myfunction(evento i, evento j);

double CalcolaMedia(const vector<evento> &v);

double CalcolaVarianza(const vector<evento> &v);