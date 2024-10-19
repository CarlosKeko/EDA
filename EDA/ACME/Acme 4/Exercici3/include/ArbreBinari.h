#include <memory>
#include <iostream>

#ifndef ARBREBINARI_H
#define ARBREBINARI_H


using namespace std;

class ArbreBinari { // Arbre Binari

  public:
    ArbreBinari();
    ArbreBinari(const char t[]);
    bool esBuit() const;
    ArbreBinari FillDret() const;
    ArbreBinari FillEsquerre() const;
    char Contingut() const;
    // no t� destructor.

  private:
    struct node {
        char dada;
        shared_ptr<node> fe, fd;
    };

    shared_ptr<node>  arrel;

    shared_ptr<ArbreBinari::node> iArbreBinari(const char t[], int &i); // m�tode auxiliar del constructor
};

#endif // ARBREBINARI_H