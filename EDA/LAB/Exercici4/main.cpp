#include <iostream>
#include "EPS.h"
#include "Assignatura.h"
#include <iomanip>

using namespace std;

int redondeaArriba(int a, int b) {
    return (a + b - 1) / b;
}


/**

*/
void mostrarTurnos(EPS &eps) {
   map<string, list<Assignatura>> assignatures = eps.ferTorns();

   for (map<string, list<Assignatura>>::const_iterator it = assignatures.begin(); it != assignatures.end(); it++) {
        cout << "\n*********************************" << endl;
        cout << "* " << it->first << "                   n=" << it->second.size() << "  *" << endl;
        cout << "*-------------------------------*" << endl;

        for ( list<Assignatura>::const_iterator itDos = it->second.begin(); itDos != it->second.end(); itDos++) {
            cout << "* " << setw(10) << left << itDos->getCodi() << " (tipus " << itDos->getTipus() << "), " << setw(5) << right << itDos->getGrau() << "-" << itDos->getCurs() << " *" << endl;

        }
        cout << "*********************************" << endl;

   }

    cout << "Num. torns:\t" << assignatures.size() << endl;
    cout << "Num. dies:\t" << redondeaArriba(assignatures.size(), 2) << endl;
}

/**
    @brief Lee los datos de un archivo csv y los carga en el objeto EPS
    @pre El archivo en la ruta debe existir, accesible y tener un formato valido.
    @post Los datos del archivo se cargan en el objeto.
    @param EPS Referencia al objeto que contiene los datos del padro.
*/
void lecturaFichero(EPS &eps) {
    cout << "*******************" << endl;
    cout << "* 1: Llegir dades *" << endl;
    cout << "*******************" << endl;
    string ruta;
    cin >> ruta;
    pair<int, int> linies = eps.llegirDades(ruta);
    cout << linies.first << " assignatures llegides de " << linies.second << " graus diferents." << endl;
}

int main()
{
    EPS eps;

    lecturaFichero(eps);

    mostrarTurnos(eps);

    return 0;
}
