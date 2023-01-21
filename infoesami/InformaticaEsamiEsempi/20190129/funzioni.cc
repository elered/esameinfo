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
        ntot ++;
        if(f.eof()) break;
    } 

    return ntot;
    
}

sfera *load_data(string const &filename, int &ntot){          
    
    fstream f;
    f.open(filename, ios::in);
    if (!f.good()){
        throw runtime_error("Problema con il file da leggere");
    }


    f.clear();
    f.seekg(0);
    
    sfera *read = new sfera[ntot];
    for (int i = 0; i<ntot; i++){
        f >> read[i].diam
          >> read[i].col;
    }

    return read;
}


sfera *load_data2(string const &filename, int &ntot){          
    
    fstream f;
    f.open(filename, ios::in);
    if (!f.good()){
        throw runtime_error("Problema con il file da leggere");
    }


    f.clear();
    f.seekg(0);
    
    sfera *read = new sfera[ntot];
    for (int i = 0; i<ntot; i++){
        f >> read[i].col
          >> read[i].exact
          >> read[i].atoll;
    }

    return read;
}

void sort_by (sfera *m, sfera *f, int ntot, int nf) {
    
    for(int i = 0; i<nf; i++) {
        for(int k = 0; k<ntot-1; k++) {
            for(int j=k+1; j<ntot; j++) {
                if(f[i].col == m[k].col) {
                    sfera dep = m[k];
                    m[k] = m[j];
                    m[j] = dep;
                }
            }
        }
    }
}

void print_data(sfera *m, int ntot, string const &filename){

    fstream foutput;

    foutput.open(filename, ios::out);
    
        if (foutput.good()) {
        
            for(int i = 0; i<ntot; i++) {

                foutput << m[i].col << " " << m[i].diam << " " << m[i].exact << " " << m[i].atoll << " " << m[i].discr << endl;
            }
        } else {

            cout << "Errore: file is not good!" << endl;
        }

  foutput.close();  

}