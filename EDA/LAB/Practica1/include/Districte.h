// Carlos José Urbina Romero
// u1980975
// Practica 1

/// @file Districte.h
/// @brief Clase Districte

#ifndef DISTRICTE_H
#define DISTRICTE_H


#include <string>
#include "Persona.h"
#include <vector>
#include <list>
#include <map>

using namespace std;

/**
    @class Districte
    @brief El distrito de los años

    En esta clase guardamos el dato del distrito con sus habitantes.
*/
class Districte
{
    public:
        /**
            @brief Constructor por defecto de la clase Districte.
            @pre --
            @post Se inicializa un objeto vacio.
        */
        Districte();

        /**
            @brief Metodo para añadir habitantes a una seccion del distrito.
            @pre La seccion y los datos personales son validos.
            @post Se añade un nuevo habitante a la seccion correspondiente.
        */
        void afegir(int seccio, int any, int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiNacionalitat, const string &nomNacionalitat);

        /**
            @brief Metodo para calcular el numero total de habitantes en el distrito.
            @pre El mapa habitants esta inicializado correctamente
            @post Devuelve el numero total de habitantes sumando todas las secciones
            @return Numero total de habitantes.
        */
        long obtenirNumHabitants() const;

        /**
            @brief Metodo para calcular la edad promedio de los habitantes del distrito.
            @pre El mapa habitants esta inicializado correctamente.
            @post Devuelve la edad promedio.
            @return Edad promedio de los habitantes.
        */
        double obtenirEdatMitjana() const;

        /**
            @brief Metodo para generar una lista de los estudios unicos en el distrito.
            @pre El mapa habitants esta inicializado correctamente.
            @post Devuelve una lista de estudios unicos.
            @return Lista de strings con los estudios no repetidos.
        */
        list<string> resumEstudis() const;

        /**
            @brief Metodo para obtener el numero de habitantes que cumplen con una edad y nacionalidad especificas.
            @pre El mapa habitants esta inicializado correctamente.
            @post Devuelve el numero de habitantes que cumplen con los requisitos.
            @param anyNaixmente entero positivo valido.
            @param codiNacionalitat entero positivo valido.
            @return long con el numero de habitantes.
        */
        long comptaEdatNacionalitat(int anyNaixement, int codiNacionalitat) const;

        /**
            @brief Metodo para obtener una lista de estudios de las personas que cumplan los requisitos de edad y codiNacionalitat.
            @pre El mapa habitants esta inicializado correctamente.
            @param edat entero positivo valido.
            @param codiNacionalitat entero positivo valido.
            @post Devuelve una lista de strings distintitos de la gente que cumplan los requisitos.
            @return lista de strings de los estudios.
        */
        list<string> obtenirEstudis(int edat, int codiNacionalitat) const;

        /**
            @brief Metodo para obtener por cada seccion el numero de habitantes.
            @pre El mapa habitants esta inicializado correctamente.
            @post Devuelve un mapa donde la clave seran las diferentes secciones y el valor el numero de habitantes.
            @return mapa con los habitantes por seccion
        */
        map<int, long> obtenirSeccioHabitants() const;

        /**
            @brief Metodo para obtener la media del nivel de los estudios de las personas de todas las secciones
            @pre El mapa habitants esta inicializado correctamente.
            @post Devuelve un double con la media de estudios de todos los habitantes
            @return Devuelve la media de estudios.
        */
        double calcularNivellEstudis() const;

        /**
            @brief Metodo para obtener el nombre de los paises y la cantidad de gente de la cual es cada una.
            @pre Habitants esta inicializada correctamente.
            @post Devuelve un mapa el cual la clave sera un string de cada pais y el valor sera la cantida de gente de ese pais
            @return Mapa de strings y longs con los paises y la gente en cada uno.
        */
        map<string, long> obtenirPaisos() const;

        /**
            @brief Metodo para obtener el numero de habitantes de codiNacionalitat pasado por parametro.
            @pre Habitantes esta inicializado correctamente.
            @param codiNacionalitat es un entero positivo valido.
            @post Devuelve el numero de habitantes a partir de un codigo.
            @return entero con el numero total de habitantes.
        */
        int obtenirNumHabitantsCodi(int codiNacionalitat) const;

        /**
            @brief Metodo para añadir el nombre al distrito.
            @pre nomDistricte existe.
            @post nomDistricte asignado correctamente.
        */
        void asignarNomDistricte(string nom);

        /**
            @brief Metodo para obtener el nombre del distrito.
            @pre nomDistricte esta inicializado correctamente.
            @post Devuelves un string con el nombre del distrito.
        */
        string obtenirNomDistricte() const;

        /**
            @brief Metodo para contar las personas en el distrito entre 20 y 30 años.
            @pre habitants esta inicializado correctamente.
            @post Devuelve un long con la cantidad de gente que tiene entre 20 y 30 años.
            @return long con la cantidad de gente.
        */
        long numJoves() const;

    private:
        map<int, list<Persona>> habitants; ///< Mapa de enteros y lista de personas, donde la clave son las secciones y el valor sus habitantes
        int anyPadro; ///< Año que corresponde del padro el distrito.
        string nomDistricte; ///< Nombre del distrito.

};

#endif // DISTRICTE_H
