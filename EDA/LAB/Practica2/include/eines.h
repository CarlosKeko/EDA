//
// Created by jordir on 25/9/21.
//

#ifndef EINES_H
#define EINES_H

#include <string>
#include <vector>
using namespace std;

// pre: --
// post: excepcions: si cometes �s cert, el primer car�cter �s " i no hi ha unes segones " que tanquin, es genera una excepci�
// retorna: cadena entre posicio primer i seg�ent separador o final de linia
//          si cometes �s cert, quan el token comen�a per " busca la " que ho tanca i les elimina del token
string token(const string &s, char separador, bool cometes, long &primer, long &ultim);

// pre: --
// post: --
// retorna: vector<string> amb tots els components d'una l�nia CSV b�sica (nom�s tractant separadors)
//          un component est� format per tots els car�cters entre dos separador excepte el primer i l'�ltim
//              el primer component est� format per tots els car�cters abans del primer separador
//              l'�ltim component est� format per tots els car�cters de despr�s de l'�ltim separador
vector<string> tokens(const string &s, char separador = ',', bool cometes = false);


#endif //LECTURA_EINES_H
