#include <fstream>
#include <string>
#include <iostream>


#include "Graf.h"

Graf::Graf()
{
    nVers = nArs = 0;
    dirigit = false;
    vertexs.resize(nVers+1); // casella 0 no ocupada
}

Graf::Graf(int nVertexs, bool dirigit)
{
    nVers = nVertexs;
    nArs = 0;
    this->dirigit = dirigit;
    vertexs.resize(nVers+1); // casella 0 no ocupada
}

Graf::Graf(char nom_fitxer[], bool dirigit)
{
    ifstream f(nom_fitxer);
    string linia;

    nVers = 0;
    nArs = 0;
    this->dirigit = dirigit;

    if (f.is_open()) {
        getline(f, linia);
        while (linia != "#" ) {
            nVers++;
            getline(f, linia);
        }
        vertexs.resize(nVers+1);

        int v1, v2;
        f >> v1 >> v2;
        while (not f.eof()) {
            vertexs[v1].push_back(v2); // no es valida
            if (not dirigit)
                vertexs[v2].push_back(v1);
            nArs++;
            f >> v1 >> v2;
        }
        f.close();
    }
}

int Graf::nVertexs() const
{
    return nVers;
}

int Graf::nArestes() const
{
    return nArs;
}

bool Graf::esDirigit() const
{
    return dirigit;
}



void Graf::ordreAssignatures() const
{
    if (not dirigit) cout << "Nomes per grafs dirigits" << endl;
    else {
        vector<int> res; // per guardar la sortida
        list<int> pendent;

        for (int i = 1; i <= nVers; i++) pendent.push_back(i);

        while(pendent.size() > 0) {
            int aux = mesPrometedor(pendent, res);
            res.push_back(aux);
            pendent.remove(aux);

        }

        cout << res[0];
        for (int i=1; i<nVers; i++)
            cout << ", " << res[i];
        cout << endl;
    }
}

int Graf::mesPrometedor(const list<int> & pendent, const vector<int> & res) const {
     bool encontrado = false;
     bool tieneValores = false;
     list<int> repetits;

    //Repasamos si es primera assignatura
     for (list<int>::const_iterator it = pendent.begin(); it != pendent.end(); it++) {
        encontrado = false;
        tieneValores = false;
        for (list<int> arestes : vertexs) {
            if (existeix(*it, arestes)) {
                encontrado = true;
            }
        }

        if (!encontrado && vertexs[*it].size() > 0) {
            tieneValores = true;

        }

        if (!encontrado && tieneValores) repetits.push_back(*it);

     }

     if (repetits.size() == 1) {
        return *repetits.begin();

     }else if (repetits.size() > 1) {
        return mesPrometedorRepetits(repetits);

     }

    //Repasamos si es assignatura intermediaria
    for (list<int>::const_iterator it = pendent.begin(); it != pendent.end(); it++) {
        encontrado = false;
        tieneValores = false;

        for (list<int> arestes : vertexs) {
            if (existeix(*it, arestes)) {
                encontrado = true;
            }
        }

        if (encontrado && vertexs[*it].size() > 0) {
            tieneValores = true;

        }

        if (encontrado && tieneValores) repetits.push_back(*it);

     }

     if (repetits.size() == 1) {
        return *repetits.begin();

     }else if (repetits.size() > 1) {
        return mesPrometedorRepetits(repetits);

     }

    //Repasamos si es última assignatura
    for (list<int>::const_iterator it = pendent.begin(); it != pendent.end(); it++) {
        encontrado = false;
        tieneValores = false;

        //Repasamos si es primera assignatura
        for (list<int> arestes : vertexs) {
            if (existeix(*it, arestes)) {
                encontrado = true;
            }
        }

        if (!encontrado && vertexs[*it].size() > 0) {
            tieneValores = true;

        }

        if (encontrado && !tieneValores) return *it;

     }

    return *pendent.begin();
}

bool Graf::existeix(const int valor, const list<int> & arestes) const {
    for (list<int>::const_iterator itU = arestes.begin(); itU != arestes.end(); itU++) {
        if (*itU == valor) return true;

    }

    return false;
}

int Graf::mesPrometedorRepetits(const list<int> &repetits) const {
    int resultat = *repetits.begin();
    int dependent = 0;

    for (list<int>::const_iterator itD = repetits.begin(); itD != repetits.end(); itD++) {
        if (vertexs[resultat].size() > dependent) {
            dependent = vertexs[resultat].size();
            resultat = *itD;
        }
    }

    return resultat;
}
