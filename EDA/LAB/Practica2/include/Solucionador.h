#ifndef SOLUCIONADOR_H
#define SOLUCIONADOR_H

#include "Solucio.h"
#include "Candidats.h"
#include <string>
#include <iostream>

/**
 * @class Solucionador
 * @brief Classe intermedia que gestiona la interacci� entre solucions i candidats utilitzant algoritmes de backtracking.
 */
class Solucionador
{
    public:
        /**
         * @brief Constructor que determina el tipus de soluci�.
         * @param tipus Tipus d'algorisme de soluci� a utilitzar.
         */
        Solucionador (int tipus);

        /**
         * @brief Retorna la soluci� actual guardada.
         * @return Un objecte de tipus Solucio amb l'estat actual de la soluci�.
         */
        Solucio obtenirSolucio () const;

        /**
         * @brief Inicialitza la soluci� i executa l'algorisme de backtracking.
         * @param assignatures Llista d'assignatures pendents de processar.
         * @param restriccions Mapa de restriccions entre assignatures.
         * @param diesMaxim Nombre m�xim de dies disponibles per als ex�mens.
         * @param aulaGran Nombre d'aules de gran capacitat disponibles.
         * @param aulaReduida Nombre d'aules de capacitat redu�da disponibles.
         * @return True si es troba una soluci� v�lida, false en cas contrari.
         */
        bool solucionar (list<Assignatura> &assignatures, map<string, list<string>> &restriccions, int diesMaxim, int aulaGran, int aulaReduida);

    private:
        Solucio solucioActual; ///< Soluci� actual en proc�s.
        Solucio millorSolucio; ///< Millor soluci� trobada fins al moment.
        bool trobat; ///< Indica si s'ha trobat una soluci� completa.

        /**
         * @brief Implementa l'esquema recursiu del backtracking.
         * Pot haver-hi una variant per a cada tipus d'algorisme.
         */
        void backtracking ();

};

#endif // SOLUCIONADOR_H
