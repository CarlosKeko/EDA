/*
 *  estructuraDinamica.cpp
 *  EstructuraDinamica
 *
 *  Created by Didac Barragan & Joan Surrell.
 *  Copyright (c) 2004-2021 IMAE-UdG.
 *
 */

#include <iostream>

#include "estructuraDinamica.h"

using namespace std;


estructuraDinamica::estructuraDinamica()
{
// aquest constructor es dona fet i no es pot canviar
	inici = final = NULL;
}

void estructuraDinamica::AfegirInici(int i) {
    node *p = inici;

    if (inici == NULL) {
        p = new node;
        p->dada = i;
        p->seguent = NULL;
        inici = p;
        final = p;

    }else {
        node *aux = new node;
        aux->dada = i;
        aux->seguent = inici;
        inici = aux;


    }
}

int estructuraDinamica::TreureFinal() {
    node *p = inici;
    node *anterior = inici;
    int valor;

    if (final == NULL) {
        return 0;

    }else {
        while(p != final) {
            if (p->seguent == final) {
                anterior = p;

            }
            p = p->seguent;
        }

        valor = p->dada;
        anterior->seguent = NULL;
        final = anterior;

        if (inici == p) {
            inici = NULL;
            final = NULL;
        }

        return valor;
    }

}

void estructuraDinamica::Llistar() const
{
// aquest metode es dona fet i no es pot canviar
	node * p = inici;
	while (p != final) {
		cout << p->dada << " ";
		p = p-> seguent;
	}
	if (p != NULL)
		cout << p->dada << endl;
	else
		cout << endl;
}

estructuraDinamica::~estructuraDinamica() {
    while (inici != NULL) {
        node *aux = inici;
        inici = inici->seguent;
        delete aux;
    }
}
