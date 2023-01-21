#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "funzioni.h"

using namespace std;

int main() {

    int ntot = contatore("punti.dat");

    punti *p = load_data("punti.dat", ntot);

    double *f = forza(p, ntot);

    cout << "numero totale di punti: " << ntot << endl;

    for(int i = 0; i<ntot; i++) {

        cout << "Punto [" << i+1 << "]: (" << p[i].x << ", " << p[i].y << "),  omega = " << p[i].w << ", massa = " << p[i].m << endl;

    }

    cout << endl;
    cout << "Array riordinato secondo la forza" << endl;
    cout << endl;

    riordina (f, p, ntot);

    for(int i = 0; i<ntot; i++) {

        cout << "Punto [" << i+1 << "]: (" << p[i].x << ", " << p[i].y << "),  omega = " << p[i].w << ", massa = " << p[i].m << endl;

    }

    cout << endl;

    cout << "Media delle forze: " << media(f, ntot) << endl;

    double count = conta2(p,f,ntot);

    cout << "Numero punti eliminati: " << count << endl;

    punti *elim = filtra(p,f,ntot,count);

    cout << endl;
    cout << "Punti eliminati" << endl;
    cout << endl;

    for(int i = 0; i<count; i++) {

        cout << "Punto [" << i+1 << "]: (" << elim[i].x << ", " << elim[i].y << "),  omega = " << elim[i].w << ", massa = " << elim[i].m << endl;

    }

    return 0;

}