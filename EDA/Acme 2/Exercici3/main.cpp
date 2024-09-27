#include <iostream>
#include "estructuraDinamica.h"
using namespace std;

/////// Programa 11
/*
 * Exemples d'execucio
 *
 * entrada:
 3 4 2 0
 * sortida:
 2 4 3
 3 4 2
 *
 * entrada:
 9 7 5 5 0
 * sortida:
 5 5 7 9
 9 7 5 5
 */
int main () {
	estructuraDinamica e;
	int n;

	cin >> n;
	while (n != 0) {
		e.AfegirInici(n);
		cin >> n;
	}
	e.Llistar();

	n = e.TreureFinal();
	while (n != 0) {
		cout << n << " ";
		n = e.TreureFinal();
	}
	cout << endl;

	return 0;
}
