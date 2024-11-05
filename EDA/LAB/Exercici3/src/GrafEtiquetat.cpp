// Jerónimo Hernández González
// Exercici 3 - Laboratoris EDA 24/25


#include <iostream>
#include <limits>
#include "GrafEtiquetat.h"
#include "Districte.h"
#include <utility>

GrafEtiquetat::GrafEtiquetat(bool dirigit) : _dirigit(dirigit)
{
   _numArestes = 0;
}

bool GrafEtiquetat::esDirigit() const
{
   return _dirigit;
}

int GrafEtiquetat::nVertexs() const
{
   return _representacio.size();
}

int GrafEtiquetat::nArestes() const
{
   return _numArestes;
}

bool GrafEtiquetat::existeixAresta(int v1, int v2) const
{
   bool existeix = false;

   if (esValid(v1) and esValid(v2)) {
      v1--; v2--;
      // ... AQUI FALTA CODI ...
   }

   return existeix;
}

Etiqueta GrafEtiquetat::etiquetaAresta(int v1, int v2)
{
   Etiqueta e;

   if (existeixAresta(v1, v2)) {
      v1--; v2--;
      // ... AQUI FALTA CODI ...
   }
   else throw "GrafEtiquetat::etiquetaAresta: L'aresta que es vol consultar no existeix";

   return e;
}

int GrafEtiquetat::afegirVertex(const Districte& districte)
{
   throw "GrafEtiquetat::afegirAresta: Sense completar";

   pair<bool, Etiqueta> relaciones;
   relaciones.first = false;
   relaciones.second = 0;

   vector<pair<bool, Etiqueta>> numRelacions(nVertexs() + 1, relaciones);

   pair<Districte, vector<pair<bool, Etiqueta>>> pairDistritos;
   pairDistritos.first = districte;
   pairDistritos.second = numRelacions;

   Representacio.push_back(pairDistritos);
}

void GrafEtiquetat::afegirAresta(int v1, int v2, const Etiqueta& e)
{
   throw "GrafEtiquetat::afegirAresta: Sense completar";
   if (esValid(v1) and esValid(v2)) {
      v1--; v2--;
      // ... AQUI FALTA CODI ...
      _numArestes++;
      if (not _dirigit) {
         // ... AQUI FALTA CODI ...
         _numArestes++;
      }
   }
   else throw "GrafEtiquetat::afegirAresta: Algun dels vèrtexs no és vàlid";
}

void GrafEtiquetat::esborrarAresta(int v1, int v2)
{
   if (existeixAresta(v1, v2)) {
      v1--; v2--;
      // ... AQUI FALTA CODI ...
      _numArestes--;
      if (not _dirigit) {
         // ... AQUI FALTA CODI ...
         _numArestes--;
      }
   }
   else throw "GrafEtiquetat::esborrarAresta: L'aresta que es vol esborrar no existeix";
}

void GrafEtiquetat::esborrarVertex(int v)
{
   if (esValid(v)){
      v--;
      // ... AQUI FALTA CODI ...
   }
   else throw "GrafEtiquetat::esborrarVertex: El vèrtex no existeix";
}

bool GrafEtiquetat::esValid(int v) const {
   return v >= 1 and v <= _representacio.size();
}

ostream &operator<<(ostream &os, const GrafEtiquetat &g){
   os << "Vèrtexs:" << endl;
   throw "GrafEtiquetat: Sobrecàrrega operador << sense completar";

   // ... AQUI FALTA CODI ...

   os << endl << "Arestes:" << endl;

   // ... AQUI FALTA CODI ...

   return os;
}


int GrafEtiquetat::coloreja() {
   throw "GrafEtiquetat::coloreja: No implementat";
}
