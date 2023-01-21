#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

struct part{

    float x; //Ascissa particella
    float y; //Ordinata particella
    int c; //Carica particella 
    float m; //Massa particella

};

struct buca{

    float xc; //Ascissa centro
    float yc; //Ordinata centro
    float rad; //Raggio
    char lab; //Etichetta
    int n_part; //Num. part in cerchio
    part *v_part; //Vettore particelle

};

int contatore(string const &filename);
buca *load_data(string const &filename, int &ntot);
part *load_data2(string const &filename, int &ntot);
void conta_part(part *p, buca *b, int &ntot, int &ntot2);
void sort_by_(buca *m, int ntot);
double *media (buca *b, int &ntot);
double *massa (buca *b, int &ntot);