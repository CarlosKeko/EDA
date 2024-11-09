#ifndef DISTRICTE_H
#define DISTRICTE_H


#include <string>
#include "Persona.h"
#include <vector>
#include <list>
#include "Nacionalitat.h"
#include <map>

using namespace std;

class Districte
{
    public:
        Districte();
        void afegir(int seccio, int any, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat);
        long obtenirNumHabitants() const;
        double obtenirEdatMitjana() const;
        list<string> resumEstudis() const;
        list<string> resumNacionalitats() const;
        long comptaEdatNacionalitat(int anyNaixement, int codiNacionalitat) const;
        list<string> obtenirEstudis(int edat, int codiNacionalitat) const;
        map<int, long> obtenirSeccioHabitants() const;
        double calcularNivellEstudis() const;

    private:
        map<int, list<Persona>> habitants;
        int anyPadro;
        list<Nacionalitat> nacionalitats;

};

#endif // DISTRICTE_H
