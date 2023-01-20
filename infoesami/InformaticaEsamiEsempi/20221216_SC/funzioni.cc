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

misure *load_data(string const &filename, int &ntot){          
    
    fstream f;
    f.open(filename, ios::in);
    if (!f.good()){
        throw runtime_error("Problema con il file da leggere");
    }


    f.clear();
    f.seekg(0);
    
    misure *read = new misure[ntot];
    for (int i = 0; i<ntot; i++){
        f >> read[i].t
          >> read[i].vx
          >> read[i].vy
          >> read[i].vz
          >> read[i].K;
          read[i].massa = 0;

          if(f.eof()) { break; };
    }

    return read;
}

void sort_by_(misure *m, int ntot){
    for (int i = 0; i < ntot - 1; i++){
        for (int j = i + 1; j < ntot; j++){
            if (m[i].t > m[j].t){
                misure dep = m[i];
                m[i] = m[j];
                m[j] = dep;
            }
        }   
    }
}

double *posizioni(misure &m) {

    double *pos = new double[3];

    pos[0] = m.vx*m.t;
    pos[1] = m.vy*m.t+0.5*m.t*m.t;
    pos[2] = m.t*sqrt(m.vz);

    return pos;

}

void massaa (misure *m, int &ntot) {

    for(int i = 0; i<ntot; i++) {

        m[i].massa = (2*m[i].K)/(m[i].vx*m[i].vx+m[i].vy*m[i].vy+m[i].vz*m[i].vz);
    }

}


double media(misure *m, int ntot){
    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i].massa;
    }
    return sum/ntot;
}

double stdev(misure *m, int ntot){
    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i].massa;
    }
    double media = sum/ntot;
    
    double scarti = 0;
    for(int i = 0; i < ntot; i++){
        scarti += pow((m[i].massa - media),2);
    }
    return sqrt(scarti/ntot);
}

misure *v_copy(misure *m, int &ntot) {

    misure *v = new misure[ntot];

    for(int i = 0; i<ntot; i++) {

        v[i] = m[i];
    }

    return v;
}

void print_array(const string &filename, misure *m, misure *v, misure *v2, int &ntot) {

    fstream foutput; 

    foutput.open("risultato.dat", ios::out); 

    if (foutput.good()) 
    {
      foutput << "Numero di dati: " << ntot << endl;

      foutput << endl;

      for(int i = 0; i<ntot; i++) {

        foutput << "Oggetto [" << i+1 << "]: tempo = "  << v[i].t << " vx = " << v[i].vx << " vy = " << v[i].vz << " vz = " << " K = " << v[i].K << " massa = " << v[i].massa << endl; 

        }

      foutput << endl;

      foutput << "Array riordinato" << endl;

      foutput << endl;

      for(int i = 0; i<ntot; i++) {

        foutput << "Oggetto [" << i+1 << "]: tempo = "  << v2[i].t << " vx = " << v2[i].vx << " vy = " << v2[i].vz << " vz = " << " K = " << v2[i].K << " massa = " << v2[i].massa << endl; 

    }   

      foutput << endl;

      for(int i = 0; i<ntot; i++) {

        double *pos =  posizioni(m[i]);

        if(m[i].t == 5 || m[i].t == 10 || m[i].t == 15) 

        foutput << "tempo = " << m[i].t << " posizione x = " << pos[0] << " posizione y = " << pos[1] << " posizione z = " << pos[2] << endl;
    }

    foutput << endl;

    for(int i = 0; i<ntot; i++) {

        foutput << "Oggetto [" << i+1 << "]: tempo = "  << m[i].t << " vx = " << m[i].vx << " vy = " << m[i].vz << " vz = " << " K = " << m[i].K << " massa = " << m[i].massa << endl; 

    }

    foutput << endl;

    foutput << "media delle masse = " << media(m, ntot) << endl;
    foutput << "deviazione standard delle masse = " << stdev(m, ntot) << endl;

    }
    else
    cout << "Errore: file is not good!" << endl;

    foutput.close(); 
}