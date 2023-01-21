#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include "funzioni.h"

using namespace std;

int contatore(string const &filename) {

    fstream f;
    f.open(filename, ios::in);
    if (!f.good()){
        throw runtime_error("Problema con il file da leggere");
    }

    int ntot = 0;

    string tmp;

    for(;;){

        getline(f,tmp);

        if(f.eof())  {
            
            if(!tmp.empty()) {

              ntot++;
            }
            
            break;

        }

        if(tmp.empty()) {

            continue;
        }

        ntot ++;

    } 

    return ntot;
    
}

punti *load_data(string const &filename, int &ntot){          
    
    fstream f;
    f.open(filename, ios::in);
    if (!f.good()){
        throw runtime_error("Problema con il file da leggere");
    }


    f.clear();
    f.seekg(0);
    
    punti *read = new punti[ntot];
    for (int i = 0; i<ntot; i++){
        f >> read[i].x
          >> read[i].y
          >> read[i].w
          >> read[i].m;

          if(f.eof()) { break; };
    }

    return read;
}

double *forza(punti *p, int &ntot) {

    double *f = new double[ntot];

    double raggio = 0;

    double a = 0;

    for(int i = 0; i<ntot; i++) {

        raggio = sqrt(p[i].x*p[i].x+p[i].y*p[i].y);

        a = p[i].w*p[i].w*raggio;

        f[i] = p[i].m*a;

    }

    return f;

}


void riordina (double *f, punti *p, int &ntot) {

    for (int i = 0; i < ntot - 1; i++){

        for (int j = i + 1; j < ntot; j++){

            if (f[i] > f[j]){
                punti dep = p[i];
                p[i] = p[j];
                p[j] = dep;
            }
        }  

    }
}


double media(double *m, int ntot){
    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i];
    }
    return sum/ntot;
}

double conta2 (punti *p, double *f, int ntot)  {

    int elim = 0;

    for(int i = 0; i < ntot; i++){

        if(f[i] > 1.2*media(f,ntot)){
            
            elim ++;
        }

    }

    return elim;

}


punti *filtra(punti *p, double *f, int ntot, int elim) {

    punti *e = new punti[elim];

    for (int i = 0; i<ntot; i++) {

        if(f[i] > 1.2*media(f,ntot)) {

            for(int k = 0; k<elim; k++) {

            e[k] = p[k];

            }
        }

    }

    return e;
    
}


