/**
@author Jerónimo Hernández González
@brief Exercici 3 - Laboratoris EDA 24/25
Descripcion larga.
*/

#ifndef GRAF_H
#define GRAF_H

#include <vector>
#include <map>
#include <list>
#include <string>
#include "Districte.h"
#include <utility>

using namespace std;

/// Definim el tipus de dada darrera de "Etiqueta"
typedef double Etiqueta;
/// Definim el tipus de dada darrera de "Representacio"
typedef vector<pair<Districte, vector<pair<bool, Etiqueta>>>> Representacio;

/**
 @class GrafEtiquetat
 Guarda un graf etiquetat
 */
class GrafEtiquetat
{
public:
   /// Constructor per defecte (graf no dirigit)
   GrafEtiquetat(bool dirigit = false);

   // Retorna si el graf és dirigit o no
   bool esDirigit() const;
   // Retorna el nombre de vèrtexs
   int nVertexs() const;
   // Retorna el nombre d'arestes
   int nArestes() const;

   /** Comprova si existeix una aresta.
    si v1 o v2 no son vàlid, llença excepció
    @pre v1 o v2 son indexos valids a dintre del rang
    @post aresta trobada o no...
    */
   bool existeixAresta(int v1, int v2) const;
   // Torna l'etiqueta d'una aresta.
   // si no hi ha aresta entre v1 i v2, llença excepció
   Etiqueta etiquetaAresta(int v1, int v2);

   /** Afegeix un vèrtex amb el districte donat
    Torna un nombre (índex) donat al nou vèrtex*/
   int afegirVertex(const Districte& districte);

   // Afegeix una aresta amb l'etiqueta donada
   // entre els vèrtexs indicats. Si no son correctes,
   // llença excepció
   void afegirAresta(int v1, int v2, const Etiqueta& e);
   // Esborra l'aresta entre v1 i v2
   // si no existeix l'aresta, llença excepció
   void esborrarAresta(int v1, int v2);
   // Esborra el vèrtex
   // si no existeix, llença excepció
   void esborrarVertex(int v);

   // Coloreja el graf
   // No implementada! Llença excepció incondicional
   int coloreja();

   // Implementem l'operador << per a GrafEtiquetat
   friend ostream &operator<<(ostream &os, const GrafEtiquetat &g);

private:
   bool _dirigit; ///< Indica si el graf és o no dirigit
   int _numArestes; ///< guarda el nombre d'arestes del graf
   Representacio _representacio; ///< representació del graf

   // Comprova si és un índex vàlid per a un vèrtex
   // És valid si està entre 1 i el nombre total de
   // vèrtexs (ambdos inclosos)
   bool esValid(int v) const;

};

#endif //GRAF_H
