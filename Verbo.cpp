#include <stdio.h>
#include <iostream>
#include <string>
#include "Verbo.h"
#include <fstream>

using namespace std;
Verbo::Verbo(string palabras[], int cantPalabras){
    this->list_verbos = lista_verbos();
    int i = 0;
    while(cantPalabras > i){
        string prueba = " " + palabras[i] +" ";
        int num = this->list_verbos.find(prueba);
        if(num != -1){
            this->palabra = palabras[i];
        }
        i++;
    }
};

Verbo::~Verbo(){
};

string Verbo::lista_verbos(){
    ifstream lectura;
    string linea, texto;

    lectura.open("Verbos.txt",ios::in);
    while(getline(lectura,linea)){
        texto = texto + linea + "\n";
    }
    lectura.close();
    return texto;
};
    
string Verbo::getPalabra(){
    return this->palabra;
}; 
