#ifndef Verbo_h
#define Verbo_h
#include <string>

using namespace std;

class Verbo{
    private:
        string list_verbos;
        string palabra = "";
    public:
        Verbo(string[],int);
        ~Verbo();
        string lista_verbos();
        string getPalabra();
};
#endif
