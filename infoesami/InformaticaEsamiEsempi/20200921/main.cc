#include <iostream>
#include <cmath>
#include "funzioni.h"

using namespace std;

int main() {

    int n = contatore("particelle.dat");

    particella *p = load_data("particelle.dat", n);


    cout << "Numero di cariche: " << n << endl;

    int npos = 0;
    int nneg = 0;
    int nneutr = 0;

        for(int i = 0; i<n; i++) {

        if(p[i].carica > 0) {
            npos ++;
        } else if (p[i].carica < 0) {
            nneg ++;
        } else {
            nneutr ++;
        }
    }

    cout << "Cariche positive: " << npos << endl;
    cout << "Cariche negative: " << nneg << endl;
    cout << "Cariche neutre: " << nneutr << endl;

    cout << "Percentuale cariche positive: " << (npos/double(n))*100 << endl;
    cout << "Percentuale cariche negative: " << (nneg/double(n))*100 << endl;
    cout << "Percentuale cariche neutre: " << (nneutr/double(n))*100 << endl;

    eta (p, n);

    for(int i=0; i<10; i++) {

        cout << "Eta particella [" << i << "]: " << p[i].eta << endl; 

    }

    sort_by_ (p, n);

    for(int i = 0; i<4; i++) {

        cout << p[i].p[0] << endl;
        cout << p[i].p[1] << endl;
        cout << p[i].p[2] << endl;
        cout << p[i].p[3] << endl;
        cout << p[i].carica << endl;
        cout << "eta " << p[i].eta << endl;

    }


    for(int i = n-4; i<n; i++) {

        cout << p[i].p[0] << endl;
        cout << p[i].p[1] << endl;
        cout << p[i].p[2] << endl;
        cout << p[i].p[3] << endl;
        cout << p[i].carica << endl;
        cout << "eta " << p[i].eta << endl;

    }

    cout << "Max: " << max_value(p, n) << endl;
    cout << "Min: " << min_value(p, n) << endl;
    cout << "stdev: " << stdev(p,n) << endl;
    cout << "Media: " << media(p,n) << endl;


    return 0;
}