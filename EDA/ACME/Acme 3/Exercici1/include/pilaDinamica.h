/*
 *  pilaDinamica.h
 *  PilaDinamica
 *
 *  Created by Joan Surrell on Mon Oct 30 2006.
 *  Copyright (c) 2004-2006 IMA-UdG. All rights reserved.
 *
 * Aquest fitxer conte la definicio de la pila dinamica simplement
 * encadenada. Cal implementar tots els metodes.
 * La definicio es pot adaptar facilment a qualsevol tipus base.
 */


#ifndef PILADINAMICA_H
#define PILADINAMICA_H


#include <cstdlib>
#include <iostream>
using namespace std;


typedef char element; // es pot canviar per qualsevol tipus

struct node
{
    element dada;
    node *seguent;
};

class pilaDinamica
{
public:
    pilaDinamica();
    pilaDinamica(const pilaDinamica & p); // no es demana

    void Empila(element e);
    void Desempila();
    element Cim() const;
    bool Buida() const;

    ~pilaDinamica();

private:
    node * inici;
};


#endif
