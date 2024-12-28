#include <iostream>
#include <vector>


using namespace std;


void llegirPic(vector<int> &v) {
// pre: cert
// pos: omple el vector v amb una sequencia llegida per teclat
    int n;
    cout << "Entra una sequencia d'enters acabada en 0:" << endl;
    cin >> n;
    while (n!=0) {
        v.push_back(n);
        cin >> n;
    }
}

// t(n) = 2 * T (n/2) + O(1), a = 2, b = 2, k = 0 -> t(n)€O(n log2 2)
int iobtenirCim(const vector<int> &v, int esq, int dre) {
    int res;

    if (dre - esq <= 3) {
        res = esq;

        for (int i = esq; i <= dre; i++) {
            if (v[i] > v[res]) res = i;

        }

    }else {
        int mig = (esq + dre) / 2;
        int res1 = iobtenirCim(v, esq, mig);
        int res2 = iobtenirCim(v, mig + 1, dre);

        if (v[res1] > v[res2]) res = res1;
        else res = res2;


    }

    return res;

}

int obtenirCim(const vector<int> &v) {
// pre: v és un pic
// pos: retorna el cim del pic
// t(n) = ...  cas base
// t(n) = ...  cas recursiu
// t(n) es O(...)
    return iobtenirCim(v, 0, v.size() - 1);
}


int main() {
    vector<int> v;

    llegirPic(v);
    int cim = obtenirCim(v);

    cout << "El cim es " << v[cim] << " i es troba a la posicio " << cim << endl;

    return 0;
}
