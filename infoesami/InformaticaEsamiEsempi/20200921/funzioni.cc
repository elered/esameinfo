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

particella *load_data(string const &filename, int &ntot){          
    
    fstream f;
    f.open(filename, ios::in);
    if (!f.good()){
        throw runtime_error("Problema con il file da leggere");
    }


    f.clear();
    f.seekg(0);
    
    particella *read = new particella[ntot];
    for (int i = 0; i<ntot; i++){
        f >> read[i].p[0]
          >> read[i].p[1]
          >> read[i].p[2]
          >> read[i].p[3]
          >> read[i].carica;

    }

    return read;
}

void eta (particella *part, int &ntot) {

    for(int i = 0; i<ntot; i++) {

        part[i].eta = 0.5*log((part[i].p[0]+part[i].p[3])/(part[i].p[0]-part[i].p[3]));
    }

};

void sort_by_ (particella *m, int &ntot) {

    for (int i = 0; i < ntot - 1; i++){
        for (int j = i + 1; j < ntot; j++){
            if (m[i].eta > m[j].eta){
                particella dep = m[i];
                m[i] = m[j];
                m[j] = dep;
            }
        }   
    }
}

double media(particella *m, int &ntot){
    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i].eta;
    }
    return sum/ntot;
}

double stdev(particella *m, int &ntot){
    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i].eta;
    }
    double media = sum/ntot;
    
    double scarti = 0;
    for(int i = 0; i < ntot; i++){
        scarti += pow((m[i].eta - media),2);
    }
    return sqrt(scarti/ntot);
}

double min_value(particella *m, int ntot){
    double min = m[0].eta;
    for (int i = 0; i < ntot; i++){
        if(m[i].eta < min)
        min = m[i].eta;
    } 
    return min;
}

double max_value(particella *m, int ntot){
    double max = m[0].eta;
    for (int i = 0; i < ntot; i++){
        if(m[i].eta > max)
        max = m[i].eta;
    } 
    return max;
}
