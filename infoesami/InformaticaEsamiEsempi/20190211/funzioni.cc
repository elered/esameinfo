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

buca *load_data(string const &filename, int &ntot){          
    
    fstream f;
    f.open(filename, ios::in);
    if (!f.good()){
        throw runtime_error("Problema con il file da leggere");
    }


    f.clear();
    f.seekg(0);
    
    buca *read = new buca[ntot];
    for (int i = 0; i<ntot; i++){
        f >> read[i].xc
          >> read[i].yc
          >> read[i].rad
          >> read[i].lab;

    }

    return read;
}

part *load_data2(string const &filename, int &ntot){          
    
    fstream f;
    f.open(filename, ios::in);
    if (!f.good()){
        throw runtime_error("Problema con il file da leggere");
    }


    f.clear();
    f.seekg(0);
    
    part *read = new part[ntot];
    for (int i = 0; i<ntot; i++){
        f >> read[i].x
          >> read[i].y
          >> read[i].c
          >> read[i].m;

    }

    return read;
}

void conta_part(part *p, buca *b, int &ntot, int &ntot2) {

    for(int i=0; i<ntot; i++) {

        int dentro = 0;

        int j = 0; 

        for(int k=0; k<ntot2; k++) {

            if(sqrt(pow(b[i].xc-p[k].x, 2)+(pow(b[i].yc-p[k].y, 2)))<b[i].rad) {
                
                dentro ++;
            }
        }

        b[i].n_part = dentro;

        b[i].v_part = new part[b[i].n_part];

        for(int k=0; k<ntot2; k++) {

            if(sqrt(pow(b[i].xc-p[k].x, 2)+(pow(b[i].yc-p[k].y, 2)))<b[i].rad){
                
                b[i].v_part[j] = p[k];

                j++;

            }       

        }

    }

}

void sort_by_(buca *m, int ntot){
    for (int i = 0; i < ntot - 1; i++){
        for (int j = i + 1; j < ntot; j++){
            if (m[i].n_part < m[j].n_part){
                buca dep = m[i];
                m[i] = m[j];
                m[j] = dep;
            }
        }   
    }
}

double *massa (buca *b, int &ntot) {

    double *sum = new double[ntot];

    for(int i = 0; i<ntot; i++) {

        for(int j = 0; j<b[i].n_part; j++) {

        sum[i] += b[i].v_part[j].m;

        }
    }

    return sum;

}

double *media (buca *b, int &ntot) {

    double *sum = new double[ntot];

    for(int i = 0; i<ntot; i++) {

        for(int j = 0; j<b[i].n_part; j++) {

        sum[i] += b[i].v_part[j].c/b[i].n_part;

        }
    }

    return sum;

}





