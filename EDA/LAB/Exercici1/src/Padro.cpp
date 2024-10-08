#include "Padro.h"
#include "vector"
#include "list"
#include "Districte.h"
#include "Persona.h"
#include "utility"

Padro::Padro(): districtes(6, Districte())
{
    nomDistricte.push_back("Carme, Vila-roja");
    nomDistricte.push_back("Eixample, Montilivi");
    nomDistricte.push_back("Santa Eugenia, Mas Xirgu");
    nomDistricte.push_back("Casc Antic");
    nomDistricte.push_back("Montjuic, Pont major");
    nomDistricte.push_back("Sant Ponc, Domeny, Taiala");


}

int Padro::afegir(int any, int districte, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat) {
    int sizeDis = districtes.size();
    districtes[districte - 1].afegir(any, codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat);

    anyPadro = any;

    if (sizeDis < districtes.size()) {
        return 1;

    }else {
        return 0;

    }

}

vector<long> Padro::obtenirNumHabitantsPerDistricte() const {
    vector<long> numHabitants;

    for (int i = 0; i < districtes.size(); i++) {
        numHabitants.push_back(districtes[i].obtenirNumHabitants());

    }

    return numHabitants;
}

vector<pair<string, double>> Padro::resumEdat() const {
    vector<pair<string, double>> edats;

    for (int i = 0; i < districtes.size(); i++) {
        edats.push_back(make_pair(nomDistricte[i], districtes[i].obtenirEdatMitjana()));

    }

    return edats;

}

list<string> Padro::resumEstudis() const {
    list<string> resumEstudis;
    list<string>::const_iterator it;
    list<string>::const_iterator itDos;
    bool repetit = false;

    for (int i = 0; i < districtes.size(); i++) {
        list<string> districteActual = districtes[i].resumEstudis();
        for (it = districteActual.begin(); it != districteActual.end(); it++) {
            for (itDos = resumEstudis.begin(); itDos != resumEstudis.end(); itDos++) {
                if (*it == *itDos) {
                    repetit = true;
                }
            }

            if (!repetit) {
                resumEstudis.push_back(*it);

            }

            repetit = false;
        }

    }

    return resumEstudis;
}

vector<pair<string, long>> Padro::edatNacioPerDistricte(int edat, int codiNacionalitat) const {
    int anyNascut = anyPadro - edat;
    vector<pair<string, long>> edats;

    for (int i = 0; i < districtes.size(); i++) {
        edats.push_back(make_pair(nomDistricte[i], districtes[i].comptaEdatNacionalitat(anyNascut, codiNacionalitat)));

    }

    return edats;
}

vector<list<string>> Padro::diferentsNacionalitats(int districte1, int districte2) const {
    vector<list<string>> nacionalitats;
    list<string> nacionalitatsDis1;
    list<string> nacionalitatsDis2;
    list<string> nacionalitatsUn = districtes[districte1 - 1].resumNacionalitats();
    list<string> nacionalitatsDos = districtes[districte2 - 1].resumNacionalitats();
    list<string>::const_iterator it;
    list<string>::const_iterator itDos;
    bool noEsta = true;
    for (it = nacionalitatsUn.begin(); it != nacionalitatsUn.end(); it++) {
        for (itDos = nacionalitatsDos.begin(); itDos != nacionalitatsDos.end(); itDos++) {
            if (*it == *itDos) {
                noEsta = false;
            }

        }
        if (noEsta) {
            nacionalitatsDis1.push_back(*it);

        }

        noEsta = true;
    }
    noEsta = true;

    for (it = nacionalitatsDos.begin(); it != nacionalitatsDos.end(); it++) {
        for (itDos = nacionalitatsUn.begin(); itDos != nacionalitatsUn.end(); itDos++) {
            if (*it == *itDos) {
                noEsta = false;
            }
        }

        if (noEsta) {
            nacionalitatsDis2.push_back(*it);

        }

        noEsta = true;
    }
    nacionalitatsDis1.sort();
    nacionalitatsDis2.sort();
    nacionalitatsDis1.unique();
    nacionalitatsDis2.unique();

    nacionalitats.push_back(nacionalitatsDis1);
    nacionalitats.push_back(nacionalitatsDis2);

    return nacionalitats;
}
