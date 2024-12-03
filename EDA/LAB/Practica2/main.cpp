// Creat per jhg
// Laboratoris EDA 24/25
// Exemple simple de gesti� dels par�metres d'entrada
// amb excepcions.

#include <iostream>
#include <string>

using namespace std;

namespace excepcio {
    struct entradaIncorrecta {
       string missatge;
       entradaIncorrecta(string m) {missatge = m;}
    };

}

struct Parametres
{
   bool mostrarTemps, ferPrim, ajuda;
   int decimals = 0;

   int nombreAulesPetites;
   int nombreAulesGran;
   int semestre;
   string nomFitxer;

   Parametres()
   {
      mostrarTemps = ferPrim = ajuda = false;
      decimals = 0;

      nombreAulesGran = nombreAulesPetites = semestre = 0;
      nomFitxer = "";
   }

};

void mostrarAjuda(char *);
Parametres processaParametres(int argn, char** argv);

int main(int argn, char** argv) {
   try {
      Parametres p = processaParametres(argn, argv);

      if (p.ajuda) {
         mostrarAjuda(argv[0]);
      } else {
         cout << "Treballarem amb el fitxer " << p.nomFitxer;
         if (p.ferPrim) cout << ", aplicarem l'algorisme de Prim";
         if (p.mostrarTemps) cout << ", mostrarem el temps amb " << p.decimals << " decimals";
         cout << "." <<endl;
      }
   }
   catch (excepcio::entradaIncorrecta ex) {
      cerr << "excepcio!! Entrada incorrecta: " << ex.missatge << endl << endl;
      mostrarAjuda(argv[0]);
   }

   return(0);

}


Parametres processaParametres(int argn, char** argv) {
   Parametres p;
   bool error = false;

   if (argn < 2 or argn > 5) {
      throw excepcio::entradaIncorrecta("Nombre d'arguments invalid");
   }
   else {
      int nPar = 1;
      if (string(argv[nPar]) == "-h") {
         p.ajuda = true;
         return p;
      }
      while (!error and nPar < argn-1) { // processar opcions
         string par = string(argv[nPar]);
         if (par == "-t") {
            p.mostrarTemps = true;
            par = string(argv[++nPar]);
            if (par[0] >= '0' and par[0] <= '9') p.decimals = stoi(par);
            else error = true;
         }
         else if (par == "-p") p.ferPrim = true;
         else error = true;
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
   cerr << "  -d <int>:   indica el l´ımit m`axim de dies que es poden fer servir" << endl;
   cerr << "fitxer \t      fitxer de text amb totes les assignatures a les" << endl;
   cerr << "        \tque es vol assignar un torn d examen i possibles" << endl;
   cerr << "        \trestriccions entre parells d ’ assignatures" << endl;

}
