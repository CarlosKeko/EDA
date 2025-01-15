#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H

#include "Solucio.h"
#include "Candidats.h"
#include <string>
#include <iostream>

/**
 * @class Solucionador
 * @brief Classe intermedia que gestiona la interacció entre solucions i candidats utilitzant algoritmes de backtracking.
 */
class Solucionador
{
    public:
        /**
         * @brief Constructor que determina el tipus de solució.
         * @param tipus Tipus d'algorisme de solució a utilitzar.
         */
        Solucionador (int tipus);

        /**
         * @brief Retorna la solució actual guardada.
         * @return Un objecte de tipus Solucio amb l'estat actual de la solució.
         */
        Solucio obtenirSolucio () const;

        /**
         * @brief Inicialitza la solució i executa l'algorisme de backtracking.
         * @param assignatures Llista d'assignatures pendents de processar.
         * @param restriccions Mapa de restriccions entre assignatures.
         * @param diesMaxim Nombre màxim de dies disponibles per als exàmens.
         * @param aulaGran Nombre d'aules de gran capacitat disponibles.
         * @param aulaReduida Nombre d'aules de capacitat reduïda disponibles.
         * @return True si es troba una solució vàlida, false en cas contrari.
         */
        bool solucionar (list<Assignatura> &assignatures, map<string, list<string>> &restriccions, int diesMaxim, int aulaGran, int aulaReduida);

    private:
        Solucio solucioActual; ///< Solució actual en procés.
        Solucio millorSolucio; ///< Millor solució trobada fins al moment.
        bool trobat; ///< Indica si s'ha trobat una solució completa.

        /**
         * @brief Implementa l'esquema recursiu del backtracking.
         * Pot haver-hi una variant per a cada tipus d'algorisme.
         */
        void backtracking ();

};

#endif // SOLUCIONADOR_H
