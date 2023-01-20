#include <iostream>
#include <cmath>
#include "funzioni.h"

using namespace std;

int main() {

    int n = contatore("data.dat");

    misure *m = load_data("data.dat", n);

    cout << "Numero di dati: " << n << endl;

    for(int i = 0; i<n; i++) {

        cout << "Oggetto [" << i+1 << "]: tempo = "  << m[i].t << " vx = " << m[i].vx << " vy = " << m[i].vz << " vz = " << " K = " << m[i].K << " massa = " << m[i].massa << endl; 

    }

    misure *v = v_copy(m,n); 

    sort_by_(m, n);

    cout << "Array riordinato in base al tempo in ordine crescente" << endl;

    for(int i = 0; i<n; i++) {

        cout << "Oggetto [" << i+1 << "]: tempo = "  << m[i].t << " vx = " << m[i].vx << " vy = " << m[i].vz << " vz = " << " K = " << m[i].K << " massa = " << m[i].massa << endl; 

    }

    for(int i = 0; i<n; i++) {

        double *pos =  posizioni(m[i]);

        if(m[i].t == 5 || m[i].t == 10 || m[i].t == 15) 

        cout << "tempo = " << m[i].t << " posizione x = " << pos[0] << " posizione y = " << pos[1] << " posizione z = " << pos[2] << endl;


    }


    misure *v2 = v_copy(m,n); 

    massaa (m, n);


    for(int i = 0; i<n; i++) {

        cout << "Oggetto [" << i+1 << "]: tempo = "  << m[i].t << " vx = " << m[i].vx << " vy = " << m[i].vz << " vz = " << " K = " << m[i].K << " massa = " << m[i].massa << endl; 

    }

    cout << "media delle masse = " << media(m, n) << endl;
    cout << "deviazione standard delle masse = " << stdev(m, n) << endl;
    print_array("risultati.dat", m, v, v2, n);

    return 0;

}