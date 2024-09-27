/*
 *  estructuraDinamica.h
 *  EstructuraDinamica
 *
 *  Created by Santi Espigule.
 *  Copyright (c) 2004 IMA-UdG.
 *
 * JSS - 2009
 *    cal afegir-hi els metodes a implementar
* JSS - 2022
 *    es obligatori implementar el destructor
 */

#include "estructuraDinamica.h"
#include <iostream>


estructuraDinamica::estructuraDinamica( )
{
// aquest constructor es dona fet i no es pot canviar
	final = NULL;
}

estructuraDinamica::estructuraDinamica(const estructuraDinamica &e) {
    final = new node;
    node *anterior;
    node *estructuraCopia = e.final;
    node *p = new node;
    final->dada = estructuraCopia->dada;
    estructuraCopia = estructuraCopia->seguent;
    anterior = final;

    if (estructuraCopia == e.final) {

        final->seguent = final;

    }else {
        while (estructuraCopia != e.final) {
            p = new node;
            p->dada = estructuraCopia->dada;
            anterior->seguent = p;
            anterior = p;
            estructuraCopia = estructuraCopia->seguent;
            if (estructuraCopia == e.final) {
                anterior->seguent = final;
            }

        }
    }



}

estructuraDinamica::~estructuraDinamica() {
    if (final != NULL) {
        node *aux = final->seguent;
        final->seguent = NULL;

        while (aux != NULL) {
            node *auxDelete = aux;
            aux = aux->seguent;
            delete auxDelete;
        }
    }

}

void estructuraDinamica::Llistar() const
{
// aquest metode es dona fet i no es pot canviar
    node *p;

    if (final != NULL)
    {
        p = final->seguent;
        while (p != final)
        {
            cout << p->dada << " ";
            p = p->seguent;
        }
        cout << final->dada;
    }
    cout << endl;
}


void estructuraDinamica::AfegirInici(int i ) {
    node *p = new node;

    if (final == NULL) {
        final = new node;
        final->dada = i;
        final->seguent = final;

    }else if (final->seguent == final){
        p->dada = i;
        p->seguent = final;
        final->seguent = p;

    }else {
        p->dada = i;
        p->seguent = final->seguent;
        final->seguent = p;
    }
}
