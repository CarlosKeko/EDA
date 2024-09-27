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

int estructuraDinamica::nElements() const {
    node *p = inici;
    int comptador = 0;

    while (p != NULL) {
        comptador++;
        p = p->seguent;
    }

    return comptador;
}

void estructuraDinamica::OmplirFinal(int i) {
    node *p = final;
    node *nouValor = new node;
    int numInserit = 1;


    if (p == NULL) {
        nouValor->dada = numInserit;
        nouValor->seguent = NULL;
        numInserit++;
        inici = nouValor;
        final = nouValor;

    }

    while (numInserit <= i) {
        node *nouValor = new node;
        nouValor->dada = numInserit;
        nouValor->seguent = NULL;
        final->seguent = nouValor;
        final = nouValor;
        numInserit++;
    }
}

estructuraDinamica::~estructuraDinamica() {
    while (inici != NULL) {
        node *aux = inici;
        inici = inici->seguent;
        delete aux;
    }
}
