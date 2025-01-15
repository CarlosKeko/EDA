#include "EPS.h"
///SOLUCIONADOR

using namespace std;

EPS::EPS(int aulagran, int aulareduida, int semestre, int diesMaxim) {
    this->aulagran = aulagran;
    this->aulareduida = aulareduida;
    this->semestre = semestre;
    if (diesMaxim == -1) {
        diesMaxim = 1;

    }else {
        this->diesMaxim = diesMaxim;

    }

}

pair<int, int> EPS::llegirDades(const string& path) {
    ifstream archivo(path);
    string linea;
    int numLinies = 0;
    set<string> graus;
    bool restriccions = false;

    if (!archivo.is_open()) {
        cout << "\nEl archivo no se ha podido abrir" << endl;

    }else {
        getline(archivo, linea);
        while(getline(archivo, linea)) {
            vector<string> tokensAux = tokens(linea, '\t', true);

            if (tokensAux.at(0) == "*") {
                restriccions = true;

            }else {
                if (!restriccions) {
                    string grau = tokensAux.at(0);
                    string assignatura = tokensAux.at(1);
                    string codi = tokensAux.at(2);
                    char tipus = tokensAux.at(3)[0];
                    double credits = stod(tokensAux.at(4));
                    int semestre = stringToInt(tokensAux.at(5));
                    int curs = stringToInt(tokensAux.at(6));

                    if (semestre == this->semestre && curs != -1 && grau != "-1" && assignatura != "-1" && codi != "-1" && tipus != '-') {
                        Assignatura nuevaAssig(grau, assignatura, codi, tipus, credits, semestre, curs);
                        assignatures.push_back(nuevaAssig);
                        graus.insert(grau);
                        numLinies++;
                        afegirRestriccio(tokensAux.at(2));

                    }

                }else {
                    afegirRestriccio(tokensAux.at(0), tokensAux.at(1));

                }

            }

        }
    }

    assignatures.sort(compararTipus);
    return make_pair(numLinies, graus.size());
}

map<string, list<Assignatura>> EPS::ferTorns() const {
    int turno = 0;
    list<Assignatura>::const_iterator it = assignatures.begin();
    map<string, list<Assignatura>> resultat;
    vector<pair<int, int>> disponibilitat(diesMaxim, make_pair(aulagran, aulareduida));

    while (it != assignatures.end()) {
        if (turno < disponibilitat.size()) {
            if (disponibilitat[turno].first > 0 || disponibilitat[turno].second > 0) {
                if (it->getTipus() == 'g' && disponibilitat[turno].first > 0) {
                    if (esPotAfegir(it->getCodi(), resultat["Torn " + to_string(turno + 1)])){
                        disponibilitat[turno].first--;
                        resultat["Torn " + to_string(turno + 1)].push_back(*it);
                        it++;
                        turno = 0;

                    }else {
                        turno++;

                    }

                }else if (it->getTipus() == 'r') {
                    if (esPotAfegir(it->getCodi(), resultat["Torn " + to_string(turno + 1)])) {
                        if (disponibilitat[turno].second > 0) {
                            disponibilitat[turno].second--;
                            resultat["Torn " + to_string(turno + 1)].push_back(*it);
                            it++;
                            turno = 0;

                        }else if (disponibilitat[turno].first > 0) {
                            disponibilitat[turno].first--;
                            resultat["Torn " + to_string(turno + 1)].push_back(*it);
                            it++;
                            turno = 0;

                        }

                    }else {
                        turno++;

                    }

                }else {
                    turno++;

                }

            }else {
                turno++;

            }

        }else {
            disponibilitat.push_back(make_pair(aulagran, aulareduida));

        }

    }

    return resultat;
}

int EPS::calcularTurnos() const {
    int resultatGran = 0;
    int resultatPetit = 0;

    for (list<Assignatura>::const_iterator it = assignatures.begin(); it != assignatures.end(); it++) {
        if (it -> getTipus() == 'g') {
            resultatGran++;

        }else if (it -> getTipus() == 'r') {
            resultatPetit++;

        }
    }

    resultatGran = redondeaArriba(resultatGran, aulagran);
    resultatPetit = redondeaArriba(resultatPetit, aulareduida);

    if (resultatGran > resultatPetit) {
        return resultatGran;

    }else {
        return resultatPetit;

    }
}


//PRIVATE

int EPS::redondeaArriba(int a, int b) const {
    return (a + b - 1) / b;
}

int EPS::stringToInt ( string s ) {
    if ( s . length ()==0) return -1;

    for( char c : s ) {
        if (c <'0' || c >'9') return -1;
    }

    return stoi ( s );
}

bool EPS::compararTipus(const Assignatura &a1, const Assignatura &a2) {
    return a1.getTipus() < a2.getTipus();
}

void EPS::afegirRestriccio(string a1) {
    list<string> restriccionNueva;
    Assignatura assignaturaBuscada = buscarAssignatura(a1);

    for (map<string, list<string>>::iterator it = restricciones.begin(); it != restricciones.end(); it++) {
        Assignatura assignaturaAux = buscarAssignatura(it->first);

        if (assignaturaAux.getGrau() == assignaturaBuscada.getGrau() && assignaturaAux.getCurs() == assignaturaBuscada.getCurs()) {
            //cout << "Creada restriccio entre " << assignaturaAux.getAssignatura() << " y " << assignaturaBuscada.getAssignatura() << endl;
            it->second.push_back(a1);
            restriccionNueva.push_back(it->first);

        }
    }

    restricciones[a1] = restriccionNueva;
}

void EPS::afegirRestriccio(string c1, string c2) {
    restricciones[c1].push_back(c2);
    restricciones[c2].push_back(c1);

}

Assignatura EPS::buscarAssignatura(string c) {
    for (list<Assignatura>::iterator it = assignatures.begin(); it != assignatures.end(); it++) {
        if (it->getCodi() == c) {
            return *it;
        }
    }
}

bool EPS::esPotAfegir(string c, const list<Assignatura> &assignaturesVigilar) const {
    list<string> assignaturasMias = restricciones.at(c);

    for (list<string>::const_iterator it = assignaturasMias.begin(); it != assignaturasMias.end(); it++) {
        for (list<Assignatura>::const_iterator itDos = assignaturesVigilar.begin(); itDos != assignaturesVigilar.end(); itDos++) {
            if (itDos->getCodi() == *it) {
                //cout << "No es pot " << c << endl;
                return false;

            }
        }

    }

    return true;
}

vector<list<Assignatura>> EPS::executarBacktracking(int tipus) {
    Solucionador solucionador(tipus);
    //cout << diesMaxim << endl;
    solucionador.solucionar(assignatures, restricciones, 1, aulagran, aulareduida);

}
