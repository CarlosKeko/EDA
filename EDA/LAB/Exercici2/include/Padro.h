#ifndef PADRO_H
#define PADRO_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include "Districte.h"
#include "Estudi.h"
#include "Nacionalitat.h"
#include "Persona.h"
#include <iostream>
#include <utility>
#include "eines.h"

using namespace std;

class Padro {
public:
    //NUEVO
    Padro();

    //PRE: --
    //POST: --
    //RETORNA: Devuelve un entero con el total de lineas leido
    int llegirDades(const string &path);

    //PRE: --
    //POST: --
    //RETORNA: Devuelve si el año pasado por parametro esta en la ED del Padro
    bool existeixAny(int any) const;

    //PRE: --
    //POST: --
    //RETORNA: Devuelve un vector con la cantidad de personas en cada distrito indicado por el año pasado por parametro
    vector<long> obtenirNumHabitantsPerDistricte(int any) const;

    //PRE: --
    //POST: --
    //RETORNA: Devuelve un map la clave son los años y un vector de strings el cual trae los estudios de cada año
    map<int, list<string>> resumEstudis() const;

    //PRE: --
    //POST: --
    //RETORNA: Devuelve un mapa con el año y el nombre de estudios por distrito pasado por parametro.
    map<int,int> nombreEstudisDistricte(int districte) const;

    //PRE: --
    //POST: --
    //RETORNA: Devuelve un mapa con cada año, el valor de cada año devuelve un vector pair del nombre del distrito y la edad media
    map<int, vector<pair<string, double>>> resumEdat() const;

    //PRE: --
    //POST: --
    //REOTRNA:
    list<string> estudisEdat(int any, int districte, int edat, int codiNacionalitat) const;


    //int afegir(int any, int districte, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat);

    //ANTIGUO
    //vector<pair<string, double>> resumEdat() const;
    //list<string> resumEstudis() const;
    vector<pair<string, long>> edatNacioPerDistricte(int edat, int codiNacionalitat) const;
    vector<list<string>> diferentsNacionalitats(int districte1, int districte2) const;


private:
    //ANTIGUO
    vector<Districte> districtes;
    vector<string> nomDistricte;
    int anyPadro;


    //NUEVO
    map<int, vector<Districte>> padroAny;

    //METODOS
    int stringToInt(string s);
    vector<pair<string, double>> algoritmoBurbuja(vector<pair<string, double>> vectorUsado) const;

};

#endif //PADRO_H
