#include "Assignatura.h"

Assignatura::Assignatura(string grau, string assignatura, string codi, char tipus, double credits, int semestre, int curs) {
    this->grau = grau;
    this->assignatura = assignatura;
    this->codi = codi;
    this->tipus = tipus;
    this->credits = credits;
    this->semestre = semestre;
    this->curs = curs;

}

string Assignatura::getGrau() const {
    return grau;

}

string Assignatura::getAssignatura() const {
    return assignatura;

}

string Assignatura::getCodi() const {
    return codi;

}

char Assignatura::getTipus() const {
    return tipus;

}

double Assignatura::getCredits() const {
    return credits;

}

int Assignatura::getSemestre() const {
    return semestre;

}

int Assignatura::getCurs() const {
    return curs;

}

bool Assignatura::operator<(const Assignatura &a2) const {
    if (codi != a2.codi) {
        return codi < a2.codi;

    }else if (curs != a2.curs) {
        return curs < a2.curs;

    }else {
        return grau < a2.grau;
    }
}

bool Assignatura::operator==(const Assignatura &a2) const {
    return codi == a2.codi;
}
