// Carlos José Urbina Romero
// u1980975
// Practica 1

/**
 * @mainpage Gestor de padro
 * @author Carlos José Urbina Romero
 * @version 1.0
 * @date 2024/11/16
 *
 * Hemos usado la informacion de un padro para guardar su informacion y sacar
 * diferentes datos de el.
 *
 * Se ha documentado las clases utilizadas, explicado para que se usan y describiendo
 * sus atributos y clases, añadiendo las pre y post en cada funcion
 *

 */


#include <iostream>
#include <fstream>
#include <string>
#include "Padro.h"
#include <vector>
#include <list>
#include <iomanip>
#include <cmath>
#include "eines.h"

using namespace std;

const int NUM_DISTRICTES = 6;


/**
    @brief Metodo para redondear doubles
    @pre
    @post
    @param valor double valido que debemos redondear.
*/
double redondear(double valor) {
    return round(valor * 100) / 100.0;
}

/**
    @brief Metodo para mostrar los estudios de las personas que cumplen con los criterios.
    @pre El archivo debe haberse leido y padro debe tener los datos inicializados.
    @post Se muestra por pantalla una lista de estudios unicos.
    @param padro Referencia al objeto que contiene los datos del padro.
*/
void mostrarEstudisEdat(Padro &padro) {
    cout << "*******************************************" << endl;
    cout << "* 14: Estudis any,districte, edat i nacio *" << endl;
    cout << "*******************************************" << endl;
    int any, districte, edat, codiNacionalitat;
    cin >> any;
    cin >> districte;
    cin >> edat;
    cin >> codiNacionalitat;
    list<string> estudis = padro.estudisEdat(any, districte, edat, codiNacionalitat);

    cout << "Any: " << any << " Districte:" << districte << " Edat:" << edat << " Codi Nacionalitat:" << codiNacionalitat << endl;

    for (string estudi : estudis) {
        cout << estudi << endl;
    }
}

/**
    @brief Metodo para mostrar el distrito con el mayor incremento de jovenes entre dos años especificos.
    @pre El archivo debe haberse leido y padro debe tener los datos inicializados.
    @post Se muestra el distrito y el incremento de jovenes
    @param padro Referencia al objeto que contiene los datos del padro.
*/
void mostrarMesJoves(Padro &padro) {
    cout << "*****************" << endl;
    cout << "* 13: Mes joves *" << endl;
    cout << "*****************" << endl;

    int anyInicial, anyFinal;

    cin >> anyInicial;
    cin >> anyFinal;

    pair<string, long> resultat = padro.mesJoves(anyInicial, anyFinal);

    cout << "Any Inicial: " << anyInicial << " AnyFinal:" << anyFinal << endl;
    cout << resultat.first << "    " << resultat.second << endl;



}

/**
    @brief Metodo para mostrar el distrito con la edad promedio mas avanzada por cada año
    @pre El archivo debe haberse leido y padro debe tener los datos inicializados.
    @post Muestra por pantalla los años y el distrito con mas edad, si no hay no se mostrara.
    @param padro Referencia al objeto que contiene los datos del padro.
*/
void mostrarEdatVells(Padro &padro) {
    cout << "****************************" << endl;
    cout << "* 12: Moviments dels vells *" << endl;
    cout << "****************************" << endl;

    map<int, string> resultat = padro.movimentVells();

    for (map<int, string>::const_iterator it = resultat.begin(); it != resultat.end(); it++) {
        cout << it->first << "    " << it->second << endl;

    }

}

/**
    @brief Metodo para enseñar la edad media de cada año junto con cada distrito.
    @pre El archivo debe haberse leido y padro debe tener los datos inicializados.
    @post Muestra por pantalla la edad media de cada distrito por año.
    @param padro Referencia al objeto que contiene los datos del padro.
*/
void mostrarEdatMitjana(Padro &padro) {
    cout << "*********************" << endl;
    cout << "* 11: Resum d edats *" << endl;
    cout << "*********************" << endl;
    map<int, vector<pair<string, double>>> edats = padro.resumEdat();
    vector<pair<string, double>>::const_iterator itSegundo;

    for (map<int, vector<pair<string, double>>>::const_iterator it = edats.cbegin(); it != edats.cend(); it++) {
        cout << it->first << ":" << endl;

        for (itSegundo = it->second.begin(); itSegundo != it->second.end(); itSegundo++) {
            cout << "\t" << left << setw(35) << itSegundo->first << left << setw(16) << "Promig Edat:" << setw(8) << right << fixed << setprecision(2) << redondear(itSegundo->second) << endl;
        }

    }

}

/**
    @brief Metodo que muestra el distrito con el mayor numero de habitantes de una nacionalidad especifica para cada año
    @pre El archivo debe haberse leido y padro debe tener los datos inicializados.
    @post Muestra por pantalla los años y los distritos con la cantidad de gente de la nacionalidad especificada.
    @param padro Referencia al objeto que contiene los datos del padro.
*/
void mostrarMovimentsComunitat(Padro &padro) {
    cout << "*********************************" << endl;
    cout << "* 10: Moviments d'una comunitat *" << endl;
    cout << "*********************************" << endl;
    int nacionalitat = 0;
    cin >> nacionalitat;

    map<int,string> moviments = padro.movimentsComunitat(nacionalitat);

    cout << "Codi Nacionalitat:" << nacionalitat << endl;
    for(map<int,string>::const_iterator it = moviments.begin(); it != moviments.end(); it++) {
        cout << it->first << " " << setw(29) << right << it->second << endl;

    }
}

/**
    @brief Metodo para mostrar por cada año las nacionalidades que tiene y el numero de personas en cada uno
    @pre El archivo debe haberse leido y padro debe tener los datos inicializados.
    @post Mostrara por pantalla los años, las nacionalidades y la gente.
    @param padro Referencia al objeto que contiene los datos del padro.
*/
void mostrarNacionalitats(Padro &padro) {
    cout << "******************************" << endl;
    cout << "* 09: Resum de nacionalitats *" << endl;
    cout << "******************************" << endl;

    map<int, vector<pair<string, long>>> nacionalitats = padro.resumNacionalitats();

    for(map<int, vector<pair<string, long>>>::const_iterator it = nacionalitats.begin(); it != nacionalitats.end(); it++) {
        cout << it->first << endl;

        for (pair<string, long> pairNacionalitats : it->second) {
            cout << "\t" << left << setw(35) << pairNacionalitats.first << setw(8) << ":" << setw(8) << pairNacionalitats.second << endl;

        }
    }
}

/**
    @brief Metodo para mostrar el resumen de nivel de estudios por distrito y año, destacando el distrito con el mayor y menor promedio
    @pre El archivo debe haberse leido y padro debe tener los datos inicializados.
    @post Se imprime por pantalla los años, distritos y promedio.
    @param padro Referencia al objeto que contiene los datos del padro.
*/
void mostrarNivellEstudis(Padro &padro) {
    cout << "******************************" << endl;
    cout << "* 08: Resum nivell d'estudis *" << endl;
    cout << "******************************" << endl;
    map<int, vector<pair<string, double>>> nivellEstudis = padro.resumNivellEstudis();

    for (map<int, vector<pair<string, double>>>::const_iterator it = nivellEstudis.begin(); it != nivellEstudis.end(); it++) {
        cout << it->first << ":" << endl;
        for (pair<string, double> estudis : it->second) {
            cout << "\t" << left << setw(35) << estudis.first << left << setw(16) << "Promig Estudis:" << setw(8) << right << fixed << setprecision(2) << redondear(estudis.second) << endl;

        }
    }
}

/**
    @brief Metodo para por cada año mostrar cuantos estudios tiene el distrito especificado.
    @pre El archivo debe haberse leido y padro debe tener los datos inicializados.
    @post Muestra por pantalla el año y la cantidad de estudios de ese distrito.
    @param padro Referencia al objeto que contiene los datos del padro.
*/
void mostrarEstudisDistricte(Padro &padro) {
    cout << "**************************************" << endl;
    cout << "* 07: Nombre d estudis per districte *" << endl;
    cout << "**************************************" << endl;
    int districte;
    cin >> districte;
    cout << "Districte " << districte << endl;
    map<int, int> estudis = padro.nombreEstudisDistricte(districte);

    for (map<int, int>::const_iterator it = estudis.cbegin(); it != estudis.cend(); it++) {
        cout << "Any " << it->first << " Num Estudis:" << it->second << endl;

    }


}

/**
    @brief Metodo para mostrar el resumen de los estudios disponibles por cada año
    @pre El archivo debe haberse leido y padro debe tener los datos inicializados.
    @post Se muestra por pantalla el año y el valor es una lista de estudios unicos.
    @param padro Referencia al objeto que contiene los datos del padro.
*/
void mostrarEstudis(Padro &padro) {
    cout << "**************************************" << endl;
    cout << "* 06: Resum per estudis *" << endl;
    cout << "*************************" << endl;

    map<int, list<string>> estudis = padro.resumEstudis();

    for (map<int, list<string>>::const_iterator it = estudis.cbegin(); it != estudis.cend(); it++) {
        cout << it->first << " Estudis:";
        list<string> disAux = it->second;

        for (string estudios : disAux) {
            if (estudios != disAux.back()) {
                cout << estudios << " -- ";

            }else {
                cout << estudios;

            }
        }

        cout << endl;

    }

}

/**
    @brief Metodo para enseñar el numero de habitantes de una seccion de un año y distrito
    @pre El archivo debe haberse leido y padro debe tener los datos inicializados.
    @post Muestra por pantalla por año y distritos los habitantes por seccion.
    @param padro Referencia al objeto que contiene los datos del padro.
*/
void mostrarNombreHabitantsSeccio(Padro &padro) {
    cout << "*******************************************************" << endl;
    cout << "* 05: Obtenir nombre d'habitants d'un any i districte *" << endl;
    cout << "*******************************************************" <<endl;
    long total = 0;

    map<int, long> numHabitants = padro.obtenirNumHabitantsPerSeccio();

    for (map<int, long>::const_iterator it = numHabitants.begin(); it != numHabitants.end(); it++) {
        cout << "Seccio " << it->first << "   Habitants:" << setw(7) << it->second << endl;
        total += it->second;

    }

    cout << "TOTAL : " << total << endl;
}

/**
    @brief Metodo para obtener el nombre de habitantes de un año junto sus distritos.
    @pre El archivo debe haberse leido y padro debe tener los datos inicializados.
    @post Muestra por pantalla el numero de habitantes de ese año por cada distrito y el total final.
    @param padro Referencia al objeto que contiene los datos del padro.
*/
void mostrarNombreHabitants(Padro &padro) {
    cout << "******************************************" << endl;
    cout << "* 04: Obtenir nombre d habitants d un any*" << endl;
    cout << "******************************************" <<endl;
    int any;
    long total = 0;
    cin >> any;
    vector<long> numHabitants = padro.obtenirNumHabitantsPerDistricte(any);
    for (int i = 0; i < numHabitants.size(); i++) {
        cout << "Districte " << i + 1 << "\tHabitants:" << setw(8) << right << numHabitants[i] << endl;
        total += numHabitants[i];

    }

    cout << "TOTAL : " << total << endl;
}

/**
    @brief Metodo para obtener por cada año el numero de habitantes y el promedio.
    @pre El archivo debe haberse leido y padro debe tener los datos inicializados.
    @post Muestra por pantalla la cantida de gente por año y su promedio.
    @param padro Referencia al objeto que contiene los datos del padro.
*/
void mostrarNombreHabitantsAny(Padro &padro) {
    cout << "**********************************" << endl;
    cout << "* 03: Obtenir nombre d'habitants *" << endl;
    cout << "**********************************" <<endl;
    map<int, long> habitants = padro.obtenirNumHabitantsPerAny();
    int contador = 0;
    double promedio = 0;

    for (map<int, long>::const_iterator it = habitants.cbegin(); it != habitants.cend(); it++) {
        cout << it->first << "   habitants" << setw(7) << it->second << endl;
        contador++;
        promedio += it->second;

    }

    promedio = promedio / contador;

    cout << "PROMIG : " << redondear(promedio) << endl;



}

/**
    @brief Metodo para comprobar si existe un año.
    @pre El archivo debe haberse leido y padro debe tener los datos inicializados.
    @post Muestra por pantalla si existe o no un año.
    @param padro Referencia al objeto que contiene los datos del padro.
*/
void comprobarAny(Padro &padro) {
    cout << "********************" << endl;
    cout << "* 02: Existeix any *" << endl;
    cout << "*******************" << endl;
    int any;
    cin >> any;
    cout << "Any:" << any << endl;

    if (padro.existeixAny(any)) {
        cout << "Any existent" << endl;

    }else {
        cout << "Any inexistent" << endl;

    }
}


/**
    @brief Lee los datos de un archivo csv y los carga en el objeto padro
    @pre El archivo en la ruta debe existir, accesible y tener un formato valido.
    @post Los datos del archivo se cargan en el objeto.
    @param padro Referencia al objeto que contiene los datos del padro.
    @param ficheroLeido bool para ponerlo en true una vez leido el fichero.
*/
void lecturaFichero(Padro &padro, bool &ficheroLeido) {
    cout << "*******************" << endl;
    cout << "* 1: Llegir dades *" << endl;
    cout << "*******************" << endl;
    string ruta;
    cin >> ruta;
    cout << "Total lineas: " << padro.llegirDades(ruta) << endl;
    ficheroLeido = true;
}

/**
    @brief Ejecuta la opcion correspondiente segun el usuario
    @pre La opcion debe ser un string valido que corresponda a alguna opcion del menu
    @post Se ejecuta la funcionalidad o se acaba el programa.
    @param padro Referencia al objeto que contiene los datos del padro.
    @param opcio Opcion que escojamos
    @param ficheroLeido bool para ponerlo en true una vez leido el fichero.
*/
void escollirOpcio(string opcio, Padro &padro, bool &ficheroLeido) {
    if (opcio == "01") {
        if (!ficheroLeido) {
            lecturaFichero(padro, ficheroLeido);

        } else {
            cout << "Ya se ha leido un fichero" << endl;

        }

    } else if (opcio == "02") {
        if (ficheroLeido) {
            comprobarAny(padro);

        } else {
            cout << "Ya se ha leido un fichero" << endl;

        }

    } else if (opcio == "03") {
        if (ficheroLeido) {
            mostrarNombreHabitantsAny(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    } else if (opcio == "04") {
        if (ficheroLeido) {
            mostrarNombreHabitants(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    } else if (opcio == "05") {
        if (ficheroLeido) {
            mostrarNombreHabitantsSeccio(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    } else if (opcio == "06") {
        if (ficheroLeido) {
            mostrarEstudis(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    } else if (opcio == "07") {
        if (ficheroLeido) {
            mostrarEstudisDistricte(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    } else if (opcio == "08") {
        if (ficheroLeido) {
            mostrarNivellEstudis(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    }else if (opcio == "09") {
        if (ficheroLeido) {
            mostrarNacionalitats(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    }else if (opcio == "10") {
        if (ficheroLeido) {
            mostrarMovimentsComunitat(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    }else if (opcio == "11") {
        if (ficheroLeido) {
            mostrarEdatMitjana(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    }else if (opcio == "12") {
        if (ficheroLeido) {
            mostrarEdatVells(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    }else if (opcio == "13") {
        if (ficheroLeido) {
            mostrarMesJoves(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    }
    else if (opcio == "14") {
        if (ficheroLeido) {
            mostrarEstudisEdat(padro);

        } else {
            cout << "Tienes que leer primero un fichero" << endl;

        }

    } else {
        if (opcio != "0") {
            cout << "Opcion incorrecta!" << endl;

        }

    }

}

/**
    @brief Metodo para dar a elegir al usuario una opcion hasta que elija finalizar el bucle
    @pre Padro debe tener los datos inicializados
    @post El bucle continua ejecutando funcionalidades hasta que el usuario decide acabar.
    @param padro Referencia al objeto que contiene los datos del padro.
*/
void mostrarMenu(Padro &padro) {
    string opcio;
    bool ficheroLeido = false;

    do {
        //cout << "(1) Leer fichero" << endl;
        //cout << "(2) Numero de habitantes por distrito" << endl;
        //cout << "(3) Estudios" << endl;
        //cout << "(4) Edad media" << endl;
        //cout << "(5) Nacionalidades exclusivas" << endl;
        //cout << "(6) Edat y nacionalidad por distrito" << endl;
        //cout << "(0) Exit" << endl;

        //cout << "Escoge opcion (0 - 6): ";
        cin >> opcio;

        escollirOpcio(opcio, padro, ficheroLeido);

    }while(opcio != "0");
}

/**
    @brief Donde empieza el programa para crear el objeto padro y empezar a ejecutar funcionalidades
    @pre No hay pre especificas, todo esta disponible.
    @post Inicia el menu para empezar a ejecutar consultar
    @return 0 El programa ha acabado con exito.
*/
int main()
{
    Padro padro;
    mostrarMenu(padro);
    return 0;
}


