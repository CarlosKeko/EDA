// Jer�nimo Hern�ndez Gonz�lez
// Exercici 3 - Laboratoris EDA 24/25

#include <iostream>
#include <fstream>
#include "GrafEtiquetat.h"
#include "Districte.h"
#include <limits>

/// @mainpage Programa que llegeix un graf d'un mapa i el coloreja.

using namespace std;

// Llegeix un graf (no dirigit) que representa un mapa
// on les arestes representen fronteres en com� i la
// respectiva etiqueta �s la llargada de la frontera.
// El nomFitxer �s el path del fitxer a on es troba la
// descripci� TFG del graf
// graf �s un objecte GrafEtiquetat inicialitzat com
// no dirigit
void llegirGraf(const string& nomFitxer, GrafEtiquetat &graf);

int main()
{
   string nomFitxer;
   GrafEtiquetat graf(false);

   cerr << "Fitxer amb el graf de la ciutat: "<<endl;
   cin >> nomFitxer;
   cin.ignore(numeric_limits<streamsize>::max(),'\n');

   try {
      llegirGraf(nomFitxer, graf);
      //graf.colorejaGraf();
      cout << "*************** Graf colorejat ***************" << endl;
      cout << graf;
   }
   catch (const char* missatge) {
      cerr << "[ERROR] " << missatge << endl;
   }
}

void llegirGraf(const string& nomFitxer, GrafEtiquetat& graf)
{
   ifstream fitxer(nomFitxer, ifstream::in);

   if (not fitxer.fail()) {
      int id, numSec;
      string aux, nom="";
      fitxer >> aux;
      while (aux != "#"){
         id = stoi(aux);
         fitxer >> nom >> numSec;

         Districte dist(nom,"indeterminat",numSec);
         graf.afegirVertex(dist);
         fitxer >> aux;
      }

      int v1, v2;
      double etiqueta;
      while (!fitxer.eof()){ // final fitxer
         fitxer >> v1 >> v2 >> etiqueta;
         graf.afegirAresta(v1, v2, etiqueta);
      }
   }
   else {
      throw "llegirGraf: El fitxer '" + nomFitxer + "' no s'ha pogut obrir";
   }

   fitxer.close();
}
