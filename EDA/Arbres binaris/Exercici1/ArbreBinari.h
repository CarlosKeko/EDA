#ifndef ARBREBINARI_H
#define ARBREBINARI_H


class ArbreBinari   // Arbre Binari
{
public:
    ArbreBinari();
    ArbreBinari(const char t[]);
    bool esBuit() const;
    ArbreBinari FillDret() const;
    ArbreBinari FillEsquerre() const;
    char Contingut() const;
    // no té destructor.

private:
    struct node
    {
        char dada;
        shared_ptr<node> fe, fd;
    };

    shared_ptr<node>  arrel;



#endif // ARBREBINARI_H
