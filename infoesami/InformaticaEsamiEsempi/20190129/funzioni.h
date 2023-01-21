#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

struct sfera{

    float diam;
    char col;
    float exact;
    float atoll;
    float discr;

};

int contatore(string const &filename);

sfera *load_data(string const &filename, int &ntot);

sfera *load_data2(string const &filename, int &ntot);

void sort_by (sfera *m, sfera *f, int ntot, int nf);

void print_data(sfera *m, int ntot, string const &filename);