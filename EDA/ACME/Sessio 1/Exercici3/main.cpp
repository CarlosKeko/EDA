#include <iostream>
#include "estructuraDinamica.h"
using namespace std;


//////// Problema 5
/*
 * Exemples d'execucio
 *
 * entrada:
   3 4 2 5 0
 * sortida:
   3 0 4 2 5
 *
 * entrada:
   9 7 5 1 0
 * sortida:
   9 0 7 5 1
 */
int main()
{
	estructuraDinamica e;
	int primer, anterior, n;


	cin >> primer;
	anterior = primer;
	e.AfegirInici(primer);

	cin >> n;
	while (n != 0) {
		e.AfegirDespres(n, anterior);
		anterior = n;
		cin >> n;
	}
	e.AfegirDespres(n, primer);
	e.Llistar();

	return 0;
}
