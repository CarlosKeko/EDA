#ifndef ASSIGNATURA_H
#define ASSIGNATURA_H

#include <string>

using namespace std;

class Assignatura
{
    public:
        /**
            @brief
            @pre
            @post
            @return
        */
        Assignatura() {}

        /**
            @brief
            @pre
            @post
            @return
        */
        Assignatura(string grau, string assignatura, string codi, char tipus, double credits, int semestre, int curs);

        //GETTERS Y SETTERS

        /**
            @brief
            @pre
            @post
            @return
        */
        string getGrau() const;

        /**
            @brief
            @pre
            @post
            @return
        */
        string getAssignatura() const;

        /**
            @brief
            @pre
            @post
            @return
        */
        string getCodi() const;

        /**
            @brief
            @pre
            @post
            @return
        */
        char getTipus() const;

        /**
            @brief
            @pre
            @post
            @return
        */
        double getCredits() const;

        /**
            @brief
            @pre
            @post
            @return
        */
        int getSemestre() const;

        /**
            @brief
            @pre
            @post
            @return
        */
        int getCurs() const;

    private:
        string grau, assignatura, codi;
        char tipus;
        double credits;
        int semestre, curs;


};

#endif // ASSIGNATURA_H
