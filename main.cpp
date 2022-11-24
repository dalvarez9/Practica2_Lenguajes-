#include <iostream>
#include "Oracion.h"
using namespace std;

int main() {
    string texto;
    cout << "Ingrese una oracion: ";
    getline(cin, texto);
    Oracion *oracion = new Oracion(texto);
}
