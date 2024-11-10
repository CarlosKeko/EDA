#include "Districte.h"
#include <vector>
#include <list>
#include <string>
#include <iostream>

Districte::Districte() {

}

void Districte::afegir(int seccio, int any, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat) {
    Persona persona(codiNivellEstudis, nivellEstudis, anyNaixement, codiNacionalitat, nomNacionalitat);
    Nacionalitat nacionalitat(codiNacionalitat, nomNacionalitat);
    habitants[seccio].push_back(persona);
    nacionalitats.push_back(nacionalitat);
    anyPadro = any;

}

long Districte::obtenirNumHabitants() const {
    long comptador = 0;

    for (map<int, list<Persona>>::const_iterator it = habitants.begin(); it != habitants.end(); it++) {
        comptador += it->second.size();
    }

    return comptador;

}

double Districte::obtenirEdatMitjana() const {
    double edadMedia = 0.0;

    for (map<int, list<Persona>>::const_iterator itU = habitants.cbegin(); itU != habitants.cend(); itU) {
        for (list<Persona>::const_iterator it = itU->second.cbegin(); it != itU->second.cend(); ++it) {
            edadMedia += anyPadro - it->obtenirAnyNaixement();

        }

    }

    return edadMedia / habitants.size();
}

list<string> Districte::resumEstudis() const {
    list<string> nomEstudis;
    /*bool enLlista = false;
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
    }*/

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
    long num = 0;

    for (map<int, list<Persona>>::const_iterator itU = habitants.cbegin(); itU != habitants.cend(); itU++) {
        for (list<Persona>::const_iterator it = itU->second.cbegin(); it != itU->second.cend(); it++) {
            if (it->obtenirAnyNaixement() == anyNaixement && it->obtenirCodiPaisNaixement() == codiNacionalitat) {
                num++;
            }
        }

    }


    return num;
}

list<string> Districte::obtenirEstudis(int edat, int codiNacionalitat) const {
    int anyNaixment = anyPadro - edat;
    list<string> resultat;

    for (map<int, list<Persona>>::const_iterator itU = habitants.cbegin(); itU != habitants.cend(); itU++) {
        for (list<Persona>::const_iterator it = itU->second.cbegin(); it != itU->second.cend(); it++) {
            if (it->obtenirAnyNaixement() == anyNaixment && it->obtenirCodiPaisNaixement() == codiNacionalitat) {
                resultat.push_back(it->obtenirNivellEstudis());

            }
        }
    }



    return resultat;
}

map<int, long> Districte::obtenirSeccioHabitants() const {
    map<int, long> resultat;

    for (map<int, list<Persona>>::const_iterator it = habitants.begin(); it != habitants.end(); it++) {
        resultat[it->first] = it->second.size();

    }

    return resultat;
}

double Districte::calcularNivellEstudis() const {
    double resultat = 0;

    for (map<int, list<Persona>>::const_iterator it = habitants.begin(); it != habitants.end(); it++) {
        for (list<Persona>::const_iterator itPersona = it->second.begin(); itPersona != it->second.end(); itPersona++) {
            resultat += itPersona->obtenirCodiNivellEstudis();

        }

    }

    resultat = resultat / obtenirNumHabitants();
    return resultat;

}

map<string, long> Districte::obtenirPaisos() const {
    map<string, long> resultat;

    for (map<int, list<Persona>>::const_iterator it = habitants.begin(); it != habitants.end(); it++) {
        for (list<Persona>::const_iterator itPersona = it->second.begin(); itPersona != it->second.end(); itPersona++) {

            if (resultat.find(itPersona->obtenirNivellCodiPais()) != resultat.end()) {
                resultat[itPersona->obtenirNivellCodiPais()] = resultat[itPersona->obtenirNivellCodiPais()] + 1;

            }else {
                resultat[itPersona->obtenirNivellCodiPais()] = 1;

            }
        }
    }

    return resultat;

}