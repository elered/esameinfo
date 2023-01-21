#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include "funzioni.h"
using namespace std;

#define N 10000

netpacket *load_data(string const &filename, int &ntot){
    
    fstream f;
    f.open(filename, ios::in);
    if (!f.good()){
        throw runtime_error("Problema con il file da leggere");
    }
    
    //inserire dati nell'array
    netpacket *read = new netpacket[N];
    for (;;){
        f >> read[ntot].time 
          >> read[ntot].db 
          >> read[ntot].data;
        if (f.eof())
            break;
        ntot++;
    }

    // ridimensiona array
    netpacket *out = new netpacket[ntot];
    for (int i = 0; i < ntot; i++){
        out[i] = read[i];
    }
    
    delete[] read;

    return out;
}

void print_and_save(stringstream &ss){
    cout << ss.str();
    fstream outfile("risultati.dat", ios::out);
    outfile << ss.str();
    ss.str("");
    ss.clear();
}

void filtra(netpacket *m, netpacket *a, netpacket *b, int ntot){
    
    int high = 0;
    int low = 0;
    for(int i = 0; i < ntot; i++){
        if(m[i].db >= 90 ){
            a[high] = m[i];
            high ++;
        }else{
            b[low] = m[i];
            low ++;

        }
    
    }
}

void store_corrupt(netpacket *m, int ntot){
    fstream out;
    out.open("corrotti.out", ios::out);
    if (!out.good()){
        throw runtime_error("Problema con il file da creare");
    }
        
    for (int i = 0; i < ntot; i++){
        out << m[i].time << "\t" << m[i].db << "\t" << m[i].data << endl;
    }
    out.close();
}

void sort_by_timestamp(netpacket *m, int ntot){
    for (int i = 0; i < ntot - 1; i++){
        for (int j = i + 1; j < ntot; j++){
            if (m[i].time > m[j].time){
                netpacket dep = m[i];
                m[i] = m[j];
                m[j] = dep;
            }
        }   
    }
}
/*void print_data(netpacket *m, int ntot, stringstream &sout){
    for (int i = 0; i < ntot; i++){
        
        sout << m[i].time << " "
             << m[i].db << " "
             << m[i].data << endl;
        
    }
}*/

void print_description(netpacket *m, int ntot, stringstream &sout){
    for (int i = 0; i < ntot; i++){
        if(i < 5 || i > ntot -6){
            sout  << "Time: "
                    << m[i].time << "\tquality:  "
                    << m[i].db << "\tchar:  "
                    << m[i].data << endl; 
        }
    }
}

void print_message1(netpacket *m, int ntot, stringstream &sout){
    for (int i = 0; i < ntot; i++){
        
        if(m[i].data == '?'){ 
            sout << "\n";
        }else if(m[i].data == '#'){
            sout << " ";
        }else{
            sout << m[i].data; 
        }
        
    }
}

void store_message(netpacket *m, int ntot){
    fstream out;
    out.open("messaggio.out", ios::out);
    if (!out.good()){
        throw runtime_error("Problema con il file da creare");
    }
        
    for (int i = 0; i < ntot; i++){
        
        if(m[i].data == '?'){ 
            out << "\n";
        }else if(m[i].data == '#'){
            out << " ";
        }else{
            out << m[i].data; 
        }
        
    }
    out.close();
}