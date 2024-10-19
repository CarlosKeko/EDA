#ifndef PADRO_H
#define PADRO_H

#include <vector>
#include <map>
#include <list>
#include <string>

using namespace std;

class Padro {
public:
   Padro();
   int llegirDades(const string &path);
   bool existeixAny(int any) const;
   vector<long> obtenirNumHabitantsPerDistricte(int any) const;
   ResumEstudis resumEstudis() const;
   map<int,int> nombreEstudisDistricte(int districte) const;
   ResumEdats resumEdat() const;
   list<string> estudisEdat(int any, int districte, int edat, int codiNacionalitat) const;

private:
};

#endif //PADRO_H
