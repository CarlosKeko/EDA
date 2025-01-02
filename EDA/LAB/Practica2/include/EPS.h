#ifndef EPS_H
#define EPS_H

#include "Assignatura.h"
#include <string>
#include <map>
#include <list>
#include <iostream>
#include "eines.h"
#include <fstream>
#include <utility>
#include <set>

class EPS
{
    public:
        EPS(){}

        EPS(int aulagran, int aulareduida);

        pair<int, int> llegirDades(const string& path);

        map<string, list<Assignatura>> ferTorns() const;

        int calcularTurnos() const;

    private:
        list<Assignatura> assignatures;
        int aulagran, aulareduida;

        //PRIVATE
        int redondeaArriba(int a, int b) const;

        /**
            @brief Metodo que convierte una cadena de string en int
            @pre Si la cadena s no esta vacia debe contener caracteres del 0 al 9
            @post Devuelve un numero entero si la cadena tiene valores validos, si no devuelve -1
            @param Cadena la cual debemos convertir
            @return Numero entero convertido a partir de s o -1 si no es valido.
        */
        int stringToInt(string s);
};

#endif // EPS_H
