/*
 *  estructuraDinamica.cpp
 *  EstructuraDinamica
 *
 *  Created by Joan Surrell on Wed Oct 06 2004.
 *  Copyright (c) 2004-2006 IMA-UdG. All rights reserved.
 *
 *
 * JSS - 2008
 *    cal afegir-hi els metodes a implementar
 *
 * JSS - 2022
 *    es obligatori implementar el destructor
 */

#include "estructuraDinamica.h"
#include <iostream>

using namespace std;


estructuraDinamica::estructuraDinamica( )
{
// aquest constructor es dona fet i no es pot canviar
	inici = NULL;
}


estructuraDinamica::~estructuraDinamica() {
    while (inici != NULL) {
        node *aux = inici;
        inici = inici->seguent;
        delete aux;
    }
}


void estructuraDinamica::AfegirInici(int i) {
    node *nou = new node;
    nou->dada = i;
    node *p = inici;
    node *a_inici;

    if (inici == NULL) {
        nou->seguent = nou;
        inici = nou;

    }else {
        nou->seguent = inici;
        inici = nou;
        a_inici = p;
        while(p->seguent != a_inici) {
            p = p->seguent;

        }

        p->seguent = inici;

    }
}

void estructuraDinamica::AfegirDespres(int i, int j) {
    node *nou = new node;
    nou->dada = i;
    node *p = inici;
    bool encontrat = false;

    if (inici == NULL) {
        nou->seguent = nou;
        inici = nou;

    }else {
        while(!encontrat) {
            if (p->dada == j) {
                encontrat = true;
            }

            if (p->seguent == inici) {
                encontrat = true;
            }

            if (encontrat) {
                nou->seguent = p->seguent;
                p->seguent = nou;
            }

            p = p->seguent;

        }

    }

}

void estructuraDinamica::Llistar() const
{
// aquest metode es dona fet i no es pot canviar
    if (inici != NULL) {
        node * p = inici->seguent;
        cout << inici->dada << " ";
        while (p != inici) {
            cout << p->dada << " "; p = p->seguent;
        }
    }
    cout << endl;

}