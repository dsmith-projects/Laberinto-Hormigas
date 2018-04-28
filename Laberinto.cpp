/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Laberinto.cpp
 * Author: Alan
 * 
 * Created on 7 de febrero de 2018, 04:46 PM
 */

#include <stdio.h>     
#include <stdlib.h>     
#include <time.h> 
#include <iostream>
using namespace std;

#include "Laberinto.h"

Laberinto::Laberinto(int cantidadVrts, double probabilidadAdy){
    if((cantidadVrts > 0) || (0 < probabilidadAdy < 1)){
        cntVrts = cantidadVrts;
        int contador = 0;
        int actual = 0;
        int nRandom;
        arregloVrts = new Vertice[cntVrts];
        
        while(contador < cntVrts){
            contador++;
        }
        
        contador = 0;
        
        arregloAdys = new Adyacencia[cntVrts * (cntVrts + 1) / 2];
        
        srand (time(NULL));
        
        while(actual != cntVrts){
            while(contador != cntVrts){
                nRandom = rand() % 99 + 1;
                cout << actual << " " << nRandom << endl;
                actual++;
            }
        }
    }    
}


Laberinto::Laberinto(ifstream& archivo){       
    int flujoSalida;
    char charFinLinea = ' ';
    //ifstream archivo("Laberintop.txt", ios::in);
    
    
    //Lee la primera linea: cantidad de nodos. Linea #1
    archivo >> flujoSalida;
    cntVrts = flujoSalida; // Guardo el numero de nodos de la primera linea en la variable cantNodos
    //Lee la siguiente linea. Linea #2
    
    arregloAdys = new Adyacencia[cntVrts + (cntVrts + 1 ) / 2];
    arregloVrts = new Vertice[cntVrts];
    int contador = 0;
    
    archivo >> flujoSalida; //Consumio la linea 2. Leo el 6
    //cout << "Que es " << flujoSalida << endl;
    while(!archivo.eof()){//Mientras no se llegue al fin del archivo de texto
        ListaOrdenada lista;
         
        while(!archivo.eof() && charFinLinea != 10){ //Mientras no se llegue al fin del archivo de texto ni al fin de linea (En ASCII el 10 representa el simbolo de fin de linea)
            lista.agregar(flujoSalida);
            
            archivo >> flujoSalida; //Extrae un numero de la lista ordenada de adyacencias
            archivo.get(); // Avanza sobre un espacio en blanco. Lo consume y se mueve al siguiente flujo de caracteres
            charFinLinea = archivo.peek(); // revisa si el siguiente caracter es el fin de linea
        }
        if(!archivo.eof()){//Si aun tiene caracteres el archivo 
            lista.agregar(flujoSalida);
        }
        archivo >> flujoSalida; //Lee la siguiente linea del archivo. Linea #4 en adelante por estar dentro del ciclo del while
        archivo.get(); // Avanza sobre un espacio en blanco. Lo consume y se mueve al siguiente flujo de caracteres
        charFinLinea = archivo.peek(); // revisa si el siguiente caracter es el fin de linea
        
        arregloVrts[contador].lstAdy = lista;
        string x = arregloVrts[contador].lstAdy.toString();
        cout << x << endl;
        contador++;
    }
}

Laberinto::Laberinto(const Laberinto& orig){
}

Laberinto::~Laberinto() {
}

/* MÉTODOS OBSERVADORES BÁSICOS */
bool Laberinto::xstVrt(int idVrt) const {
    bool rsl = false;
    if(0 <= idVrt < cntVrts)
        rsl = true;
    
    return rsl;
}

bool Laberinto::xstAdy(int idVrtO, int idVrtD) const {
    /*
    bool rsl;
    int indice = obtIndiceAdy(idVrtO, idVrtD);
    if (arregloAdys[indice] == 1){
        rsl = true;
    }
    
    return rsl;
    */
}

int Laberinto::obtIdVrtInicial() const {
    return idVrtInicial;
}

int Laberinto::obtIdVrtFinal() const {
    return idVrtFinal;
}

void Laberinto::obtIdVrtAdys(int idVrt, int* rsp) const {

}

Adyacencia Laberinto::obtDatoAdy(int idVrtO, int idVrtD) const {
}

int Laberinto::obtCntAdy(int idVrt) const {
}

int Laberinto::obtTotAdy() const {
}

int Laberinto::obtTotVrt() const {
    return cntVrts;
}

int Laberinto::caminoMasCorto(int idVrtO, int idVrtD, int* camino) const {
}

int Laberinto::caminoEncontrado(int idVrtO, int idVrtD, int* camino) const {
}

double Laberinto::sumaTotalFerormona() const {
}

void Laberinto::asgIdVrtInicial(int idVrtInicialN) {
    idVrtInicial = idVrtInicialN;
}

void Laberinto::asgIdVrtFinal(int idVrtFinalN) {
    idVrtFinal = idVrtFinalN;
}

void Laberinto::asgDatoAdy(int idVrtO, int idVrtD, const Adyacencia& ady) {
}

void Laberinto::decrementarFerormonaAdys(double decrFerormona) {
}

void Laberinto::actualizarValoracionAdys() {
}

int Laberinto::obtIndiceAdy(int f, int c) const {
    if ( f > c){
        int t = f;
        f = c;
        c = t;
    }
    return f * cntVrts + c - f * (f + 1) / 2;
}
