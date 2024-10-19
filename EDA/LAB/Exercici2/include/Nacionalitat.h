#ifndef NACIONALITAT_H
#define NACIONALITAT_H


#include <string>

using namespace std;

class Nacionalitat
{
    public:
        Nacionalitat(int id, string nom);
        int obtenirId() const;
        string obtenirNom() const;
        bool operator==(const Nacionalitat &nacio) const;

    private:
        int id;
        string nom;
};

#endif // NACIONALITAT_H
