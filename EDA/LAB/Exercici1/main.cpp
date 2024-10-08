#include <iostream>
#include <fstream>
#include <string>
#include <Padro.h>
#include <vector>
#include <list>

using namespace std;

const int NUM_DISTRICTES = 6;

void mostrarEdatNacionalitat(Padro &padro) {
    int edat, codiNacionalitat;
    cin >> edat;
    cin >> codiNacionalitat;

    vector<pair<string, long>> habitants = padro.edatNacioPerDistricte(edat, codiNacionalitat);

    cout << "Edat:" << edat << "   Codi Nacionalitat:" << codiNacionalitat << endl;

    for (int i = 0; i < habitants.size(); i++) {
        if (habitants[i].second > 0) {
            cout << habitants[i].first << ": " << habitants[i].second << endl;
        }
    }
}

void mostrarNacionalitatsExclusives(Padro &padro) {
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
    vector<pair<string, double>> edats = padro.resumEdat();
    vector<pair<string, double>>::iterator it;

    for (it = edats.begin(); it != edats.end(); it++) {
        cout << "\t\t" << it->first << "\t\tPromig Edat:\t" << it->second << endl;
    }
}

void mostrarEstudis(Padro &padro) {
    list<string> estudis = padro.resumEstudis();
    list<string>::reverse_iterator it;

    cout << "Estudis:" << endl;

    estudis.sort();

    for (it = estudis.rbegin(); it != estudis.rend(); it++) {
        cout << " - " << *it << endl;
    }

}

void mostrarNombreHabitants(Padro &padro) {
    long total = 0;
    vector<long> numHabitants = padro.obtenirNumHabitantsPerDistricte();

    for (int i = 0; i < NUM_DISTRICTES; i++) {
        cout << "Districte " << i + 1 << "\tHabitants:\t" << numHabitants[i] << endl;
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

void lecturaFichero(Padro &padro) {
    ifstream archivo("padroCurt.txt");
    string linea, palabra;
    string any, districte, codiEstudis, nivelLStudis, dataNaixement, codiNacionalitat, nacionalitat;

    if (!archivo.is_open()) {
        cout << "\nEl archivo no se ha podido abrir" << endl;

    }else {
        getline(archivo, linea);
        while(not archivo.eof()) {
            archivo>>any>>districte>>codiEstudis>>nivelLStudis>>dataNaixement>>codiNacionalitat>>nacionalitat;
            padro.afegir(stringToInt(any), stringToInt(districte), stringToInt(codiEstudis), nivelLStudis, stringToInt(dataNaixement), stringToInt(codiNacionalitat), nacionalitat);
            //cout<< "hola" << endl;
        }

        archivo.close();
        cout << "\n Archivo leido" << endl;
    }
}

void escollirOpcio(char opcio, Padro &padro) {
        switch(opcio) {
            case '1':
                lecturaFichero(padro);
                break;

            case '2':
                mostrarNombreHabitants(padro);
                break;

            case '3':
                mostrarEstudis(padro);
                break;

            case '4':
                mostrarEdatMitjana(padro);
                break;

            case '5':
                mostrarNacionalitatsExclusives(padro);
                break;

            case '6':
                mostrarEdatNacionalitat(padro);
                break;

            case '0':
                cout << "\nADIOS!" << endl;
                break;

            default:
                cout << "\nOpcion invalida!" << endl;
        }
}

void mostrarMenu(Padro &padro) {
    char opcio;

    do {
        cout << "\n(1) Cargar datos" << endl;
        cout << "(2) " << endl;
        cout << "(3) " << endl;
        cout << "(4) " << endl;
        cout << "(5) " << endl;
        cout << "(6) " << endl;
        cout << "(0) Exit\n" << endl;

        cout << "Escoge opcion (0 - 6): ";
        cin >> opcio;

        escollirOpcio(opcio, padro);

    }while(opcio != '0');
}

int main()
{
    Padro padro;
    mostrarMenu(padro);
    return 0;
}


