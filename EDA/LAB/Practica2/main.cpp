// Carlos José Urbina Romero
// u1980975
// Practica 2

/**
 * @mainpage Practica 2
 * @author Carlos José Urbina
 * @version 1.0
 * @date 1970/01/01
 *
 *Practica 2 EDA
 */

#include <iostream>
#include <string>
#include "EPS.h"
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

namespace excepcio {
    /**
     * @struct entradaIncorrecta
     * @brief Estructura que representa una excepció per entrada incorrecta.
     * @param missatge Missatge d'error associat a l'excepció.
     */
    struct entradaIncorrecta {
       string missatge;
       entradaIncorrecta(string m) {missatge = m;}
    };

}

/**
 * @struct Parametres
 * @brief Estructura que conté els paràmetres d'execució del programa.
 */
struct Parametres
{
   int nombreAulesPetites; ///< Nombre d'aules de capacitat reduïda.
   int nombreAulesGran;    ///< Nombre d'aules de gran capacitat.
   int semestre;           ///< Semestre de treball.
   int diesMaxim;          ///< Nombre màxim de dies per a exàmens.
   string nomFitxer;       ///< Nom del fitxer de dades.
   bool ajuda;             ///< Indica si es mostra l'ajuda.
   bool cercaVoraz;        ///< Indica si s'executa l'algoritme voraz.
   bool millorSolucio;     ///< Indica si es busca la millor solució.
   bool backtracking;      ///< Indica si s'executa el backtracking.

   /**
    * @brief Constructor per defecte de Parametres.
    * @post Inicialitza els paràmetres amb valors predeterminats.
    */
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

/**
 * @brief Mostra el missatge d'ajuda.
 * @param nomPrograma Nom del programa executat.
 */
void mostrarAjuda(char *);

/**
 * @brief Processa els paràmetres d'entrada del programa.
 * @param argn Nombre d'arguments d'entrada.
 * @param argv Array d'arguments d'entrada.
 * @return Una estructura Parametres amb els valors processats.
 */
Parametres processaParametres(int argn, char** argv);

/**
 * @brief Redondeja un nombre cap amunt.
 * @param a Dividend.
 * @param b Divisor.
 * @return Resultat del redondeig cap amunt.
 */
int redondeaArriba(int a, int b) {
    return (a + b - 1) / b;
}

/**
 * @brief Mostra els torns d'exàmens generats.
 * @param eps Objecte EPS que conté les dades i mètodes per gestionar exàmens.
 * @param p Estructura Parametres amb els paràmetres de configuració.
 */
void mostrarTurnos(EPS &eps, Parametres p) {

    if (p.cercaVoraz) {
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

    }else {
        int turno = 0;
        auto t1 = high_resolution_clock::now();
        vector<list<Assignatura>> assignatures = eps.executarBacktracking(1);
        auto t2 = high_resolution_clock::now();

        for (list<Assignatura> assignaturesLista : assignatures) {
            cout << "\n*********************************" << endl;
            cout << "* Turno " << turno << "                   n=" << endl;
            cout << "*-------------------------------*" << endl;

            for ( list<Assignatura>::const_iterator itDos = assignaturesLista.begin(); itDos != assignaturesLista.end(); itDos++) {
                cout << "* " << setw(10) << left << itDos->getCodi() << " (tipus " << itDos->getTipus() << "), " << setw(5) << right << itDos->getGrau() << "-" << itDos->getCurs() << " *" << endl;

            }

            turno++;
        }

        cout << "Num. torns:\t" << assignatures.size() << endl;
        cout << "Num. dies:\t" << redondeaArriba(assignatures.size(), 2) << endl;
        duration<double> duracio = duration_cast<duration<double>>(t2 - t1);
        cout << "Temps: " << fixed << setprecision(10) << duracio.count() << " segons" << endl;
    }
}

/**
 * @brief Funció principal del programa.
 * @param argn Nombre d'arguments d'entrada.
 * @param argv Array d'arguments d'entrada.
 * @return 0 si l'execució és correcta.
 */
int main(int argn, char** argv) {
   try {
      Parametres p = processaParametres(argn, argv);

      if (p.ajuda) {
         mostrarAjuda(argv[0]);

      } else {

         if (p.cercaVoraz) {
            EPS eps(p.nombreAulesGran, p.nombreAulesPetites, p.semestre, p.diesMaxim);
            pair<int, int> dades = eps.llegirDades(p.nomFitxer);
            cout << dades.first << " " << dades.second << endl;
            eps.ferTorns();
            mostrarTurnos(eps, p);
         }else {
            EPS eps(p.nombreAulesGran, p.nombreAulesPetites, p.semestre, p.diesMaxim);
            pair<int, int> dades = eps.llegirDades(p.nomFitxer);
            cout << dades.first << " " << dades.second << endl;
            eps.executarBacktracking(1);
            mostrarTurnos(eps, p);

         }

      }
   }
   catch (excepcio::entradaIncorrecta ex) {
      cerr << ex.missatge << endl << endl;
      //mostrarAjuda(argv[0]);
   }

   return(0);

}

/**
 * @brief Processa els paràmetres d'entrada.
 * @param argn Nombre d'arguments d'entrada.
 * @param argv Array d'arguments d'entrada.
 * @return Una estructura Parametres amb els valors assignats segons els arguments.
 */
Parametres processaParametres(int argn, char** argv) {
   Parametres p;
   bool error = false;

   if (argn < 2) {
      throw excepcio::entradaIncorrecta("Falten arguments (\"p2 -- help\" per ajuda)");

   }
   else {
      int nPar = 1; //cambiar a 1 en el bash
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

/**
 * @brief Mostra el missatge d'ajuda del programa.
 * @param nomPrograma Nom del programa executat.
 */
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
