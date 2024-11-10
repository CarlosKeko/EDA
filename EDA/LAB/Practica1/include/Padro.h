// Carlos José Urbina Romero
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

typedef map<int, list<string>> ResumEstudis; ///< Mapa para guardar los años y estudios de cada uno.
typedef map<int, vector<pair<string, double>>> ResumEdats; ///< Mapa para guardar los años y la media de edades por cada distrito y año.
typedef map<int, vector<pair<string, double>>> ResumNivellEstudis; ///< Mapa para guardar los años y el promedio de estudios de cada distrito y año.
typedef map<int, vector<pair<string, long>>> ResumNacionalitats; ///< Mapa para guardar los años y el nombre de cada nacionalidad con la cantidad de personas en cada.

/**
    @class Padro
    @brief El padro de los diferentes distritos y años

    En esta clase guardamos los datos del padro con los diferentes años y distritos.
*/
class Padro {
public:
    /// @brief Constructor el cual no utilizamos para nada en el programa.
    Padro() {}

    /**
        @brief Metodo para leer los datos con ifstream y añadirlo a la estructura de datos.
        @pre El path debe existir, el archivo csv debe tener un formato valido.
        @post Se agregan los datos de cada linea a la estructura de datos en la posicion correspondiente de año y distrito.
        @param path La ruta del archivo.
        @return El numero de lineas leidas del archivo.
    */
    int llegirDades(const string &path);

    /**
        @brief Metodo para comprobar si el año pasado por parametro existe dentro de la estructura de datos
        @pre El valor de any debe ser positivo, la estructura de datos debe estar inicializada
        @post Devuelve true si el año existe en la estructura de datos, false si no.
        @param any El año que se debe comprobar.
        @return true si el año existe, false al contrario.
    */
    bool existeixAny(int any) const;

    /**
        @brief Metodo para obtener el numero total de habitantes por año, juntando los distritos.
        @pre La estructura debe esta inicializada y tener los datos necesarios asignados.
        @post Devuelve un mapa donde la clave es cada año y el valor sus habitantes, el valor de cada año es la suma de los habitantes de todos los distritos de ese año.
        @return Mapa con clave años y habitantes como valor.
    */
    map<int, long> obtenirNumHabitantsPerAny() const;

    /**
        @brief Metodo para obtener el numero de habitantes de UN año, mostrando uno por uno la cantidad de personas por distrito.
        @pre El valor any debe ser un numero valido positivo.
        @post Devuelve un vector donde cada elemento correspone al numero de habitantes de un distrito, si no se encuentra el año, devuelve un vector vacio.
        @param any Año el cual se quiere obtener el numero de habitantes por distrito.
        @return Vector de longs, cada valor es el numero de habitantes.
    */
    vector<long> obtenirNumHabitantsPerDistricte(int any) const;

    /**
        @brief Metodo para obtener el numero de habitantes por seccion de un año y distrito especificados-
        @pre any y districte son variables validas introducidas por el usuario, si alguna de las dos no son validas, la funcion continuara pidiendolo hasta que las dos sean validas.
        @post Devuelve un mapa donde la clave es la seccion y el valor los habitantes. Si no existen devuelve un mapa vacio.
        @return map<int, long> Mapa donde las claves son las secciónes y los valores son el número de habitantes por sección.
    */
    map<int, long> obtenirNumHabitantsPerSeccio() const;

    /**
        @brief Metodo que nos devuelve los años y los estudios de cada año.
        @pre La variable padroAny contiene la informacion valida de años y estudios.
        @post Devuelve un map donde las claves son los años y los datos son una lista de string con los diferentes estudios unicos en orden inverso.
        @return map<int, list<string>> Un mapa que contiene los años y los estudios.
    */
    ResumEstudis resumEstudis() const;

    /**
        @brief Metodo que calcula el numero de estudios unicos en el distrito especificado por cada año.
        @pre districte Debe estar en un rango valido.
        @post Devuelve un mapa donde cada clave es el año y su valor es el numero de estudios en el distrito especificado para ese año.
        @param districte Numero del distrito el cual deseamos obtener los estudios
        @return map<int, int> Un mapa que contiene los años y los estudios unicos para cada año.
    */
    map<int,int> nombreEstudisDistricte(int districte) const;

    /**
        @brief Genera el promedio de los niveles de estudio por distrito y año, marcando el distrito con mayor y menor promedio con + y - respectivamente.
        @pre PadroAny debe estar inicializado.
        @post Devuelve un mapa donde cada clave es un año y el valor es un vector de pairs que contiene el nombre del distrito con el prefijo correspondiente y su respectivo promedio.
        @return map<int, vector<pair<string, double>>> Mapa que contiene los años y un vector de pairs con los distritos y el promedio.
    */
    ResumNivellEstudis resumNivellEstudis() const;

    /**
        @brief Metodo que va año por año recolectando las nacionalidades y calculando cuantas cantidad de personas hay de ellas
        @pre padroAny debe contener informacion de los años, distritos y nacionalidades
        @post Devuelve un mapa donde la clave seran los años, los valores seran vectores de pairs de strings y longs que estaran ordenadas descendentemente.
        @return map<int, vector<pair<string, long>>> Mapa que contiene los años y un vector de pairs con las nacionalides y la cantidad.
    */
    ResumNacionalitats resumNacionalitats() const;

    /**
        @brief Metodo para obtener el distrito con el mayor numero de habitantes de la nacionalidad pasada por parametro por cada año.
        @pre El codiNacionalitat tiene que ser un entero positivo y valido.
        @post Devuelve un mapa en el que las claves son los años y el valor es el nombre del distrito con el mayor numero de habitantes de la nacionalidad especificada. Si algun año no tiene habitantes el valor sera "No te habitants".
        @param codiNacionalitat Codigo de la nacionalidad a buscar.
        @return map<int,string> Mapa que cada año es la clave y el valor es un string con el nombre del distrito.
    */
    map<int,string> movimentsComunitat(int codiNacionalitat) const;

    ResumEdats resumEdat() const; ///Hecho faltar comentar

    map<int, string> movimentVells() const;
    pair<string,long> mesJoves(int anyInicial, int anyFinal) const;
    list<string> estudisEdat(int any, int districte, int edat, int codiNacionalitat) const; ///Hecho faltar comentar

private:
    map<int, vector<Districte>> padroAny;
    vector<string> nomDistricte;

    //METODOS PRIVADOS
    int stringToInt(string s);
    void asignarDistritos();
    vector<pair<string, double>> algoritmoBurbuja(vector<pair<string, double>> vectorUsado) const;

    /**

    */
    bool existeiyAny(int any) const;

    /**

    */
    bool existeixDistricte(int any, int districte) const;

};

#endif // PADRO_H
