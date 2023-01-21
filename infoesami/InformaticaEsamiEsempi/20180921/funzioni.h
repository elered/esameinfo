#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

struct punti {

    float x;
    float y; 
    float w;
    float m;

};

int contatore(string const &filename) ;
punti *load_data(string const &filename, int &ntot) ;
double *forza(punti *p, int &ntot) ;
void riordina (double *f, punti *p, int &ntot) ;
double media(double *m, int ntot) ;
punti *filtra(punti *p, double *f, int ntot, int elim);
double conta2 (punti *p, double *f, int ntot) ;
