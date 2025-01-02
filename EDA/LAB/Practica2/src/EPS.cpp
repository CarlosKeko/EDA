#include "EPS.h"


using namespace std;

EPS::EPS(int aulagran, int aulareduida) {
    this->aulagran = aulagran;
    this->aulareduida = aulareduida;

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


                    if (semestre != -1 && curs != -1 && grau != "-1" && assignatura != "-1" && codi != "-1" && tipus != '-') {
                        Assignatura nuevaAssig(grau, assignatura, codi, tipus, credits, semestre, curs);
                        assignatures.push_back(nuevaAssig);
                        graus.insert(grau);
                        numLinies++;
                    }

                }else {

                    //POSAR RESTRICCIONS

                    //cout << tokensAux.at(0) <<endl;

                }

            }

        }
    }

    return make_pair(numLinies, graus.size());
}

map<string, list<Assignatura>> EPS::ferTorns() const {
    list<Assignatura>::const_iterator it = assignatures.begin();
    map<string, list<Assignatura>> resultat;
    int turno = 0;
    int turnosNecesarios = calcularTurnos();
    vector<pair<int, int>> disponibilitat(turnosNecesarios, make_pair(aulagran, aulareduida));
    set<int> turnosHechos;

    while (it != assignatures.end()) {
        cout << "hoa" << endl;
        if (it->getTipus() == 'g' && disponibilitat[turno].first > 0) {
            disponibilitat[turno].first--;
            resultat["Torn " + to_string(turno + 1)].push_back(*it);
            it++;

        }else if (it->getTipus() == 'r' && disponibilitat[turno].second > 0) {
            disponibilitat[turno].second--;
            resultat["Torn " + to_string(turno + 1)].push_back(*it);
            it++;

        }else if (it->getTipus() == 'r' && disponibilitat[turno].first > 0) {
            disponibilitat[turno].first--;
            resultat["Torn " + to_string(turno + 1)].push_back(*it);
            it++;

        }else {
            if (disponibilitat[turno].first == 0 && disponibilitat[turno].second == 0) {
                turnosHechos.insert(turno);
            }

            if (turno >= turnosNecesarios - 1) {
                turno = 0;

            }else {
                turno++;

            }
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
