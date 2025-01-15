#include "Candidats.h"

Candidats::Candidats(const list<Assignatura> &elements) : elements(elements), actualElement(elements.begin()) {}

Assignatura Candidats::actual() const {
    if (actualElement == elements.end()) {
        throw runtime_error("Fuera de rango");
    }

    return *actualElement;

}

bool Candidats::fi() const {
    return actualElement == elements.end();

}

void Candidats::seguent() {
    actualElement++;

}
