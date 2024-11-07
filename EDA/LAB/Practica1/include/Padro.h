// Carlos Jos� Urbina Romero
// u1980975
// Practica 1

/// @file Padro.h
/// @brief Clase Padro

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

typedef map<int, list<string>> ResumEstudis; ///< Mapa para guardar los a�os y estudios de cada uno.
typedef map<int, vector<pair<string, double>>> ResumEdats; ///< Mapa para guardar los a�os y la media de edades por cada distrito y a�o.
typedef int ResumNivellEstudis; //Falta asignar tipus
typedef int ResumNacionalitats; //Falta asignar tipus

/**
    @class Padro
    @brief El padro de los diferentes distritos y a�os

    En esta clase guardamos los datos del padro con los diferentes a�os y distritos.
*/
class Padro {
public:
    /// @brief Constructor el cual no utilizamos para nada en el programa.
    Padro() {}

    /**
        @brief Metodo para leer los datos con ifstream y a�adirlo a la estructura de datos.
        @pre El path debe existir, el archivo csv debe tener un formato valido.
        @post Se agregan los datos de cada linea a la estructura de datos en la posicion correspondiente de a�o y distrito.
        @param path La ruta del archivo.
        @return El numero de lineas leidas del archivo.
    */
    int llegirDades(const string &path);

    /**
        @brief Metodo para comprobar si el a�o pasado por parametro existe dentro de la estructura de datos
        @pre El valor de any debe ser positivo, la estructura de datos debe estar inicializada
        @post Devuelve true si el a�o existe en la estructura de datos, false si no.
        @param any El a�o que se debe comprobar.
        @return true si el a�o existe, false al contrario.
    */
    bool existeixAny(int any) const;

    /**
        @brief Metodo para obtener el numero total de habitantes por a�o, juntando los distritos.
        @pre La estructura debe esta inicializada y tener los datos necesarios asignados.
        @post Devuelve un mapa donde la clave es cada a�o y el valor sus habitantes, el valor de cada a�o es la suma de los habitantes de todos los distritos de ese a�o.
        @return Mapa con clave a�os y habitantes como valor.
    */
    map<int, long> obtenirNumHabitantsPerAny() const;


    vector<long> obtenirNumHabitantsPerDistricte(int any) const;
    map<int, long> obtenirNumHabitantsPerSeccio(int any, int districte) const;

    ResumEstudis resumEstudis() const; ///Hecho faltar comentar

    map<int,int> nombreEstudisDistricte(int districte) const;
    ResumNivellEstudis resumNivellEstudis() const;
    ResumNacionalitats resumNacionalitats() const;
    map<int,string> movimentsComunitat(int codiNacionalitat) const;

    ResumEdats resumEdat() const; ///Hecho faltar comentar

    map<int, string> movimentVells() const;
    pair<string,long> mesJoves(int anyInicial, int anyFinal) const;
    list<string> estudisEdat(int any, int districte, int edat, int codiNacionalitat) const;

private:
    map<int, vector<Districte>> padroAny;
    vector<string> nomDistricte;

    //METODOS PRIVADOS
    int stringToInt(string s);
    void asignarDistritos();
    vector<pair<string, double>> algoritmoBurbuja(vector<pair<string, double>> vectorUsado) const;

};

#endif // PADRO_H
