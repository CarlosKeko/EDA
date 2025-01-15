#ifndef ASSIGNATURA_H
#define ASSIGNATURA_H

#include <string>

using namespace std;

/**
 * @class Assignatura
 * @brief Classe que representa una assignatura amb les seves caracter�stiques.
 */
class Assignatura
{
    public:
        /**
         * @brief Constructor per defecte de Assignatura.
         */
        Assignatura() {}

        /**
         * @brief Constructor que inicialitza una assignatura amb els seus atributs.
         * @param grau Nom del grau al qual pertany l'assignatura.
         * @param assignatura Nom de l'assignatura.
         * @param codi Codi identificador de l'assignatura.
         * @param tipus Tipus d'assignatura ('g' per grup gran, 'r' per grup redu�t).
         * @param credits Nombre de cr�dits de l'assignatura.
         * @param semestre Semestre al qual pertany l'assignatura.
         * @param curs Curs acad�mic al qual pertany l'assignatura.
         */
        Assignatura(string grau, string assignatura, string codi, char tipus, double credits, int semestre, int curs);

        /**
         * @brief Obtenim el grau de l'assignatura.
         * @return Nom del grau.
         */
        string getGrau() const;

        /**
         * @brief Obtenim el nom de l'assignatura.
         * @return Nom de l'assignatura.
         */
        string getAssignatura() const;

        /**
         * @brief Obtenim el codi de l'assignatura.
         * @return Codi de l'assignatura.
         */
        string getCodi() const;

        /**
         * @brief Obtenim el tipus de l'assignatura.
         * @return Tipus de l'assignatura ('g' o 'r').
         */
        char getTipus() const;

        /**
         * @brief Obtenim el nombre de cr�dits de l'assignatura.
         * @return Nombre de cr�dits.
         */
        double getCredits() const;

        /**
         * @brief Obtenim el semestre al qual pertany l'assignatura.
         * @return Semestre de l'assignatura.
         */
        int getSemestre() const;

        /**
         * @brief Obtenim el curs acad�mic al qual pertany l'assignatura.
         * @return Curs acad�mic.
         */
        int getCurs() const;

        /**
         * @brief Operador d'igualtat per comparar assignatures.
         * @param a2 Assignatura amb la qual es compara.
         * @return True si les dues assignatures tenen el mateix codi, false en cas contrari.
         */
        bool operator==(const Assignatura &a2) const;

        /**
         * @brief Operador de comparaci� per determinar l'ordre entre assignatures.
         * @param a2 Assignatura amb la qual es compara.
         * @return True si l'assignatura actual �s menor que a2, false en cas contrari.
         */
        bool operator<(const Assignatura &a2) const;

    private:
        string grau; ///< Nom del grau.
        string assignatura; ///< Nom de l'assignatura.
        string codi; ///< Codi identificador de l'assignatura.
        char tipus; ///< Tipus d'assignatura ('g' o 'r').
        double credits; ///< Nombre de cr�dits de l'assignatura.
        int semestre; ///< Semestre de l'assignatura.
        int curs; ///< Curs acad�mic de l'assignatura.

};

#endif // ASSIGNATURA_H
