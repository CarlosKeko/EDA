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
   //throw "GrafEtiquetat::afegirAresta: Sense completar";

   pair<bool, Etiqueta> relaciones(false, 0);
   for (pair<Districte, vector<pair<bool, Etiqueta>>> &itU : _representacio) {
       itU.second.push_back(relaciones);
   }

   vector<pair<bool, Etiqueta>> numRelacions(nVertexs() + 1, relaciones);
   pair<Districte, vector<pair<bool, Etiqueta>>> pairDistritos(districte, numRelacions);
   _representacio.push_back(pairDistritos);
   return nVertexs();

}

void GrafEtiquetat::afegirAresta(int v1, int v2, const Etiqueta& e)
{
   //throw "GrafEtiquetat::afegirAresta: Sense completar";
   if (esValid(v1) and esValid(v2)) {
      v1--; v2--;
      pair<bool, Etiqueta> conexion(true, e);
      _representacio[v1].second[v2] = conexion;

      _numArestes++;

      if (not _dirigit) {
         _representacio[v2].second[v1] = conexion;
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
   //throw "GrafEtiquetat: Sobrecàrrega operador << sense completar";
   int numVector = 0;
   int altreVector = 0;

   os << "Vèrtexs:" << endl;
   for (pair<Districte, vector<pair<bool, Etiqueta>>> itU : g._representacio) {
        numVector++;
        cout << numVector << ", " << itU.first.obtenirNom() << ": color " << itU.first.obtenirColor() << endl;

   }

   os << endl << "Arestes:" << endl;
   numVector = 0;

   for (pair<Districte, vector<pair<bool, Etiqueta>>> itU : g._representacio) {
        numVector++;
        altreVector = 0;
        for (pair<bool, Etiqueta> itDos : itU.second) {
            altreVector++;
            if (itDos.first) {
                cout << numVector << "-" << altreVector << ": " << itDos.second << endl;
            }

        }

   }


   return os;
}


int GrafEtiquetat::coloreja() {
   throw "GrafEtiquetat::coloreja: No implementat";
}
