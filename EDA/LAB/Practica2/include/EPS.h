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
#include "Solucio.h"
#include "Solucionador.h"

/**
 * @class EPS
 * @brief Classe que gestiona les dades i m�todes relacionats amb l'organitzaci� d'ex�mens.
 */
class EPS
{
    public:
        /**
         * @brief Constructor per defecte de EPS.
         */
        EPS(){}

        /**
         * @brief Constructor parametritzat de EPS.
         * @param aulagran Nombre d'aules de gran capacitat.
         * @param aulareduida Nombre d'aules de capacitat redu�da.
         * @param semestre Semestre per al qual es vol fer l'assignaci�.
         * @param diesMaxim Nombre m�xim de dies per als ex�mens.
         */
        EPS(int aulagran, int aulareduida, int semestre, int diesMaxim);

        /**
         * @brief Llegeix les dades de les assignatures des d'un fitxer.
         * @param path Ruta del fitxer de dades.
         * @return Un parell amb el nombre d'assignatures llegides i el nombre de graus diferents trobats.
         */
        pair<int, int> llegirDades(const string& path);

        /**
         * @brief Genera els torns d'ex�mens utilitzant un algorisme voraz.
         * @return Un mapa amb els torns generats.
         */
        map<string, list<Assignatura>> ferTorns() const;

        /**
         * @brief Calcula el nombre de torns necessaris per a l'assignaci�.
         * @return El nombre de torns necessaris.
         */
        int calcularTurnos() const;

        /**
         * @brief Executa l'algorisme de backtracking per assignar ex�mens.
         * @param tipus Tipus d'algorisme de backtracking.
         * @return Un vector amb les llistes d'assignatures per torns.
         */
        vector<list<Assignatura>> executarBacktracking(int tipus);

    private:
        list<Assignatura> assignatures; ///< Llista d'assignatures llegides.
        map<string, list<string>> restricciones; ///< Restriccions entre assignatures.
        int aulagran; ///< Nombre d'aules de gran capacitat.
        int aulareduida; ///< Nombre d'aules de capacitat redu�da.
        int semestre; ///< Semestre de treball.
        int diesMaxim; ///< Nombre m�xim de dies per als ex�mens.

        /**
         * @brief Redondeja un nombre cap amunt.
         * @param a Dividend.
         * @param b Divisor.
         * @return El resultat del redondeig cap amunt.
         */
        int redondeaArriba(int a, int b) const;

        /**
         * @brief Converteix una cadena de text a enter.
         * @param s Cadena de text a convertir.
         * @pre La cadena nom�s ha de contenir d�gits.
         * @return Un enter corresponent a la cadena, o -1 si no �s v�lida.
         */
        int stringToInt(string s);

        /**
         * @brief Compara dues assignatures pel seu tipus.
         * @param a1 Primera assignatura.
         * @param a2 Segona assignatura.
         * @return True si el tipus d'a1 �s menor que el tipus d'a2.
         */
        static bool compararTipus(const Assignatura &a1, const Assignatura &a2);

        /**
         * @brief Afegeix una restricci� basada en el codi d'una assignatura.
         * @param a1 Codi de l'assignatura per afegir una restricci�.
         */
        void afegirRestriccio(string a1);

        /**
         * @brief Afegeix una restricci� entre dues assignatures.
         * @param c1 Codi de la primera assignatura.
         * @param c2 Codi de la segona assignatura.
         */
        void afegirRestriccio(string c1, string c2);

        /**
         * @brief Busca una assignatura pel seu codi.
         * @param c Codi de l'assignatura a buscar.
         * @return L'assignatura corresponent al codi.
         */
        Assignatura buscarAssignatura(string c);

        /**
         * @brief Determina si es pot afegir una assignatura a un torn.
         * @param c Codi de l'assignatura.
         * @param assignaturesVigilar Llista d'assignatures al torn actual.
         * @return True si es pot afegir l'assignatura, false en cas contrari.
         */
        bool esPotAfegir(string c, const list<Assignatura> &assignaturesVigilar) const;

};

#endif // EPS_H
