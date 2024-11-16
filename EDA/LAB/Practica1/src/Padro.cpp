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
            int anyAlta = stringToInt(tokensAux.at(13).substr(tokensAux.at(13).size() - 4));

            if (!existeixAny(any)) {
                padroAny[any] = vector<Districte>(6);
                int comptador = 0;

                for (Districte &dis : padroAny[any]) {
                    dis.asignarNomDistricte(nomDistricte[comptador]);
                    comptador++;

                }

            }

            padroAny[any][districte - 1].afegir(anyAlta, seccio, any, codiEstudis, estudis, anyNaixement, idNacionalitat, nacionalitat);
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

ResumNivellEstudis Padro::resumNivellEstudis() const {
    map<int, vector<pair<string, double>>> resultat;
    int contador = 0;
    int posicionGrande = 0;
    int posicionPeque = 0;

    for (map<int, vector<Districte>>::const_iterator itAny = padroAny.begin(); itAny != padroAny.end(); itAny++) {
        contador = 0;

        for (Districte dis : itAny->second) {
            pair<string, double> pairAux("  " + nomDistricte[contador], dis.calcularNivellEstudis());
            resultat[itAny->first].push_back(pairAux);
            contador++;

        }

        posicionGrande = 0;
        posicionPeque = 0;
        contador = 0;

        for (pair<string, double> itAux : resultat[itAny->first]) {
            if (itAux.second >= resultat[itAny->first][posicionGrande].second) {
                posicionGrande = contador;

            }

            if (itAux.second <= resultat[itAny->first][posicionPeque].second) {
                posicionPeque = contador;

            }

            contador++;
        }

        pair<string, double> gran("+ " + nomDistricte[posicionGrande], resultat[itAny->first][posicionGrande].second);
        resultat[itAny->first][posicionGrande] = gran;

        pair<string, double> petit("- " + nomDistricte[posicionPeque], resultat[itAny->first][posicionPeque].second);
        resultat[itAny->first][posicionPeque] = petit;


    }

    return resultat;
}

ResumNacionalitats Padro::resumNacionalitats() const {
    map<int, map<string, long>> resultat;
    map<string, long> aux;

    for (map<int, vector<Districte>>::const_iterator it = padroAny.begin(); it != padroAny.end(); it++) {
        for (Districte dis : it->second) {
            aux = dis.obtenirPaisos();

            for (map<string, long>::const_iterator itAux = aux.begin(); itAux != aux.end(); itAux++) {
                if (resultat[it->first].find(itAux->first) != resultat[it->first].end()) {
                    resultat[it->first][itAux->first] = resultat[it->first][itAux->first] + itAux->second;

                }else {
                    resultat[it->first][itAux->first] = itAux->second;

                }
            }
        }
    }
    map<int, vector<pair<string, long>>> resultatFinal;

    for (map<int, map<string, long>>::const_iterator it = resultat.begin(); it != resultat.end(); it++) {
        vector<pair<string, long>> mapaOrdenado(it->second.begin(), it->second.end());

        sort(mapaOrdenado.begin(), mapaOrdenado.end(),
              [](const pair<string, long>& a, const pair<string, long>& b) {
                  return a.second > b.second;  // Cambia a > para orden descendente
              });

        resultatFinal[it->first] = mapaOrdenado;

    }



    return resultatFinal;
}

map<int,string> Padro::movimentsComunitat(int codiNacionalitat) const {
    map<int, string> resultat;
    string nom = " ";
    int mesGran = 0;

    for (map<int, vector<Districte>>::const_iterator it = padroAny.cbegin(); it != padroAny.cend(); it++) {
        nom = "No te habitants";
        mesGran = 0;

        for (Districte dis : it ->second) {
            if (dis.obtenirNumHabitantsCodi(codiNacionalitat) > mesGran) {
                mesGran = dis.obtenirNumHabitantsCodi(codiNacionalitat);
                nom = dis.obtenirNomDistricte();

            }
        }

        resultat[it->first] = nom;
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

map<int, string> Padro::movimentVells() const {
    map<int, string> resultat;
    double contadorAux = 0;
    double disComptador = 0;
    Districte disAux;

    for (map<int, vector<Districte>>::const_iterator it = padroAny.cbegin(); it != padroAny.cend(); it++) {
        contadorAux = 0;

        for (Districte dis : it->second) {
            disComptador = dis.obtenirEdatMitjana();
            if (disComptador > contadorAux) {
                disAux = dis;
                contadorAux = disComptador;

            }

        }

        resultat[it->first] = disAux.obtenirNomDistricte();

    }


    return resultat;
}

pair<string,long> Padro::mesJoves(int anyInicial, int anyFinal) const {
    long mesJoves = 0;
    string nom = "";
    map<string, long> mapaAux;
    map<string, long> mapaAuxDos;

    for (map<int, vector<Districte>>::const_iterator it = padroAny.begin(); it != padroAny.end(); it++) {

        if (it->first == anyInicial) {
            for (Districte dis : it->second) {
                if (mapaAux.find(dis.obtenirNomDistricte()) != mapaAux.end()) {
                    mapaAux[dis.obtenirNomDistricte()] =  mapaAux[dis.obtenirNomDistricte()] + dis.numJoves();

                }else {
                    mapaAux[dis.obtenirNomDistricte()] =  dis.numJoves();

                }

            }
        }else if (it->first == anyFinal) {
            for (Districte dis : it->second) {
                if (mapaAuxDos.find(dis.obtenirNomDistricte()) != mapaAuxDos.end()) {
                    mapaAuxDos[dis.obtenirNomDistricte()] =  mapaAuxDos[dis.obtenirNomDistricte()] + dis.numJoves();

                }else {
                    mapaAuxDos[dis.obtenirNomDistricte()] =  dis.numJoves();

                }

            }
        }
    }

    for (map<string, long>::const_iterator it = mapaAux.begin(); it != mapaAux.end(); it++) {
        for (map<string, long>::const_iterator itDos = mapaAuxDos.begin(); itDos != mapaAuxDos.end(); itDos++) {
            if (it->first == itDos->first) {
                if ((itDos->second - it->second) >= mesJoves) {
                    nom = it->first;
                    mesJoves = itDos->second - it->second;
                }

            }
        }
    }

    pair<string, long> resultat(nom, mesJoves);
    return resultat;
}

list<string> Padro::estudisEdat(int any, int districte, int edat, int codiNacionalitat) const {
    list<string> estudisEdat;

    if (existeixAny(any)) {
        map<int, vector<Districte>>::const_iterator it = padroAny.find(any);
        //vector<Districte> districtes = it->second;
        Districte dis = it->second[districte - 1];
        estudisEdat = dis.obtenirEstudis(edat, codiNacionalitat);


    }
    estudisEdat.sort();
    return estudisEdat;

}


//PRIVATE

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

