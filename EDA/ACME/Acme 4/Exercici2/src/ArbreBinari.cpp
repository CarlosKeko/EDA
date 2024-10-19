#include "ArbreBinari.h"
#include <memory>
#include <iostream>
//PUBLIC

ArbreBinari::ArbreBinari()
{
    arrel = NULL;

}

ArbreBinari::ArbreBinari(const char t[]) {
    int i = 0;
    arrel = iArbreBinari(t, i);
}

bool ArbreBinari::esBuit() const {
    return arrel == NULL;

}

ArbreBinari ArbreBinari::FillDret() const {
    ArbreBinari arbre;

    if (esBuit()) {
        throw("Arbol vacio");

    }else {
        arbre.arrel = arrel->fd;

    }

    return arbre;

}

ArbreBinari ArbreBinari::FillEsquerre() const {
    ArbreBinari arbre;

    if (esBuit()) {
        throw("Arbol vacio");

    }else {
        arbre.arrel = arrel->fe;

    }

    return arbre;

}

char ArbreBinari::Contingut() const {
    return arrel->dada;

}


//PRIVATE

shared_ptr<ArbreBinari::node> ArbreBinari::iArbreBinari(const char t[], int &i) {
    char c = t[i];
    shared_ptr<node> aux1, aux2;

    i++;

    if (t[i] != '(') {
        aux1 = NULL;
        aux2 = NULL;

    }else {
        i++;

        if (t[i] != ' ') {
            aux1 = iArbreBinari(t, i);

        }

        if(t[i] == ' '){
            i++;
            aux2 = iArbreBinari(t,i);
        }

        i++;
    }

    shared_ptr<ArbreBinari::node>res = make_shared<node>();
    res->dada = c;
    res->fe = aux1;
    res->fd = aux2;

    return res;
}
