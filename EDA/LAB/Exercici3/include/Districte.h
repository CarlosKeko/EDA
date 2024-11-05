// Jerónimo Hernández González
// Exercici 3 - Laboratoris EDA 24/25

#ifndef DISTRICTE_H
#define DISTRICTE_H

#include <string>

using namespace std;

/*
 Classe Districte
 Guarda dades bàsiques d'un districte
 */
class Districte
{
public:
   // Constructor amb tots els paràmetres
   Districte(string nom, string color, int numSeccions);
   // Retorna el nom
   string obtenirNom() const;
   // Retorna el color
   string obtenirColor() const;
   // Retorna el nombre de seccions del districte
   int obtenirNombreSeccions() const;

private:
   string _nom;
   string _color;
   int _nseccions;
};

#endif // DISTRICTE_H
