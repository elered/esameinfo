#include <iostream>
#include <cmath>
#include "funzioni.h"

using namespace std;

int main() {

    int n = contatore("sfere.dat");

    sfera *s = load_data("sfere.dat", n);

    int n2 = contatore("tolleranze.dat");

    sfera *s2 = load_data2("tolleranze.dat", n2);

    for(int i = 0; i<n; i++) {

        for(int k = 0; k<n2; k++) {

            if(s2[k].col == s[i].col) {

                s[i].exact = s2[k].exact;
                s[i].atoll = s2[k].atoll;

            }
        }
    }

    for(int i =0; i<n; i++) {

        s[i].discr = s[i].diam - s[i].exact;

    }

    cout << "Numero complessivo: " << n << endl;

    int blu = 0;
    int giallo = 0;
    int rosso = 0;

    for(int i = 0; i<n; i++) {

        if(s[i].col == 'b') {
            blu ++;
        } else if (s[i].col == 'r') {
            rosso ++;
        } else {
            giallo ++;
        }
    }


    cout << "Numero blu: " << blu << endl;
    cout << "Numero rosse: " << rosso << endl;
    cout << "Numero gialle: " << giallo << endl;


    for (int i=0; i<n; i++) {

        cout << "colore " << s[i].col << " Diametro vero: " << s[i].diam << " Diametro nominale " << s[i].exact << " scarto: " << s[i].discr << " atoll " << s[i].atoll << endl;
    }

    sort_by (s, s2, n, n2);

    for(int i = 0; i<n; i++) {

        cout << "sfera [" << i+1 << "]: " << "diamentro: " << s[i].discr << endl;
    }

    int blugiuste = 0;
    int blueliminate = 0;

    for(int i = 0; i<blu; i++) {

        if (fabs(s[i].discr) < fabs(s[i].atoll)) {

            blugiuste ++;
        } else {
            blueliminate ++;
        }
    }

    sfera *blug = new sfera[blugiuste];

    for (int i = 0; i<blu; i++) {

        if(fabs(s[i].discr) < s[i].atoll) {

            for(int k = 0; k<blugiuste; k++) {

            blug[k] = s[k];

            }
        }

    }

    for(int i = 0; i<blugiuste; i++) {

        cout << "colore " << blug[i].col << " Diametro vero: " << blug[i].diam << " Diametro nominale " << blug[i].exact << " scarto: " << blug[i].discr << " atoll " << blug[i].atoll << endl;
    }

    cout << "Blu giuste: " << blugiuste << endl;
    cout << "Blu eliminate: " << blueliminate << endl;

    print_data(s, n, "ris.dat");


    return 0;
}