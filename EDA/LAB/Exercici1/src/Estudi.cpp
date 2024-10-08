#include "Estudi.h"

Estudi::Estudi(int i, string n) {
    id = i;
    nom = n;
}

int Estudi::obtenirId() const {
    return id;
}

string Estudi::obtenirNom() const {
    return nom;
}

bool Estudi::operator==(const Estudi &estudi) const {
    return id == estudi.id;
}
