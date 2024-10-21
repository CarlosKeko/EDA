#include <iostream>
#include <fstream>
#include <string>
#include "Padro.h"
#include <vector>
#include <list>
#include <iomanip>
#include <cmath>
#include "eines.h"

using namespace std;

const int NUM_DISTRICTES = 6;

double redondear(double valor) {
    return round(valor * 100) / 100.0;
}

void mostrarEdatNacionalitat(Padro &padro) {
    cout << "*****************************************" << endl;
    cout << "* 6: Compta edat i naci�o per districte *" << endl;
    cout << "*****************************************" << endl;

    int edat, codiNacionalitat;
    cin >> edat;
    cin >> codiNacionalitat;

    vector<pair<string, long>> habitants = padro.edatNacioPerDistricte(edat, codiNacionalitat);

    cout << "Edat:" << edat << "  Codi Nacionalitat:" << codiNacionalitat << endl;

    for (int i = 0; i < habitants.size(); i++) {
        if (habitants[i].second > 0) {
            cout << habitants[i].first << ": " << habitants[i].second << endl;
        }
    }
}

void mostrarNacionalitatsExclusives(Padro &padro) {
    cout << "*******************************" << endl;
    cout << "* 5: Nacionalitats exclusives *" << endl;
    cout << "*******************************" << endl;
    int districte1, districte2;
    cin >> districte1;
    cin >> districte2;
    vector<list<string>> nacionalitats = padro.diferentsNacionalitats(districte1, districte2);
    list<string>::const_iterator it;

    cout << "Districte " << districte1 << ":" << endl;
    for (it = nacionalitats[0].begin(); it != nacionalitats[0].end(); it++) {
        cout << " - " << *it << endl;
    }

    cout << "Districte " << districte2 << ":" << endl;
    for (it = nacionalitats[1].begin(); it != nacionalitats[1].end(); it++) {
        cout << " - " << *it << endl;
    }

}

//NUEVO
void mostrarEstudisEdat(Padro &padro) {
    cout << "*******************************************" << endl;
    cout << "* 14: Estudis any,districte, edat i nacio *" << endl;
    cout << "*******************************************" << endl;
    int any, districte, edat, codiNacionalitat;
    cin >> any;
    cin >> districte;
    cin >> edat;
    cin >> codiNacionalitat;
    list<string> estudis = padro.estudisEdat(any, districte, edat, codiNacionalitat);

    cout << "Any: " << any << " Districte:" << districte << " Edat:" << edat << " Codi Nacionalitat:" << codiNacionalitat << endl;

    for (string estudi : estudis) {
        cout << estudi << endl;
    }
}

void mostrarEdatMitjana(Padro &padro) {
    cout << "*********************" << endl;
    cout << "* 11: Resum d edats *" << endl;
    cout << "*********************" << endl;
    map<int, vector<pair<string, double>>> edats = padro.resumEdat();
    vector<pair<string, double>>::const_iterator itSegundo;

    for (map<int, vector<pair<string, double>>>::const_iterator it = edats.cbegin(); it != edats.cend(); it++) {
        cout << it->first << ":" << endl;

        for (itSegundo = it->second.begin(); itSegundo != it->second.end(); itSegundo++) {
            cout << "\t" << left << setw(35) << itSegundo->first << left << setw(16) << "Promig Edat:" << setw(8) << right << fixed << setprecision(2) << redondear(itSegundo->second) << endl;
        }

    }

}

void mostrarEstudisDistricte(Padro &padro) {
    cout << "**************************************" << endl;
    cout << "* 07: Nombre d estudis per districte *" << endl;
    cout << "**************************************" << endl;
    int districte;
    cin >> districte;
    cout << "Districte " << districte << endl;
    map<int, int> estudis = padro.nombreEstudisDistricte(districte);

    for (map<int, int>::const_iterator it = estudis.cbegin(); it != estudis.cend(); it++) {
        cout << "Any " << it->first << " Num Estudis:" << it->second << endl;

    }


}

void mostrarEstudis(Padro &padro) {
    cout << "**************************************" << endl;
    cout << "* 06: Resum per estudis *" << endl;
    cout << "*************************" << endl;

    map<int, list<string>> estudis = padro.resumEstudis();

    for (map<int, list<string>>::const_iterator it = estudis.cbegin(); it != estudis.cend(); it++) {
        cout << it->first << " Estudis:";
        list<string> disAux = it->second;

        for (string estudios : disAux) {
            if (estudios != disAux.back()) {
                cout << estudios << " -- ";

            }else {
                cout << estudios;

            }
        }

        cout << endl;

    }

}

void mostrarNombreHabitants(Padro &padro) {
    cout << "*******************************************" << endl;
    cout << "* 04: Obtenir nombre d habitants d un any *" << endl;
    cout << "*******************************************" <<endl;
    int any;
    long total = 0;
    cin >> any;
    vector<long> numHabitants = padro.obtenirNumHabitantsPerDistricte(any);

    for (int i = 0; i < numHabitants.size(); i++) {
        cout << "Districte " << i + 1 << "\tHabitants:" << setw(8) << right << numHabitants[i] << endl;
        total += numHabitants[i];

    }

    cout << "TOTAL : " << total << endl;
}

void comprobarAny(Padro &padro) {
    cout << "********************" << endl;
    cout << "* 02: Existeix any *" << endl;
    cout << "*******************" << endl;
    int any;
    cin >> any;
    cout << "Any:" << any << endl;

    if (padro.existeixAny(any)) {
        cout << "Any existent" << endl;

    }else {
        cout << "Any inexistent" << endl;

    }
}

void lecturaFichero(Padro &padro, bool &ficheroLeido) {
    cout << "*******************" << endl;
    cout << "* 1: Llegir dades *" << endl;
    cout << "*******************" << endl;
    string ruta;
    cin >> ruta;
    cout << "Total lineas: " << padro.llegirDades(ruta) << endl;
    ficheroLeido = true;
}

void escollirOpcio(string opcio, Padro &padro, bool &ficheroLeido) {
    if (opcio == "01") {
        if (!ficheroLeido) {
            lecturaFichero(padro, ficheroLeido);

        } else {
            cout << "Ya se ha leido un fichero" << endl;

        }

    } else if (opcio == "02") {
        if (ficheroLeido) {
            comprobarAny(padro);

        } else {
            cout << "Ya se ha leido un fichero" << endl;

        }

    } else if (opcio == "04") {
        if (ficheroLeido) {
            mostrarNombreHabitants(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    } else if (opcio == "06") {
        if (ficheroLeido) {
            mostrarEstudis(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    } else if (opcio == "07") {
        if (ficheroLeido) {
            mostrarEstudisDistricte(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    } else if (opcio == "11") {
        if (ficheroLeido) {
            mostrarEdatMitjana(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    } else if (opcio == "14") {
        if (ficheroLeido) {
            mostrarEstudisEdat(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    } else {
        if (opcio != "0") {
            cout << "Opcion incorrecta!" << endl;

        }

    }

}

//PRE:
//POST:
void mostrarMenu(Padro &padro) {
    string opcio;
    bool ficheroLeido = false;

    do {
        //cout << "(1) Leer fichero" << endl;
        //cout << "(2) Numero de habitantes por distrito" << endl;
        //cout << "(3) Estudios" << endl;
        //cout << "(4) Edad media" << endl;
        //cout << "(5) Nacionalidades exclusivas" << endl;
        //cout << "(6) Edat y nacionalidad por distrito" << endl;
        //cout << "(0) Exit" << endl;

        //cout << "Escoge opcion (0 - 6): ";
        cin >> opcio;

        escollirOpcio(opcio, padro, ficheroLeido);

    }while(opcio != "0");
}

int main()
{
    Padro padro;
    mostrarMenu(padro);
    return 0;
}


