#include <iostream>
#include <fstream>
#include <string>
#include "Padro.h"
#include <vector>
#include <list>
#include <iomanip>
#include <cmath>

using namespace std;

const int NUM_DISTRICTES = 6;

double redondear(double valor) {
    return round(valor * 100) / 100.0;
}

void mostrarEdatNacionalitat(Padro &padro) {
    cout << "*****************************************" << endl;
    cout << "* 6: Compta edat i naci´o per districte *" << endl;
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

void mostrarEdatMitjana(Padro &padro) {
    cout << "*********************" << endl;
    cout << "* 4: Edats mitjanes *" << endl;
    cout << "*********************" << endl;
    vector<pair<string, double>> edats = padro.resumEdat();
    vector<pair<string, double>>::iterator it;

    for (it = edats.begin(); it != edats.end(); it++) {
        cout << "\t" << left << setw(35) << it->first << left << setw(16) << "Promig Edat:" << setw(8) << right << redondear(it->second) << endl;
    }
}

void mostrarEstudis(Padro &padro) {
    cout << "**************" << endl;
    cout << "* 3: Estudis *" << endl;
    cout << "**************" << endl;

    list<string> estudis = padro.resumEstudis();
    list<string>::reverse_iterator it;

    cout << "Estudis:" << endl;

    estudis.sort();

    for (it = estudis.rbegin(); it != estudis.rend(); it++) {
        cout << " - " << *it << endl;
    }

}

void mostrarNombreHabitants(Padro &padro) {
    cout << "***************************************" << endl;
    cout << "* 2: Nombre d’habitants per districte *" << endl;
    cout << "***************************************" <<endl;
    long total = 0;
    vector<long> numHabitants = padro.obtenirNumHabitantsPerDistricte();

    for (int i = 0; i < NUM_DISTRICTES; i++) {
        cout << "Districte " << i + 1 << "\tHabitants:" << setw(8) << right << numHabitants[i] << endl;
        total += numHabitants[i];

    }

    cout << "TOTAL : " << total << endl;
}

int stringToInt ( string s ) {
    if ( s . length ()==0) return -1;

    for( char c : s ) {
        if (c <'0' || c >'9') return -1;
    }

    return stoi ( s );
}

void lecturaFichero(Padro &padro, bool &ficheroLeido) {
    cout << "*******************" << endl;
    cout << "* 1: Llegir dades *" << endl;
    cout << "*******************" << endl;
    string ruta;
    cin >> ruta;
    ifstream archivo(ruta);
    string linea, palabra;
    string any, districte, codiEstudis, nivelLStudis, dataNaixement, codiNacionalitat, nacionalitat;
    long numLinies = 0;

    if (!archivo.is_open()) {
        cout << "\nEl archivo no se ha podido abrir" << endl;

    }else {
        getline(archivo, linea);
        while(not archivo.eof()) {
            archivo>>any>>districte>>codiEstudis>>nivelLStudis>>dataNaixement>>codiNacionalitat>>nacionalitat;
            padro.afegir(stringToInt(any), stringToInt(districte), stringToInt(codiEstudis), nivelLStudis, stringToInt(dataNaixement), stringToInt(codiNacionalitat), nacionalitat);
            //cout<< "hola" << endl;
            numLinies++;
        }

        ficheroLeido = true;
        archivo.close();
        cout << "Numero de linies: " << numLinies << endl;
    }
}

void escollirOpcio(char opcio, Padro &padro, bool &ficheroLeido) {
        switch(opcio) {
            case '1':
                if (!ficheroLeido) {
                    lecturaFichero(padro, ficheroLeido);

                }else {
                    cout << "Ya se ha leido un fichero" << endl;
                }
                break;

            case '2':
                if (ficheroLeido) {
                    mostrarNombreHabitants(padro);

                }else {
                    cout << "Tienes que leer primero un fichero" << endl;

                }
                break;

            case '3':
                if (ficheroLeido) {
                    mostrarEstudis(padro);

                }else {
                    cout << "Tienes que leer primero un fichero" << endl;

                }

                break;

            case '4':
                if (ficheroLeido) {
                    mostrarEdatMitjana(padro);

                }else {
                    cout << "Tienes que leer primero un fichero" << endl;

                }

                break;

            case '5':
                if (ficheroLeido) {
                    mostrarNacionalitatsExclusives(padro);

                }else {
                    cout << "Tienes que leer primero un fichero" << endl;

                }

                break;

            case '6':
                if (ficheroLeido) {
                    mostrarEdatNacionalitat(padro);

                }else {
                    cout << "Tienes que leer primero un fichero" << endl;

                }

                break;

            case '0':
                //cout << "ADIOS!" << endl;
                break;

            default:
                cout << "Opcion incorrecta!" << endl;
        }
}

//PRE:
//POST:
void mostrarMenu(Padro &padro) {
    char opcio;
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

    }while(opcio != '0');
}

int main()
{
    Padro padro;
    mostrarMenu(padro);
    return 0;
}


