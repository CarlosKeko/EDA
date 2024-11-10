#include "Persona.h"
#include "Nacionalitat.h"
#include "Estudi.h"
#include <string>

Persona::Persona(int codiNivell, const string &nivellEst, int anyNaix, int codiPais, const string &pais) {
        codiNivellEstudis = codiNivell;
        nivellEstudis = nivellEst;
        anyNaixement = anyNaix;
        codiPaisNaixement = codiPais;
        paisNaixement = pais;

}

int Persona::obtenirAnyNaixement() const {
    return anyNaixement;

}

string Persona::obtenirNivellEstudis() const {
    return nivellEstudis;

}

int Persona::obtenirCodiPaisNaixement() const {
    return codiPaisNaixement;

}

int Persona::obtenirCodiNivellEstudis() const {
    return codiNivellEstudis;
}

string Persona::obtenirNivellCodiPais() const {
    return paisNaixement + " (" + std::to_string(codiPaisNaixement) + ")";
}
