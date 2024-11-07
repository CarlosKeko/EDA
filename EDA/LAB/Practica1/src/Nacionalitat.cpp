#include "Nacionalitat.h"

Nacionalitat::Nacionalitat(int i, string n) {
    id = i;
    nom = n;

}

int Nacionalitat::obtenirId() const {
    return id;

}

string Nacionalitat::obtenirNom() const {
    return nom;

}

bool Nacionalitat::operator==(const Nacionalitat &nacio) const {
    return id == nacio.id;

}
