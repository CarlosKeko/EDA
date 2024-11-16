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

void mostrar(Padro &padro) {
    cout << "****************************" << endl;
    cout << "* 13: Moviments dels vells *" << endl;
    cout << "****************************" << endl;

    int anyInicial, anyFinal;

    cin >> anyInicial;
    cin >> anyFinal;

    pair<string, long> resultat = padro.mesJoves(anyInicial, anyFinal);

    cout << resultat.first << "    " << resultat.second << endl;



}

void mostrarEdatVells(Padro &padro) {
    cout << "****************************" << endl;
    cout << "* 12: Moviments dels vells *" << endl;
    cout << "****************************" << endl;

    map<int, string> resultat = padro.movimentVells();

    for (map<int, string>::const_iterator it = resultat.begin(); it != resultat.end(); it++) {
        cout << it->first << "    " << it->second << endl;

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

void mostrarMovimentsComunitat(Padro &padro) {
    cout << "*********************************" << endl;
    cout << "* 10: Moviments d'una comunitat *" << endl;
    cout << "*********************************" << endl;
    int nacionalitat = 0;
    cin >> nacionalitat;

    map<int,string> moviments = padro.movimentsComunitat(nacionalitat);

    cout << "Codi Nacionalitat:" << nacionalitat << endl;
    for(map<int,string>::const_iterator it = moviments.begin(); it != moviments.end(); it++) {
        cout << it->first << " " << setw(29) << right << it->second << endl;

    }
}

void mostrarNacionalitats(Padro &padro) {
    cout << "******************************" << endl;
    cout << "* 09: Resum de nacionalitats *" << endl;
    cout << "******************************" << endl;

    map<int, vector<pair<string, long>>> nacionalitats = padro.resumNacionalitats();

    for(map<int, vector<pair<string, long>>>::const_iterator it = nacionalitats.begin(); it != nacionalitats.end(); it++) {
        cout << it->first << endl;

        for (pair<string, long> pairNacionalitats : it->second) {
            cout << "\t" << left << setw(35) << pairNacionalitats.first << setw(8) << ":" << setw(8) << pairNacionalitats.second << endl;

        }
    }
}

void mostrarNivellEstudis(Padro &padro) {
    cout << "******************************" << endl;
    cout << "* 08: Resum nivell d'estudis *" << endl;
    cout << "******************************" << endl;
    map<int, vector<pair<string, double>>> nivellEstudis = padro.resumNivellEstudis();

    for (map<int, vector<pair<string, double>>>::const_iterator it = nivellEstudis.begin(); it != nivellEstudis.end(); it++) {
        cout << it->first << ":" << endl;
        for (pair<string, double> estudis : it->second) {
            cout << "\t" << left << setw(35) << estudis.first << left << setw(16) << "Promig Estudis:" << setw(8) << right << fixed << setprecision(2) << redondear(estudis.second) << endl;

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

void mostrarNombreHabitantsSeccio(Padro &padro) {
    cout << "*******************************************************" << endl;
    cout << "* 05: Obtenir nombre d'habitants d'un any i districte *" << endl;
    cout << "*******************************************************" <<endl;
    long total = 0;

    map<int, long> numHabitants = padro.obtenirNumHabitantsPerSeccio();

    for (map<int, long>::const_iterator it = numHabitants.begin(); it != numHabitants.end(); it++) {
        cout << "Seccio " << it->first << "   Habitants:" << setw(7) << it->second << endl;
        total += it->second;

    }

    cout << "TOTAL : " << total << endl;
}

void mostrarNombreHabitants(Padro &padro) {
    cout << "******************************************" << endl;
    cout << "* 04: Obtenir nombre d habitants d un any*" << endl;
    cout << "******************************************" <<endl;
    int any;
    long total = 0;
    cin >> any;
    vector<long> numHabitants = padro.obtenirNumHabitantsPerDistricte(any);
    cout << "Any:" << any << endl;
    for (int i = 0; i < numHabitants.size(); i++) {
        cout << "Districte " << i + 1 << "\tHabitants:" << setw(8) << right << numHabitants[i] << endl;
        total += numHabitants[i];

    }

    cout << "TOTAL : " << total << endl;
}

void mostrarNombreHabitantsAny(Padro &padro) {
    cout << "**********************************" << endl;
    cout << "* 03: Obtenir nombre d'habitants *" << endl;
    cout << "**********************************" <<endl;
    map<int, long> habitants = padro.obtenirNumHabitantsPerAny();
    int contador = 0;
    double promedio = 0;

    for (map<int, long>::const_iterator it = habitants.cbegin(); it != habitants.cend(); it++) {
        cout << it->first << "   habitants" << setw(7) << it->second << endl;
        contador++;
        promedio += it->second;

    }

    promedio = promedio / contador;

    cout << "PROMIG : " << redondear(promedio) << endl;



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

    } else if (opcio == "03") {
        if (ficheroLeido) {
            mostrarNombreHabitantsAny(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    } else if (opcio == "04") {
        if (ficheroLeido) {
            mostrarNombreHabitants(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    } else if (opcio == "05") {
        if (ficheroLeido) {
            mostrarNombreHabitantsSeccio(padro);

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

    } else if (opcio == "08") {
        if (ficheroLeido) {
            mostrarNivellEstudis(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    }else if (opcio == "09") {
        if (ficheroLeido) {
            mostrarNacionalitats(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    }else if (opcio == "10") {
        if (ficheroLeido) {
            mostrarMovimentsComunitat(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    }else if (opcio == "11") {
        if (ficheroLeido) {
            mostrarEdatMitjana(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    }else if (opcio == "12") {
        if (ficheroLeido) {
            mostrarEdatVells(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    }else if (opcio == "13") {
        if (ficheroLeido) {
            mostrar(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    }
    else if (opcio == "14") {
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


