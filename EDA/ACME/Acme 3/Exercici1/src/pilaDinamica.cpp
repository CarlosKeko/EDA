#include "pilaDinamica.h"

pilaDinamica::pilaDinamica()
{
    inici = NULL;
}

void pilaDinamica::Empila(element e) {
    node *p = new node;
    p->dada = e;
    p->seguent = NULL;

    if (inici != NULL) {
        p->seguent = inici;

    }

    inici = p;
}

bool pilaDinamica::Buida() const {
    return inici == NULL;

}

void pilaDinamica::Desempila() {
    if (!Buida()) {
        node *aux = inici;
        inici = inici->seguent;
        delete aux;

    }

}

element pilaDinamica::Cim() const {
    if (!Buida()) {
        return inici->dada;

    }else {
        return NULL;
    }

}

pilaDinamica::~pilaDinamica() {
    while(inici != NULL) {
        node *aux = inici;
        inici = inici->seguent;
        delete aux;
    }
}
