#ifndef SOLUCIO_H
#define SOLUCIO_H

#include "Assignatura.h"
#include <list>
#include <algorithm>
#include <map>
#include "Candidats.h"
#include <vector>
#include <iostream>

/**
 * @class Solucio
 * @brief Classe que representa una solució per assignar exàmens.
 */
class Solucio
{

    public:
        /**
         * @brief Constructor per defecte de Solucio.
         */
        Solucio (){}

        /**
         * @brief Constructor que inicialitza una solució amb assignatures i restriccions.
         * @param assignatures Llista d'assignatures pendents.
         * @param restriccions Mapa de restriccions entre assignatures.
         * @param diesMaxim Nombre màxim de dies disponibles.
         * @param aulaGran Nombre d'aules de gran capacitat.
         * @param aulaReduida Nombre d'aules de capacitat reduïda.
         */
        Solucio(list<Assignatura> assignatures, map<string, list<string>> restriccions, int diesMaxim, int aulaGran, int aulaReduida);

        /**
         * @brief Crea un conjunt de candidats per a la solució actual.
         * @return Un objecte Candidats que representa les opcions possibles.
         */
        Candidats inicialitzarCandidats () const ;

        /**
         * @brief Determina si el candidat actual és acceptable en la solució actual.
         * @param candidats Conjunt de candidats disponibles.
         * @return True si el candidat actual és acceptable, false en cas contrari.
         */
        bool acceptable (const Candidats & candidats) ;

        /**
         * @brief Afegeix el candidat actual a la solució.
         * @param candidat Candidat a afegir.
         */
        void anotar (const Candidats& candidat);

        /**
         * @brief Elimina el candidat actual de la solució.
         * @param candidats Candidat a eliminar.
         */
        void desanotar (const Candidats & candidats);

        /**
         * @brief Determina si la solució actual està completa.
         * @return True si la solució és completa, false en cas contrari.
         */
        bool completa () const ;

        /**
         * @brief Obtenim el vector amb les assignatures per torns.
         * @return Un vector de llistes d'assignatures per torns.
         */
        vector<list<Assignatura>> getRes();

    private:
        list<Assignatura> assignaturesPendents; ///< Llista d'assignatures pendents.
        map<string, list<string>> restriccions; ///< Mapa de restriccions entre assignatures.
        int nivell; ///< Nivell actual de la solució.
        int aulagran; ///< Nombre d'aules de gran capacitat disponibles.
        int aulareduida; ///< Nombre d'aules de capacitat reduïda disponibles.
        int diesmaxim; ///< Nombre màxim de dies disponibles per als exàmens.
        vector<list<Assignatura>> res; ///< Resultat de la solució, assignatures per torns.
        vector<pair<int, int>> disponibilitat; ///< Disponibilitat d'aules per torn.

};

#endif // SOLUCIO_H
