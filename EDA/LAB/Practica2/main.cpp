// Creat per jhg
// Laboratoris EDA 24/25
// Exemple simple de gesti� dels par�metres d'entrada
// amb excepcions.

#include <iostream>
#include <string>
#include "EPS.h"
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

namespace excepcio {
    struct entradaIncorrecta {
       string missatge;
       entradaIncorrecta(string m) {missatge = m;}
    };

}

struct Parametres
{
   int nombreAulesPetites;
   int nombreAulesGran;
   int semestre;
   int diesMaxim;
   string nomFitxer;
   bool ajuda;
   bool cercaVoraz;
   bool millorSolucio;
   bool backtracking;

   Parametres()
   {
      nombreAulesGran = nombreAulesPetites = semestre = 1;
      nomFitxer = "";
      ajuda = false;
      millorSolucio = false;
      cercaVoraz = false;
      backtracking = true;
      diesMaxim = -1;

   }

};

void mostrarAjuda(char *);
Parametres processaParametres(int argn, char** argv);

int redondeaArriba(int a, int b) {
    return (a + b - 1) / b;
}

void mostrarTurnos(EPS &eps) {
    auto t1 = high_resolution_clock::now();
   map<string, list<Assignatura>> assignatures = eps.ferTorns();
    auto t2 = high_resolution_clock::now();

   for (map<string, list<Assignatura>>::const_iterator it = assignatures.begin(); it != assignatures.end(); it++) {
        cout << "\n*********************************" << endl;
        cout << "* " << it->first << "                   n=" << it->second.size() << "  *" << endl;
        cout << "*-------------------------------*" << endl;

        for ( list<Assignatura>::const_iterator itDos = it->second.begin(); itDos != it->second.end(); itDos++) {
            cout << "* " << setw(10) << left << itDos->getCodi() << " (tipus " << itDos->getTipus() << "), " << setw(5) << right << itDos->getGrau() << "-" << itDos->getCurs() << " *" << endl;

        }
        cout << "*********************************" << endl;

   }

    cout << "Num. torns:\t" << assignatures.size() << endl;
    cout << "Num. dies:\t" << redondeaArriba(assignatures.size(), 2) << endl;
    duration<double> duracio = duration_cast<duration<double>>(t2 - t1);
    cout << "Temps: " << fixed << setprecision(10) << duracio.count() << " segons" << endl;
}

int main(int argn, char** argv) {
   try {
      Parametres p = processaParametres(argn, argv);

      if (p.ajuda) {
         mostrarAjuda(argv[0]);

      } else {

         if (p.cercaVoraz) {
            EPS eps(p.nombreAulesGran, p.nombreAulesPetites);
            eps.llegirDades(p.nomFitxer);
            eps.ferTorns();
            //mostrarTurnos(eps);
         }

      }
   }
   catch (excepcio::entradaIncorrecta ex) {
      cerr << ex.missatge << endl << endl;
      //mostrarAjuda(argv[0]);
   }

   return(0);

}


Parametres processaParametres(int argn, char** argv) {
   Parametres p;
   bool error = false;

   if (argn < 2) {
      throw excepcio::entradaIncorrecta("Falten arguments (\"p2 -- help\" per ajuda)");

   }
   else {
      int nPar = 1;
      if (string(argv[nPar]) == "-h" || string(argv[nPar]) == "--help") {
         p.ajuda = true;
         return p;

      }

      while (!error and nPar < argn-1) { // processar opcions
         string par = string(argv[nPar]);
         if (par == "-v") {
            p.cercaVoraz = true;

         }else if (par == "-cr") {
            par = string(argv[++nPar]);

            if (par[0] >= '0' and par[0] <= '9') p.nombreAulesPetites = stoi(par);
            else error = true;

         }else if (par == "-gc") {
            par = string(argv[++nPar]);

            if (par[0] >= '0' and par[0] <= '9') p.nombreAulesGran = stoi(par);
            else error = true;

         }

        // else if (par == "-p") p.ferPrim = true;
         //else error = true;
         nPar++;
      }

      // Hem sortit del bucle perqu� el par�metre a la posici� nPar-1 �s una opci� err�nia (error==true)
      // o hem acabat el recorregut (encara hem de tractar l'�ltim par�metre, el nom del fitxer)
      error = error or argv[nPar][0] == '-'; // el nom del fitxer no pot comen�ar per '-'
      if (error) {
         throw excepcio::entradaIncorrecta("Parametres incorrectes");

      }
      p.nomFitxer = string(argv[nPar]);     // argv[nPar] cont� el nom del fitxer d'entrada
   }

   return p;

}

void mostrarAjuda(char* nomPrograma) {
   cerr << "Us: ./" << nomPrograma << " [-h] | [-m] [-cr <int>] [-gc <int>] [-s <int>] [-d <int>] fitxer" << endl << endl;
   cerr << "opcio pot ser :" << endl;
   cerr << "  -h, --help  mostra aquest missatge d ajuda i surt" << endl << endl;
   cerr << "  -m \t      cerca la solucio que minimitza el nombre de torns" << endl;
   cerr << "  -cr <int>:  assigna <int > com a nombre d aules de capacitat" << endl;
   cerr << "        \treduida disponibles per als examens" << endl;
   cerr << "  -gc <int>:  assigna <int > com a nombre d aules de gran" << endl;
   cerr << "        \tcapacitat disponibles per als examens" << endl;
   cerr << "  -s <int>:   indica que s ha de fer l assignacio per al" << endl;
   cerr << "        \tsemestre <int > (1 o 2)" << endl<<endl;
   cerr << "  -d <int>:   indica el limit maxim de dies que es poden fer servir" << endl;
   cerr << "fitxer \t      fitxer de text amb totes les assignatures a les" << endl;
   cerr << "        \tque es vol assignar un torn d examen i possibles" << endl;
   cerr << "        \trestriccions entre parells d'assignatures" << endl;

}
