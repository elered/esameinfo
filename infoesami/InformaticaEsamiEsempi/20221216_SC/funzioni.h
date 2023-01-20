#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

struct misure {
    
int t; // instante della misura
double vx; // coordinata vx dell'oggetto
double vy; // coordinata vy dell'oggetto
double vz; // coordinata vz dell'oggetto
double K; // energia cinetica totale dell'oggetto
double massa; // massa dell'oggetto in moto

};

int contatore(string const &filename);
misure *load_data(string const &filename, int &ntot);
void sort_by_(misure *m, int ntot);
double *posizioni(misure &m);
void massaa (misure *m, int &ntot);
double media(misure *m, int ntot);
double stdev(misure *m, int ntot);
misure *v_copy(misure *m, int &ntot);
void print_array(const string &filename, misure *m, misure *v, misure *v2, int &ntot);