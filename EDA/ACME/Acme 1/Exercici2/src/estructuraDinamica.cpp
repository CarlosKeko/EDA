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

void estructuraDinamica::AfegirInici(int i) {
    node *nou = new node;
    nou->dada = i;
    node *a_inici;

    if (inici == NULL) {
        nou->seguent = NULL;
        inici = nou;
        final = nou;

    }else {
        nou->seguent = inici;
        inici = nou;

    }
}

bool estructuraDinamica::Existeix(int i) const {
    node *p = inici;
    while(p != NULL) {
        if (p->dada == i) {
            return true;

        }

        p = p->seguent;

    }

    return false;
}

estructuraDinamica::~estructuraDinamica() {
    while (inici != NULL) {
        node *aux = inici;
        inici = inici->seguent;
        delete aux;
    }
}
