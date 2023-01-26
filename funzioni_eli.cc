#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include "funzioni.h"
using namespace std;

#define N 10000

... *load_data(string const &filename, int &ntot){           //... tipo di variabile, queste funzioni sono pensate per delle struct 
    
    fstream f;
    f.open(filename, ios::in);
    if (!f.good()){
        throw runtime_error("Problema con il file da leggere");
    }
    
    //inserire dati nell'array
    ... *read = new ...[N];
    for (;;){
        f >> read[ntot]. 
          >> read[ntot]. 
          >> read[ntot]. 
          >> read[ntot]. 
          >> read[ntot].;
          read[ntot]. = 0;
        if (f.eof())
            break;
        ntot++;
    }

    // ridimensiona array
    ... *out = new ...[ntot];
    for (int i = 0; i < ntot; i++){
        out[i] = read[i];
    }
    
    delete[] read;

    return out;
}

void print_data(... *m, int ntot, stringstream &sout){
    for (int i = 0; i < ntot; i++){
        
        sout << m[i]. << " "
             << m[i]. << " "
             << m[i]. << " "
             << m[i]. << " "
             << m[i]. << " "
             << m[i]. << endl;
        
    }
}


void print_and_save(stringstream &ss){
    cout << ss.str();
    fstream outfile("risultati.dat", ios::out);
    outfile << ss.str();
    ss.str("");
    ss.clear();
}

void sort_by_(... *m, int ntot){
    for (int i = 0; i < ntot - 1; i++){
        for (int j = i + 1; j < ntot; j++){
            if (m[i]. > m[j].){
                ... dep = m[i];
                m[i] = m[j];
                m[j] = dep;
            }
        }   
    }
}


void filtra(... *m, ... *a, ... *b, int ntot){
    
    int conta1 = 0;
    int conta0 = 0;
    for(int i = 0; i < ntot; i++){
        if(m[i]. > ){
            a[conta1] = m[i];
            conta1 ++;
        }else{
            b[conta0] = m[i];
            conta0 ++;

        }
    
    }
}

double media(.... *m, int ntot){
    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i].;
    }
    return sum/ntot;
}

double stdev(... *m, int ntot){
    double sum = 0;
    for (int i = 0; i < ntot; i++){
        sum += m[i].;
    }
    double media = sum/ntot;
    
    double scarti = 0;
    for(int i = 0; i < ntot; i++){
        scarti += pow((m[i]. - media),2);
    }
    return sqrt(scarti/ntot);
}

double min_value(... *m, int ntot){
    double min = m[0].;
    for (int i = 0; i < ntot; i++){
        if(m[i]. < min)
        min = m[i].;
    } 
    return min;
}

void store_(... *m, int ntot){
    fstream out;
    out.open(".dat", ios::out);
    if (!out.good()){
        throw runtime_error("Problema con il file da creare");
    }
        
    for (int i = 0; i < ntot; i++){
        out << m[i]. << endl;
    }
    out.close();
}



fstream f;
    f.open("eventi.dat", ios::in);
    if (!f.good()){
        cout << "problema con il file eventi.dat"<< endl;
        return -1;
    }
    
    int ntot = 0;
    string tmp;
    for(;;){
        getline(f,tmp);
        if(f.eof()) break;
        ntot ++;
    } 
    sout << "" << endl;
    sout << " " << ntot << endl;    
    f.clear();
    f.seekg(0);
    
     *w = new [ntot]; 

     for(int i = 0; i < count; i++){
    
        f >> 
            
//NOSTRE FUNZIONI BELLE            
            
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

netpacket *load_data(string const &filename, int &ntot){          
    
    fstream f;
    f.open(filename, ios::in);
    if (!f.good()){
        throw runtime_error("Problema con il file da leggere");
    }


    f.clear();
    f.seekg(0);
    
    netpacket *read = new netpacket[ntot];
    for (int i = 0; i<ntot; i++){
        f >> read[i].time
          >> read[i].db
          >> read[i].data;

          if(f.eof()) { break; };
    }

    return read;
}
