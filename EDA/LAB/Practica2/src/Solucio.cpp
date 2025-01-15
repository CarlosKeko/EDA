#include "Solucio.h"

Solucio::Solucio(list<Assignatura> assignatures, map<string, list<string>> restriccions, int diesMaxim, int aulaGran, int aulaReduida)
    : assignaturesPendents(assignatures),
      restriccions(restriccions),
      nivell(0),
      aulagran(aulaGran),
      aulareduida(aulaReduida),
      diesmaxim(diesMaxim),
      disponibilitat(diesMaxim, make_pair(aulaGran, aulaReduida)),
      res(1) {}

Candidats Solucio::inicialitzarCandidats() const {
    return Candidats(assignaturesPendents);
}

void Solucio::anotar(const Candidats& candidat) {
    res[nivell].push_back(candidat.actual());
    assignaturesPendents.remove(candidat.actual());

}

void Solucio::desanotar(const Candidats & candidats) {
    res[nivell].remove(candidats.actual());
    assignaturesPendents.push_back(candidats.actual());

}

bool Solucio::completa() const {
    return assignaturesPendents.empty();

}

bool Solucio::acceptable(const Candidats &candidats) {

    if (candidats.fi()) {
        cout << "No hay más candidatos." << endl;
        return false;
    }



    cout << "\n----------------------------" << endl;
    cout << "Assignatures pendents: " << assignaturesPendents.size() << endl;
    cout << "Nivell: " << nivell << endl;
    cout << "Disponbilitat gran: " << disponibilitat[nivell].first << endl;
    cout << "Disponbilitat reduida: " << disponibilitat[nivell].second << endl;
    cout << "Tamany disponibilitat: " << disponibilitat.size() << " | tipus candidat:" << candidats.actual().getTipus() << " | codi candidat: " << candidats.actual().getAssignatura() << endl;

    for (list<Assignatura>::iterator it = assignaturesPendents.begin(); it != assignaturesPendents.end(); it++) {
        cout << it->getAssignatura() << endl;
    }



    if (disponibilitat[nivell].first <= 0 && disponibilitat[nivell].second <= 0) {
        nivell++;
        if (nivell >= disponibilitat.size()) {
            disponibilitat.push_back(make_pair(aulagran, aulareduida));
            res.push_back(list<Assignatura>());
        }

        return false;

    }

    list<string> assignaturasMias = restriccions.at(candidats.actual().getCodi());

    list<Assignatura> assignaturesVigilar = res.at(nivell);

    for (list<string>::const_iterator it = assignaturasMias.begin(); it != assignaturasMias.end(); it++) {
        for (list<Assignatura>::const_iterator itDos = assignaturesVigilar.begin(); itDos != assignaturesVigilar.end(); itDos++) {
            if (itDos->getCodi() == *it) {
                cout << "RESTRICCION!! " << endl;
                //nivell++;
                //return false;

            }
        }
    }


    if (candidats.actual().getTipus() == 'g' && disponibilitat[nivell].first > 0) {
        disponibilitat[nivell].first--;

    }else if (candidats.actual().getTipus() == 'r') {
        cout << "ADIOS" << endl;
        if (disponibilitat[nivell].second > 0) {
            disponibilitat[nivell].second--;

        }else if (disponibilitat[nivell].first > 0) {
            disponibilitat[nivell].first--;

        }else {
            //nivell++;
            if (nivell >= 0 && nivell >= res.size() || nivell >= 0 && nivell >= disponibilitat.size()) {
                disponibilitat.push_back(make_pair(aulagran, aulareduida));
                res.push_back(list<Assignatura>());

            }
            return false;

        }

    }else {
        //nivell++;
        if (nivell >= 0 && nivell >= res.size()) {
            disponibilitat.push_back(make_pair(aulagran, aulareduida));
            res.push_back(list<Assignatura>());

        }
        return false;

    }

    //nivell = 0;
    cout << "LLEGA" << endl;
    return true;
}

vector<list<Assignatura>> Solucio::getRes() {
    return res;
}

