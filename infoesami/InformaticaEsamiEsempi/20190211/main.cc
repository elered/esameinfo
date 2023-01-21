#include <iostream>
#include <cmath>
#include "funzioni.h"

using namespace std;

int main() {

    int ntot = contatore("buche.dat");
    buca *b = load_data("buche.dat", ntot);

    cout << "Numero di cerhi letti: " << ntot << endl;

    for(int i = 0; i<ntot; i++) {

        cout << "Cerchio [" << i << "] = raggio: " << b[i].rad << " xc: " << b[i].xc << " yc: " << b[i].yc << " etichetta: " << b[i].lab << endl;

    }

    int ntot2 = contatore("particelle.dat");
    part *p = load_data2("particelle.dat", ntot2);

    for(int i = 0; i<3; i++) {

        cout << "Particella [" << i << "] = x: " << p[i].x << " y: " << p[i].y << " c: " << p[i].c << " m: " << p[i].m << endl;

    }

    for(int i = ntot2-2; i<=ntot2; i++) {

        cout << "Particella [" << i << "] = x: " << p[i].x << " y: " << p[i].y << " c: " << p[i].c << " m: " << p[i].m << endl;

    }

    conta_part(p, b, ntot, ntot2);

    for(int i = 0; i<ntot; i++) {

        cout << "cerchio [" << i << "] numero particelle interne: " << b[i].n_part << endl;
    }

    for(int i = 0; i<ntot; i++) {

        if(b[i].lab == 'A') {

        for(int k = 0; k<b[i].n_part; k++) {

        cout << " nel cerchio A: Particella [" << k+1 << "] = x: " << b[i].v_part[k].x << " y: " << b[i].v_part[k].y << " c: " << b[i].v_part[k].c << " m: " << b[i].v_part[k].m << endl;
            
        }

        }

    }

    sort_by_(b, ntot);

    for(int i = 0; i<ntot; i++) {

        cout << "Cerchio[" << b[i].lab << "]" << ", Numero = " << b[i].n_part << endl;
    }

    double *m = massa (b,ntot);
    double *media2 = media(b, ntot);

    for(int i = 0; i<ntot; i++) {

        cout << "cerchio [" << b[i].lab << "], somma masse: " << m[i] << ", media cariche: " << media2[i] << endl;

    }

    return 0;

}