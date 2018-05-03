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
    if((cantidadVrts > 0) && (0 < probabilidadAdy) && (probabilidadAdy < 1)){
        cntVrts = cantidadVrts;
        int contador = 0;
        int actual = 0;
        int nRandom;
        arregloVrts = new Vertice[cntVrts];
        arregloAdys = new Adyacencia[cntVrts * (cntVrts + 1) / 2];
        
        srand (time(NULL));
        
        while(actual < cntVrts){
            while(contador < cntVrts){
                nRandom = rand() % 99 + 1;
                if(contador > actual){
                    if(nRandom <= (probabilidadAdy*100)){
                        //cout << nRandom << " " << actual << contador << endl;
                        arregloVrts[contador].lstAdy.agregar(actual);
                        arregloVrts[actual].lstAdy.agregar(contador);
                    }
                }
                contador++;
            }
            contador = 0;
            actual++;
        }
    }    
}


Laberinto::Laberinto(ifstream& archivo){       
    int flujoSalida;
    char charFinLinea = ' ';  
    
    //Linea #1
    archivo >> flujoSalida;
    cntVrts = flujoSalida;  
    arregloAdys = new Adyacencia[cntVrts * (cntVrts + 1 ) / 2];
    arregloVrts = new Vertice[cntVrts];
    int contador = 0;
    idVrtInicial = 0;
    idVrtFinal = cntVrts - 1;
    
    //Linea #2   
    archivo >> flujoSalida; 
    while(!archivo.eof()){
        ListaOrdenada lista;
         
        while(!archivo.eof() && charFinLinea != 10){ 
            lista.agregar(flujoSalida);
            archivo >> flujoSalida;
            archivo.get(); 
            charFinLinea = archivo.peek(); 
        }
        
        if(!archivo.eof())
            lista.agregar(flujoSalida);
        
        archivo >> flujoSalida; 
        archivo.get(); 
        charFinLinea = archivo.peek();        
        arregloVrts[contador].lstAdy = lista;
        contador++;
    }
    if(archivo.eof())
        arregloVrts[contador-1].lstAdy.agregar(flujoSalida);
}

Laberinto::Laberinto(const Laberinto& orig){
    cntVrts = orig.cntVrts;
    idVrtInicial = orig.idVrtInicial;
    idVrtFinal = orig.idVrtFinal;
    arregloVrts = orig.arregloVrts;
    arregloAdys = orig.arregloAdys;
    int contador;
    while(contador < cntVrts){
        arregloVrts[contador].lstAdy = orig.arregloVrts[contador].lstAdy;
        contador++;
    }
}

Laberinto::~Laberinto() {
    delete[] arregloVrts;
    delete[] arregloAdys;
}

/* MÉTODOS OBSERVADORES BÁSICOS */
bool Laberinto::xstVrt(int idVrt) const {
    bool rsl = false;
    if(0 <= idVrt < cntVrts)
        rsl = true;
    
    return rsl;
}

bool Laberinto::xstAdy(int idNdO, int idVrtD) const {
    if((0 <= idNdO) && (idNdO < cntVrts) && (0 <= idVrtD) && (idVrtD < cntVrts)){
        bool rsl;
        int* x = arregloVrts[idNdO].lstAdy.adyacencias();
        int contador = 0;
        
        while(contador < (cntVrts-1)){
            if(x[contador] == idVrtD){
                rsl = true;
                contador = cntVrts;
            }
            contador++;
        }
        return rsl;
    }   
}

int Laberinto::obtIdVrtInicial() const {
    return idVrtInicial;
}

int Laberinto::obtIdVrtFinal() const {
    return idVrtFinal;
}

void Laberinto::obtIdVrtAdys(int idVrt, int*& rsp) const {
    if ((0 <= idVrt) && (idVrt < cntVrts))
        rsp = arregloVrts[idVrt].lstAdy.adyacencias();
}

Adyacencia Laberinto::obtDatoAdy(int idVrtO, int idVrtD) const {
}

int Laberinto::obtCntAdy(int idVrt) const {
    return arregloVrts[idVrt].lstAdy.cantidadAdy();
}

int Laberinto::obtTotAdy() const {
    int rsp = 0;
    int contador = 0;
    for(int contador = 0; contador <= (cntVrts-1); contador++){
        rsp = rsp + arregloVrts[contador].lstAdy.cantidadAdy();
    }
    return rsp/2;
}

int Laberinto::obtTotVrt() const {
    return cntVrts;
}

int Laberinto::caminoMasCorto(int idVrtO, int idVrtD, int*& camino) const {
}

int Laberinto::caminoEncontrado(int idVrtO, int idVrtD, int*& camino) const {
}

double Laberinto::sumaTotalFerormona() const {
}

void Laberinto::asgIdVrtInicial(int idVrtInicialN) {
    if((0 <= idVrtInicialN) && (idVrtInicialN < cntVrts))
        idVrtInicial = idVrtInicialN;
}

void Laberinto::asgIdVrtFinal(int idVrtFinalN) {
    if((0 <= idVrtFinalN) && (idVrtFinalN < cntVrts))
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