// Creat per jhg
// EDA (laboratori): Exercici 6
// Curs 2024/25

#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <vector>
#include <cmath>

const int MIN_COORDINATE_VAL = -1000;
const int MAX_COORDINATE_VAL =  1000;

const int COMPLEXITY_MIN = 3;
const int COMPLEXITY_MAX = 16;

const int LLAVOR = 13;

using namespace std;

struct Punt
{
    Punt():_x(0),_y(0) {};
    Punt(double x, double y):_x(x),_y(y) {};

    int _x;
    int _y;
};

namespace excepcio
{
struct entradaIncorrecta
{
    string missatge;
    entradaIncorrecta(string m)
    {
        missatge = m;
    }
};
}


struct Parametres
{
    bool compararAlgoritmes, estudiComplexitat, ajuda;
    int numPunts = 0;

    Parametres()
    {
        compararAlgoritmes = estudiComplexitat = ajuda = false;
        numPunts = 0;

    }
};

// Genera n punts de manera aleatoria i els guarda en el vector
void generarDades(vector<Punt>& v, unsigned int n) {
    default_random_engine generador(13);
    uniform_int_distribution<int> distribucio(MIN_COORDINATE_VAL, MAX_COORDINATE_VAL);

    for (int i = 0; i < n; i++) {
        Punt p;
        int x = distribucio(generador);
        int y = distribucio(generador);
        p._x = x;
        p._y = y;
        v.push_back(p);

    }
}

// Comparacio (temps) de l'execució dels dos algoritmes a mesura que
// s'incrementa la mida del vector aleatori
void estudiComplexitat();

// Comparacio (temps i resultat) de l'execució dels dos algoritmes
// amb un vector aleatori de mida n
void compararAlgoritmes(int n);

// Mètode que calcula en temps quadràctic la distància mínima entre
// qualsevol parell d'elements a l'interval [esq,dreta) del vector
double distMinQuadratica(const vector<Punt>& punts, int esq, int dreta);

// Mètode que implementa DiV (recursivitat) i calcula la distància mínima
// entre qualsevol parell d'elements a l'interval [esq,dreta) del vector
double distMinDiVRec(const vector<Punt>& punts, int esq, int dreta);

Parametres processaParametres(int argc, char** argv)
{
    Parametres p;
    bool error = false;

    if (argc < 2 or argc > 3)
    {
        throw excepcio::entradaIncorrecta("Numero de argumentos invalidos");
    }
    else
    {
        int nPar = 1;
        string par = string(argv[nPar]);

        if (string(argv[nPar]) == "-h") {
            p.ajuda = true;
            return p;

        } else if (par == "-r") {
            p.compararAlgoritmes = true;
            par = string(argv[++nPar]);
            if (par[0] >= '0' and par[0] <= '9') p.numPunts = stoi(par);
            else error = true;

        } else if (par == "-c") {
            p.estudiComplexitat = true;

        } else {
            error = true;

        }


        if (error)
        {
            throw excepcio::entradaIncorrecta("Parametros incorrectos");
        }

    }
    return p;
}

void mostrarAjuda(char* nomPrograma) {
    cerr << "Uso: " << nomPrograma << " -h | [-r <num>] | -c" << endl << endl;
    cerr << "  -h: Muestra esta ayuda" << endl << endl;
    cerr << "  -r <num>: Compara los algoritmos quadratric y divide, <num> nombre de puntos que el usuario elige" << endl << endl;
    cerr << "  -c: Estudio de complejidad, en cada paso incrementa la dificultad del problema y mide el tiempo de computo de los dos algoritmos" << endl;

}

int main (int argc, char **argv)
{
    vector<Punt> punts;

    try
    {
        Parametres p = processaParametres(argc, argv);

        if (p.ajuda) {
            mostrarAjuda(argv[0]);

        }

        else {
            if (p.compararAlgoritmes) {
                generarDades(punts, p.numPunts);
                cout << ", mostrarem el temps amb " << p.numPunts << " decimals";

            } else if (p.estudiComplexitat) {
                cout << ", aplicarem l'algorisme de Prim";

            }
            cout << "." <<endl;

        }
    }
    catch (excepcio::entradaIncorrecta ex) {
        cerr << "Excepcion! Entrada incorrecta: " << ex.missatge << endl << endl;
        mostrarAjuda(argv[0]);
    }

    return(0);
}
