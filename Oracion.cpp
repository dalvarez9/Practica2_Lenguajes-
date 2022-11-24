#include <iostream>
#include <string>
#include "Oracion.h"
#include "Sujeto.h"
#include "Verbo.h"

using namespace std;

//creo que asi puede funcionar

Oracion::Oracion(string txt){
    int cantidadPalabras = numPalabras(txt);//numero de palabras en la oracion//
    this->palabras = new string[cantidadPalabras];//crea el arreglo y lo guarda en el atributo "palabras" de la clase oracion
    string palabra;
    int i = 0;
    int numPalabra = 0;
    while(txt.size() > i){
        //esta parte separa las diferentes palabras y las añade al arreglo
        if(i == txt.size() - 1){
            palabra = palabra + txt[i];
            this->palabras[numPalabra] = palabra;
//el ultimo caracter siempre es diferente de espacio, lo añade a la variable palabra y se añade la ultima palabra al arreglo
        }else if(txt[i] != ' '){
            palabra = palabra + txt[i];
//mientras el caracter no sea un espacio ' ' va juntando las letras en la variable palabra
        }else{
            if((palabra == "la")||(palabra == "el")||(palabra == "las")||(palabra == "los")||(palabra == "mi")){
                palabra = palabra + txt[i];
                this->palabras[cantidadPalabras - 1] = "vacio";
                i++;
                continue;
            }
            this->palabras[numPalabra] = palabra;
            palabra = "";
            numPalabra = numPalabra + 1;
//cuando el caracter es un espacio ' ' significa que llego al final de la palabra y la añade al arreglo. 
        }
        i = i + 1;
    }
    Verbo *verbo = new Verbo(this->palabras,cantidadPalabras);//lo mas importante, hallar el verbo
    Sujeto *sujeto = new Sujeto(this->palabras,cantidadPalabras);
    string predicado = obtPredicado(verbo->getPalabra(), palabras, cantidadPalabras);
    this->predicado = predicado;
    this->verbo = verbo;
    this->sujeto = sujeto;
    //validar frase
    string fraseFinal = this->sujeto->getPalabra() + " " + verbo->getPalabra() + " " + this->predicado;  
    if(fraseFinal == txt+"  "){
        cout<<"Oracion simple valida"<<endl;
    }else{
        cout<<"Oracion invalida"<<endl;
    }
};

Oracion::~Oracion(){
};

int Oracion::numPalabras(string txt){
//un metodo que cuenta las palabras en la oracion
    int cantPalabras = 0;
    int i = 0;
    while(i < txt.size()){
        if(i == txt.size() - 1){
            cantPalabras = cantPalabras + 1;
        }else if(txt[i] == ' '){
            cantPalabras = cantPalabras + 1;
        }
        i = i + 1;
    }
    //de momento el problema es aqui
    return cantPalabras;
};

string Oracion::obtPredicado(string verbo,string palabras[],int cantidadPalabras){
    string predicado;
    int posVerbo = -1;
    int i = 0;
    while(i < cantidadPalabras){
        if(palabras[i] == "vacio"){
            palabras[i] = "";
        }else if(verbo == palabras[i]){
            posVerbo = i;
            i++;
            continue;
        }
        if(posVerbo != -1){
            predicado = predicado + palabras[i] + " ";
        }
        i++;
    }
    return predicado;
};
