#include <iostream>
#include "ArbreBinari.h"

using namespace std;

const int MIDA = 1000;

void preordre_binari(const ArbreBinari & a);

int main() {
    char entrada[MIDA];
    cin.getline(entrada, MIDA);
    ArbreBinari a(entrada);

    cout << "Preordre: ";
    preordre_binari(a);
    cout << endl;
}
