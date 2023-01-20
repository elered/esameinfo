#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
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
        
        if(f.eof()) {
            if(!tmp.empty()) {
                ntot++;
            }
            break;
        }

        if(tmp.empty())
            continue;
        
        ntot ++;
    
    } 
    return ntot;   
}

evento *load_data(string const &filename, int &ntot){          
    
    fstream f;
    f.open(filename, ios::in);
    if (!f.good()){
        throw runtime_error("Problema con il file da leggere");
    }


    f.clear();
    f.seekg(0);
    
    evento *read = new evento[ntot];
    for (int i = 0; i<ntot; i++){
        f >> read[i].p1[0]
          >> read[i].p1[1]
          >> read[i].p1[2]
          >> read[i].p1[3]
          >> read[i].p2[0]
          >> read[i].p2[1]
          >> read[i].p2[2]
          >> read[i].p2[3]
          >> read[i].segnale;

        if(f.eof()) {
            break;
        }
    }

    return read;

}

void mass(evento *m, int &n) {
    for(int i=0; i<n; i++) {
        m[i].massainv = sqrt(pow(m[i].p1[0]+(m[i].p2[0]), 2) - 
            (
                pow(m[i].p1[1]+(m[i].p2[1]), 2) +
                pow(m[i].p1[2]+(m[i].p2[2]), 2) + 
                pow(m[i].p1[3]+(m[i].p2[3]), 2)
            )
        );
    }
}

void sort_by_ (evento *m, int &ntot) {

    for (int i = 0; i < ntot - 1; i++){
        for (int j = i + 1; j < ntot; j++){
            if (m[i].massainv > m[j].massainv){
                evento dep = m[i];
                m[i] = m[j];
                m[j] = dep;
            }
        }   
    }
}

double media(evento *m, int &ntot) {
    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i].massainv;
    }
    double media = sum/ntot;

    return media;
}

double stdev(evento *m, int &ntot){
    double med = media(m, ntot);   
    double scarti = 0;

    for(int i = 0; i < ntot; i++){
        scarti += pow((m[i].massainv - med),2)/ntot;
    }

    return sqrt(scarti);
}

double min_value(evento *m, int ntot){
    double min = m[0].massainv;
    for (int i = 0; i < ntot; i++){
        if(m[i].massainv < min)
        min = m[i].massainv;
    } 
    return min;
}

double max_value(evento *m, int ntot){
    double max = m[0].massainv;
    for (int i = 0; i < ntot; i++){
        if(m[i].massainv > max)
        max = m[i].massainv;
    } 
    return max;
}

bool myfunction(evento i, evento j) {
    return (i.massainv < j.massainv);
}

double CalcolaMedia(const vector<evento> &v) {
  double accumulo = 0;

  if (v.size() == 0) {
    return accumulo;
  } else {
    for (int k = 0; k < v.size(); k++) {
      accumulo += v[k].massainv;
    }
  }
  return accumulo / double(v.size());
};

double CalcolaVarianza(const vector<evento> &v) {

  double sommascarti = 0;
  double varianza;

  if (v.size() == 0)
    return sommascarti;
  for (int i = 0; i < v.size(); i++) {
    sommascarti += pow(v[i].massainv - CalcolaMedia(v), 2);
  }
  varianza = sommascarti / (v.size() - 1);

  return sqrt(varianza);
};