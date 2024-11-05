#include <string>
#include "Districte.h"

Districte::Districte(string nom, string color, int numSeccions): _nom(nom), _color(color), _nseccions(numSeccions) { }

string Districte::obtenirColor() const{
   return _color;
}

string Districte::obtenirNom() const{
   return _nom;
}

int Districte::obtenirNombreSeccions() const{
   return _nseccions;
}

