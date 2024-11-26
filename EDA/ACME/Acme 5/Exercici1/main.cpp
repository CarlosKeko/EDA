#include <iostream>

using namespace std;


#include "Graf.h"

int main()
{
    const int MIDA = 2000;
    char nom_fitxer[MIDA];

    cout << "Entra el nom del fitxer:" << endl;
    cin.getline(nom_fitxer, MIDA);

    Graf g(nom_fitxer, true);

    if (g.nVertexs() > 0 and g.esDirigit())
        g.ordreAssignatures();
    else
        cout << "no es pot mirar amb aquest graf" << endl;

    return 0;
}
