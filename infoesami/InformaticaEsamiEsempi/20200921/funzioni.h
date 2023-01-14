#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

struct particella {

    double p[4];
    // energia-momento (E, px, py, pz)
    int carica;
    // carica elettrica
    double eta;
    // pseudo-rapidita’

};

particella *load_data(string const &filename, int &ntot);

int contatore(string const &filename);

void eta (particella *part, int &ntot);

void sort_by_ (particella *m, int &ntot);

double max_value(particella *m, int ntot);

double min_value(particella *m, int ntot);

double stdev(particella *m, int &ntot);

double media(particella *m, int &ntot);