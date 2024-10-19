#include <iostream>
#include "pilaDinamica.h"

using namespace std;
int main()
{
    pilaDinamica e;
    element n;
    char aux;
    bool posat = false;

    cin >> n;

    while (n != '.') {
        if (n >= 'A' && n <= 'Z') {
            e.Empila(n);


        }else if (n >= 'a' && n <= 'z') {
            e.Desempila();

        }

        if (!e.Buida()) {
            cout << e.Cim() << " ";
            posat = false;

        }else {
            cout << "* ";
            posat = true;

        }

        cin >> n;
    }

    e.Desempila();

    if (!e.Buida()) {
        do {
            aux = e.Cim();
            e.Desempila();

            if (aux != NULL) {
                cout << aux << " ";

            }


            if (e.Buida()) {
                cout << "* ";
            }

        } while (!e.Buida());


    }else {
        if (!posat) {
            cout << "* ";

        }
    }



    return 0;
}
