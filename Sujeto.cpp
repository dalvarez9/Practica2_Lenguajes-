#include <stdio.h>
#include <iostream>
#include <string>
#include "Sujeto.h"
#include <fstream>

using namespace std;

Sujeto::Sujeto(string palabras[],int cantPalabras){
    this->list_sujetos = lista_Sujetos();
    int i = 0;
    while(cantPalabras > i){
        string prueba = " " + palabras[i] + " ";
        int num = this->list_sujetos.find(prueba);
        if(num != -1){
            this->palabra = palabras[i];
            break;
        }
        i++;
    }
};

Sujeto::~Sujeto(){
};

string Sujeto::lista_Sujetos(){
    ifstream lectura;
    string linea, texto;

    lectura.open("Sujetos.txt",ios::in);
    while(getline(lectura,linea)){
        texto = texto + linea + "\n";
    }
    lectura.close();
    return texto;
};

string Sujeto::getPalabra(){
    return this->palabra;
};
