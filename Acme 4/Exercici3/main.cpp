#include <iostream>
#include <memory>
#include "ArbreBinari.h"

using namespace std;

const int MIDA = 1000;

void inordre_binari(const ArbreBinari & a) {
    if (!a.esBuit()) {

        inordre_binari(a.FillEsquerre());
        cout << a.Contingut() << " ";
        inordre_binari(a.FillDret());
    }
}

int main() {
    char entrada[MIDA];
    cin.getline(entrada, MIDA);
    ArbreBinari a(entrada);

    cout << "Inordre: ";
    inordre_binari(a);
    cout << endl;
}
