#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include "Nacionalitat.h"
#include "Estudi.h"

using namespace std;

class Persona
{
    public:
        Persona(int codiNivellEstudis, const string &nivellEstudis, int anyNaixement, int codiPaisNaixement, const string &paisNaixement);
        int obtenirAnyNaixement() const;
        string obtenirNivellEstudis() const;
        int obtenirCodiPaisNaixement() const;
        int obtenirCodiNivellEstudis() const;

    private:
        int codiNivellEstudis;
        string nivellEstudis;
        int anyNaixement;
        int codiPaisNaixement;
        string paisNaixement;
};


#endif // PERSONA_H
