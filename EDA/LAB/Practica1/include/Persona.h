// Carlos José Urbina Romero
// u1980975
// Practica 1

/// @file Persona.h
/// @brief Clase Persona


#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;


/**
    @class Persona
    @brief La informacion de la persona

    En esta clase guardamos los datos de la persona.
*/
class Persona
{
    public:
        /**
            @brief Constructor que recibe los parametros de las variables de la clase y los asigna.
            @pre Todas las variables inicializadas correctamente.
            @post Crea el objeto Persona.
        */
        Persona(int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiPaisNaixement, const string &paisNaixement);

        /**
            @brief Metodo para obtener anyNaixement
            @pre anyNaixemente inicializada correctamente
            @post devuelve anyNaixement
        */
        int obtenirAnyNaixement() const;

        /**
            @brief Metodo para obtener nivellEstudis
            @pre nivellEstudis inicializadaa correctamente
            @post devuelve nivellEstudis
        */
        string obtenirNivellEstudis() const;

        /**
            @brief Metodo para obtener codiPaisNaixement
            @pre codiPaisNaixement inicializada correctamente.
            @post devuelve codiPaisNaixement.
        */
        int obtenirCodiPaisNaixement() const;

        /**
            @brief Metodo para obtener codiNivellEstudis.
            @pre codiNivellEstudis inicializada correctamente.
            @post devuelve codiNivellEstudis
        */
        int obtenirCodiNivellEstudis() const;

        /**
            @brief Metodo para obtener nivellCodiPais
            @pre nivellCodiPais inicializada correctamente.
            @post devuelve nivellCodiPais
        */
        string obtenirNivellCodiPais() const;

    private:
        int codiNivellEstudis; ///< Entero con el nivel de estudios.
        string nivellEstudis; ///< String con el nombre de los estudios.
        int anyNaixement; ///< Entero con el año de nacimiento.
        int codiPaisNaixement; ///< Entero con el codigo de pais.
        string paisNaixement; ///< String con el pais de nacimiento.

};


#endif // PERSONA_H
