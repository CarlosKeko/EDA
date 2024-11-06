/**
@author Jer�nimo Hern�ndez Gonz�lez
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

   // Retorna si el graf �s dirigit o no
   bool esDirigit() const;
   // Retorna el nombre de v�rtexs
   int nVertexs() const;
   // Retorna el nombre d'arestes
   int nArestes() const;

   /** Comprova si existeix una aresta.
    si v1 o v2 no son v�lid, llen�a excepci�
    @pre v1 o v2 son indexos valids a dintre del rang
    @post aresta trobada o no...
    */
   bool existeixAresta(int v1, int v2) const;
   // Torna l'etiqueta d'una aresta.
   // si no hi ha aresta entre v1 i v2, llen�a excepci�
   Etiqueta etiquetaAresta(int v1, int v2);

   /** Afegeix un v�rtex amb el districte donat
    Torna un nombre (�ndex) donat al nou v�rtex*/
   int afegirVertex(const Districte& districte);

   // Afegeix una aresta amb l'etiqueta donada
   // entre els v�rtexs indicats. Si no son correctes,
   // llen�a excepci�
   void afegirAresta(int v1, int v2, const Etiqueta& e);
   // Esborra l'aresta entre v1 i v2
   // si no existeix l'aresta, llen�a excepci�
   void esborrarAresta(int v1, int v2);
   // Esborra el v�rtex
   // si no existeix, llen�a excepci�
   void esborrarVertex(int v);

   // Coloreja el graf
   // No implementada! Llen�a excepci� incondicional
   int coloreja();

   // Implementem l'operador << per a GrafEtiquetat
   friend ostream &operator<<(ostream &os, const GrafEtiquetat &g);

private:
   bool _dirigit; ///< Indica si el graf �s o no dirigit
   int _numArestes; ///< guarda el nombre d'arestes del graf
   Representacio _representacio; ///< representaci� del graf

   // Comprova si �s un �ndex v�lid per a un v�rtex
   // �s valid si est� entre 1 i el nombre total de
   // v�rtexs (ambdos inclosos)
   bool esValid(int v) const;

};

#endif //GRAF_H
