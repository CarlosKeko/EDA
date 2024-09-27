/*
 *  estructuraDinamica.h
 *  EstructuraDinamica
 *
 *  Created by Santi Espigule.
 *  Copyright (c) 2004 IMA-UdG.
 *
 * Aquest fitxer es comu a tots els programes que usen l'estructura circular
 * final simplement encadenada. Cal implementar *nomes* els metodes que demana cada
 * enunciat.
 */

#ifndef ESTRUCTURADINAMICA_H
#define ESTRUCTURADINAMICA_H


#include <cstdlib>
#include <iostream>
using namespace std;


struct node
{
    int dada;
    node * seguent;
};

class estructuraDinamica // circular final
{
public:
    estructuraDinamica();
    estructuraDinamica(const estructuraDinamica &e);

    void AfegirInici(int i);
    void AfegirFinal(int i);
    void AfegirDespres(int i, int j);
    void AfegirAbans(int i, int j);
    void InserirOrdenadament(int i);

    bool Existeix(int i) const;
	int TreureFinal();
    void Esborrar(int i);

	void OmplirInici(int n);
	void OmplirFinal(int n);
	int nElements() const;

    void Llistar( ) const;

    ~estructuraDinamica();
private:
    node *final;
};

#endif
