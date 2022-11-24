#ifndef Oracion_h
#define Oracion_h
#include <string>
#include "Verbo.h"
#include "Sujeto.h"

using namespace std;

class Oracion{
    private:
        string *palabras;
        Sujeto *sujeto;
        Verbo *verbo;
        string predicado;

    public:
        Oracion(string);
        ~Oracion();
        int numPalabras(string);
        string obtPredicado(string,string[],int);
};

#endif
