#include <iostream>
#include <cmath>
#include <sstream> 
#include <fstream>
#include "funzioni.h"
using namespace std;


int main(){

    stringstream sout;
    stringstream ss;         //my printer
    int ntot = 0;
    netpacket *w = load_data("data.dat", ntot);
    sout << "Pacchetti caricati: " << ntot << endl;
    int high = 0;
    int low = 0;
    for(int i = 0; i < ntot; i++){
        if(w[i].db >= 90 ){
            high ++;
        }else{
            low ++;
        }
    }
    sout << "Pacchetti con buona qualità: " << high << "\nPacchetti con bassa qualità: "<< low << endl;
    netpacket *hq = new netpacket[high];
    netpacket *lq = new netpacket[low];
    filtra(w, hq, lq, ntot);
    store_corrupt(lq, low);
    sort_by_timestamp(hq, high);
    sout << "\nPrimi e ultimi 5 pacchetti dopo l'ordinamento:" << endl;
    print_description(hq, high, sout);
    sout << "\nMessaggio finale:\n" << endl;
    print_message1(hq, high, sout);
    store_message(hq, high);
    print_and_save(sout);

    delete [] w;

    return 0;
}