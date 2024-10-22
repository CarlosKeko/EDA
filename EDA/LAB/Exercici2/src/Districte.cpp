#include "Districte.h"
#include <vector>
#include <list>
#include <string>
#include <iostream>

Districte::Districte() {

}

void Districte::afegir(int any, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat) {
    Persona persona(codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat);
    Nacionalitat nacionalitat(codiNacionalitat, nomNacionalitat);
    habitants.push_back(persona);
    nacionalitats.push_back(nacionalitat);
    anyPadro = any;

}

long Districte::obtenirNumHabitants() const {
    return habitants.size();

}

double Districte::obtenirEdatMitjana() const {
    double edadMedia = 0.0;
    list<Persona>::const_iterator it;

    for (it = habitants.begin(); it != habitants.end(); ++it) {
        edadMedia += anyPadro - it->obtenirAnyNaixement();

    }

    return edadMedia / habitants.size();
}

list<string> Districte::resumEstudis() const {
    list<string> nomEstudis;
    bool enLlista = false;
    list<string>::const_iterator it;
    list<Persona>::const_iterator itPersona;

    for (itPersona = habitants.begin(); itPersona != habitants.end(); itPersona++) {
        for (it = nomEstudis.begin(); it != nomEstudis.end(); ++it) {
            if (*it == itPersona->obtenirNivellEstudis()) {
                enLlista = true;
            }
        }

        if (!enLlista) {
            nomEstudis.push_back(itPersona->obtenirNivellEstudis());

        }
        enLlista = false;
    }

    return nomEstudis;

}

list<string> Districte::resumNacionalitats() const {
    list<Nacionalitat>::const_iterator it;
    list<Nacionalitat>::const_iterator itNom;
    list<Nacionalitat> nacionalitatUnic;
    list<string> nacionalitatNom;
    bool encontrat = false;

    for (it = nacionalitats.begin(); it != nacionalitats.end(); ++it) {
        for (itNom = nacionalitatUnic.begin(); itNom != nacionalitatUnic.end(); ++itNom) {
            if (*it == *itNom) {
                encontrat = true;
            }
        }

        if (!encontrat) {
            nacionalitatNom.push_back(it->obtenirNom());

        }

        encontrat = false;

    }

    return nacionalitatNom;

}

long Districte::comptaEdatNacionalitat(int anyNaixement, int codiNacionalitat) const {
    list<Persona>::const_iterator it;
    long num = 0;

    for (it = habitants.begin(); it != habitants.end(); it++) {
        if (it->obtenirAnyNaixement() == anyNaixement && it->obtenirCodiPaisNaixement() == codiNacionalitat) {
            num++;
        }
    }

    return num;
}

list<string> Districte::obtenirEstudis(int edat, int codiNacionalitat) const {
    int anyNaixment = anyPadro - edat;
    list<string> resultat;

    for (Persona persona : habitants) {
        if (persona.obtenirAnyNaixement() == anyNaixment && persona.obtenirCodiPaisNaixement() == codiNacionalitat) {
            resultat.push_back(persona.obtenirNivellEstudis());

        }

    }

    return resultat;
}
