#ifndef Sujeto_h
#define Sujeto_h
#include <string>

using namespace std;

class Sujeto{
    private:
        string palabra = "";
        string list_sujetos;
        
    public:
        Sujeto(string[],int);
        ~Sujeto();
        string lista_Sujetos();
        string getPalabra();
};
#endif
