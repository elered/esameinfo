#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "stdlib.h"
#include "funzioni.h"
using namespace std;

int main() {
    int n = contatore("eventi.dat");
    cout << "Le misure lette sono: " << n << endl;

    evento *ev = load_data("eventi.dat", n);

    vector<evento> v;
    vector<evento> b;

    mass(ev, n);

    for(int i=0; i<n; i++) {
        if(ev[i].segnale == 1) { //posso usare anche true
            v.push_back(ev[i]);
        } else {
            b.push_back(ev[i]);
        }
    }

    cout << "Il numero di eventi di tipo segnale è: " << v.size() << endl;
    cout << "Il numero di eventi di tipo background è: " << b.size() << endl;

    cout << "La percentuale del numero di eventi di tipo segnale è: " << (double(v.size())/double(n))*100 << endl;
    cout << "La percentuale del numero di eventi di tipo background è: " << (double(b.size())/double(n))*100 << endl;

    cout << endl;

    for(int i=0; i<10; i++) {
        cout << "Massa invariante dell'evento [" << i+1 << "] = " << ev[i].massainv << endl;
    }

    cout << endl;

    sort_by_(ev, n);

    for(int i=0; i<4; i++) {
        cout << "Evento[" << i+1 << "] =" << endl;
        cout << " - particella 1: (" << ev[i].p1[0] << ", " << ev[i].p1[1] << ", " <<ev[i].p1[2] << ", " <<ev[i].p1[3] << ")" << endl;
        cout << " - particella 2: (" << ev[i].p2[0] << ", " << ev[i].p2[1] << ", " <<ev[i].p2[2] << ", " <<ev[i].p2[3] << ")" << endl;
        cout << " - segnale: (" << ev[i].segnale<< ")" << endl;
        cout << " - massa invariante: (" << ev[i].massainv << ")" << endl;
    }

    cout << endl;

    for(int i=n-4; i<n; i++) {
        cout << "Evento[" << i+1 << "] =" << endl;
        cout << " - particella 1: (" << ev[i].p1[0] << ", " << ev[i].p1[1] << ", " <<ev[i].p1[2] << ", " <<ev[i].p1[3] << ")" << endl;
        cout << " - particella 2: (" << ev[i].p2[0] << ", " << ev[i].p2[1] << ", " <<ev[i].p2[2] << ", " <<ev[i].p2[3] << ")" << endl;
        cout << " - segnale: (" << ev[i].segnale<< ")" << endl;
        cout << " - massa invariante: (" << ev[i].massainv << ")" << endl;
    }

    cout << "La media della massa invariante per tutte le particelle è: " << media(ev, n) << endl;
    cout << "La deviazione standard della massa invariante per tutte le particelle è: " << stdev(ev, n) << endl;
    cout << "Il massimo della massa invariante per tutte le particelle è: " << ev[n-1].massainv << endl;
    cout << "Il minimo della massa invariante per tutte le particelle è: " << ev[0].massainv << endl;

    sort(v.begin(), v.end(), myfunction);
    sort(b.begin(), b.end(), myfunction);


    cout << endl;
    cout << "La media della massa invariante per le particelle di tipo segnale: " << CalcolaMedia(v) << endl;
    cout << "La deviazione standard della massa invariante per le particelle di tipo segnale: " << CalcolaVarianza(v) << endl;
    cout << "Il massimo della massa invariante per le particelle di tipo segnale: " << v[v.size()-1].massainv << endl;
    cout << "Il minimo della massa invariante per le particelle di tipo segnale: " << v[0].massainv << endl;

    cout << endl;
    cout << "La media della massa invariante per le particelle di tipo background: " << CalcolaMedia(b) << endl;
    cout << "La deviazione standard della massa invariante per le particelle di tipo background: " << CalcolaVarianza(b) << endl;
    cout << "Il massimo della massa invariante per le particelle di tipo background: " << b[b.size()-1].massainv << endl;
    cout << "Il minimo della massa invariante per le particelle di tipo background: " << b[0].massainv << endl;

    return 0;
}