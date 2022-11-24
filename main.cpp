#include <iostream>
#include "Oracion.h"
using namespace std;

int main() {
    string texto;
    cout << "Ingrese una oracion: ";
    while(true){
        getline(cin, texto);
        if(texto == "FIN"){
            break;
        }
        Oracion *oracion = new Oracion(texto);
        cout<<"Escriba otra oracion o escriba FIN para finalizar la ejecucion : "<<endl;
    }
}
