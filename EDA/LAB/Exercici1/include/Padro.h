#ifndef PADRO_H
#define PADRO_H


#include <string>
#include "Districte.h"
#include "Estudi.h"
#include "Nacionalitat.h"
#include "Persona.h"
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Padro
{
    public:
        Padro();
        int afegir(int any, int districte, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat);
        vector<long> obtenirNumHabitantsPerDistricte() const;
        vector<pair<string, double>> resumEdat() const;
        list<string> resumEstudis() const;
        vector<pair<string, long>> edatNacioPerDistricte(int edat, int codiNacionalitat) const;
        vector<list<string>> diferentsNacionalitats(int districte1, int districte2) const;

    private:
        vector<Districte> districtes;
        vector<string> nomDistricte;
        int anyPadro;


};


#endif // PADRO_H
