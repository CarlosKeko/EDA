#ifndef CANDIDATS_H
#define CANDIDATS_H

#include "Assignatura.h"
#include <list>
#include <iostream>

/**
 * @class Candidats
 * @brief Classe que representa un conjunt de candidats per a la selecció.
 */
class Candidats
{
    public:
        /**
         * @brief Constructor per defecte de Candidats.
         */
        Candidats() {}

        /**
         * @brief Constructor que inicialitza els candidats amb una llista d'assignatures.
         * @param elements Llista d'assignatures que representen els candidats.
         */
        Candidats(const list<Assignatura> &elements);

        /**
         * @brief Obté el candidat actual.
         * @pre L'iterador no ha d'estar al final de la llista.
         * @return L'assignatura actual del conjunt de candidats.
         * @throw runtime_error Si es crida quan l'iterador és al final de la llista.
         */
        Assignatura actual() const;

        /**
         * @brief Determina si s'ha arribat al final dels candidats.
         * @return True si no hi ha més candidats, false en cas contrari.
         */
        bool fi() const;

        /**
         * @brief Avança al següent candidat del conjunt.
         * @pre L'iterador no ha d'estar al final de la llista.
         */
        void seguent();

    private:
        list<Assignatura> elements; ///< Llista d'assignatures candidates.
        list<Assignatura>::const_iterator actualElement; ///< Iterador que apunta al candidat actual.

};

#endif // CANDIDATS_H
