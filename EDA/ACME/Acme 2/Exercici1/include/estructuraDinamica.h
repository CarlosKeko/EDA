/*
 *  estructuraDinamica.h
 *  EstructuraDinamica
 *
 *  Created by Joan Surrell & David Figuls on Wed Oct 06 2004.
 *  Copyright (c) 2004-2021 2004-2021 IMAE-UdG. All rights reserved.
 *
 * IMPORTANT:
 * Aquest fitxer es comu a tots els programes que usen l'estructura dinamica
 * simplement encadenada amb final.
 *
 * Nomes cal implementar els metodes que demana cada enunciat.
 */

#ifndef ESTRUCTURADINAMICA_H
#define ESTRUCTURADINAMICA_H


#include <cstdlib>
#include <iostream>

using namespace std;

struct node {
    int dada;
    node *seguent;
};

class estructuraDinamica  // Final
{
public:
    estructuraDinamica();
    estructuraDinamica(estructuraDinamica & e);

    void AfegirInici(int i);
    void AfegirFinal(int i);
    void InserirOrdenadament(int i);

    void AfegirDespres(int i, int ref);
    void AfegirAbans(int i, int ref);

    void Esborrar(int i);
    int TreureFinal();
    bool Existeix(int i) const;

    void OmplirInici(int n);
    void OmplirFinal(int n);
    int nElements() const;

    void Llistar() const;

    ~estructuraDinamica();

private:
    node *inici;
    node *final;
};


#endif
