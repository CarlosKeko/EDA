#include "Padro.h"
#include "vector"
#include "list"
#include "Districte.h"
#include "Persona.h"
#include "utility"
#include "eines.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int Padro::llegirDades(const string& path) {
    ifstream archivo(path);
    string linea;
    int numLinies = 0;

    asignarDistritos();

    if (!archivo.is_open()) {
        cout << "\nEl archivo no se ha podido abrir" << endl;

    }else {
        getline(archivo, linea);
        while(getline(archivo, linea)) {
            vector<string> tokensAux = tokens(linea, ',', true);
            vector<Districte> districtesAux;
            int any = stringToInt(tokensAux.at(0));
            int districte = stringToInt(tokensAux.at(1));
            int seccio = stringToInt(tokensAux.at(2));
            int codiEstudis = stringToInt(tokensAux.at(4));
            string estudis = tokensAux.at(5);
            int anyNaixement = stringToInt(tokensAux.at(6));
            int idNacionalitat = stringToInt(tokensAux.at(11));
            string nacionalitat = tokensAux.at(12);

            if (!existeixAny(any)) {
                padroAny[any] = vector<Districte>(6);

            }

            padroAny[any][districte - 1].afegir(seccio, any, codiEstudis, estudis, anyNaixement, idNacionalitat, nacionalitat);
            numLinies++;

        }
    }

    archivo.close();
    return numLinies;

}

bool Padro::existeixAny(int any) const {
    return padroAny.count(any);

}

map<int, long> Padro::obtenirNumHabitantsPerAny() const {
    map<int, long> habitantsAny;
    int numHabitants = 0;

    for (map<int, vector<Districte>>::const_iterator it = padroAny.cbegin(); it != padroAny.cend(); it++) {
        numHabitants = 0;

        for (Districte disAux : it->second) {
            numHabitants += disAux.obtenirNumHabitants();

        }

        habitantsAny[it->first] = numHabitants;
    }

    return habitantsAny;
}

vector<long> Padro::obtenirNumHabitantsPerDistricte(int any) const {
    vector<long> resultado;
    long numero = 0;

    if (existeixAny(any)) {
        auto it = padroAny.find(any);
        vector<Districte> districtes = it->second;

        for (int i = 0; i < districtes.size(); i++) {
            numero = districtes[i].obtenirNumHabitants();
            resultado.push_back(numero);

        }
    }

    return resultado;
}

map<int, long> Padro::obtenirNumHabitantsPerSeccio() const {
    map<int, long> resultat;

    int any, districte;
    cin >> any;

    while(!existeixAny(any)) {
        cout << "ERROR any " << any << " inexistent" << endl;
        cin >> any;

    }

    cin >> districte;

    while(!existeixDistricte(any, districte)) {
        cout << "ERROR districte " << districte << " inexistent" << endl;
        cin >> districte;

    }

    cout << "Any:" << any << "  Districte:" << districte << endl;

    map<int, vector<Districte>>::const_iterator itAny = padroAny.find(any);
    vector<Districte> districtes = itAny->second;

    if (itAny != padroAny.end()) {
        resultat = districtes[districte - 1].obtenirSeccioHabitants();

    }

    return resultat;

}

ResumEstudis Padro::resumEstudis() const {
    map<int, list<string>> resultat;
    int any;

    for (map<int, vector<Districte>>::const_iterator it = padroAny.cbegin(); it != padroAny.cend(); it++) {
        any = it->first;
        const vector<Districte> disAux = it->second;
        list<string> estudis;
        list<string> listaFinal;

        for (const Districte dis : disAux) {
            list<string> aux = dis.resumEstudis();
            estudis.insert(estudis.end(), aux.begin(), aux.end());

        }

        set<string> sinDuplicados;

        for (string estudios : estudis) {
            if (sinDuplicados.insert(estudios).second) {
                listaFinal.push_back(estudios);
            }
        }

        listaFinal.sort();
        listaFinal.reverse();
        resultat[any] = listaFinal;

    }

    return resultat;

}

map<int,int> Padro::nombreEstudisDistricte(int districte) const {
    map<int, int> resultat;
    int any;

    for (map<int, vector<Districte>>::const_iterator it = padroAny.cbegin(); it != padroAny.cend(); it++) {
        any = it->first;
        const list<string> disAux = it->second[districte - 1].resumEstudis();
        int num = 0;

        for (list<string>::const_iterator itAux = disAux.begin(); itAux != disAux.end(); itAux++) {
            num++;
        }

        resultat[any] = num;

    }

    return resultat;

}

ResumEdats Padro::resumEdat() const {
    map<int,vector<pair<string, double>>> edats;
    int any;

    for (map<int, vector<Districte>>::const_iterator it = padroAny.cbegin(); it != padroAny.cend(); it++) {
        any = it->first;
        const vector<Districte> disAux = it->second;
        vector<pair<string, double>> vectorAux;
        int contadorAux = 0;

        for (Districte dis : it->second) {
            vectorAux.push_back(make_pair(nomDistricte[contadorAux], dis.obtenirEdatMitjana()));
            contadorAux++;

        }
        vectorAux = algoritmoBurbuja(vectorAux);
        edats[any] = vectorAux;

    }

    return edats;
}

vector<pair<string, double>> Padro::algoritmoBurbuja(vector<pair<string, double>> vectorUsado) const {
    vector<pair<string, double>> productos = vectorUsado;
    int n = productos.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        for (int j = 0; j < n - i - 1; ++j) {
            if (productos[j].second > productos[j + 1].second) {
                swap(productos[j], productos[j + 1]);
                swapped = true;

            }
        }

    }

    return productos;
}

list<string> Padro::estudisEdat(int any, int districte, int edat, int codiNacionalitat) const {
    list<string> estudisEdat;

    if (existeixAny(any)) {
        auto it = padroAny.find(any);
        //vector<Districte> districtes = it->second;
        Districte dis = it->second[districte - 1];
        estudisEdat = dis.obtenirEstudis(edat, codiNacionalitat);


    }

    return estudisEdat;

}


//PRIVATE

int Padro::stringToInt ( string s ) {
    if ( s . length ()==0) return -1;

    for( char c : s ) {
        if (c <'0' || c >'9') return -1;
    }

    return stoi ( s );
}


void Padro::asignarDistritos() {
    nomDistricte.push_back("Carme, Vila-roja");
    nomDistricte.push_back("Eixample, Montilivi");
    nomDistricte.push_back("Santa Eugenia, Mas Xirgu");
    nomDistricte.push_back("Casc Antic");
    nomDistricte.push_back("Montjuic, Pont major");
    nomDistricte.push_back("Sant Ponc, Domeny, Taiala");

}

bool Padro::existeiyAny(int any) const {
    return padroAny.find(any) != padroAny.end();

}

bool Padro::existeixDistricte(int any, int districte) const {
    if (existeixAny(any)) {
        map<int, vector<Districte>>::const_iterator it = padroAny.find(any);
        vector<Districte> dis = it->second;
        if (districte >= 1 && districte <= dis.size()) {
            return true;

        }
    }

    return false;
}

