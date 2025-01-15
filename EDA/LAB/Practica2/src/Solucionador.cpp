#include "Solucionador.h"


// Constructor que determina el tipus de solucio
Solucionador::Solucionador (int tipus) {
    trobat = false;

}

// Retorna la solucio guardada
Solucio Solucionador::obtenirSolucio () const {
    return solucioActual;
}

// Inicialitza la solucio inicial i executa backtracking
bool Solucionador::solucionar (list<Assignatura> &assignatures, map<string, list<string>> &restriccions, int diesMaxim, int aulaGran, int aulaReduida) {
    solucioActual = Solucio(assignatures, restriccions, diesMaxim, aulaGran, aulaReduida);
    backtracking();

}


//PRIVATE

// Implementa l'esquema ( recursiu ).
// Pot haver -ne una per cada variant de l 'esquema .
void Solucionador::backtracking() {
    Candidats candidats = solucioActual.inicialitzarCandidats();

    while (!candidats.fi() && !trobat) {
        candidats.seguent();

        if (solucioActual.acceptable(candidats)) {
            solucioActual.anotar(candidats);

            if (solucioActual.completa()) {
                trobat = true;

            } else {
                backtracking();

                if (!trobat) {
                    solucioActual.desanotar(candidats);
                }
            }
        }

    }
}
