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
    int pe;
    ifstream archivoEnterosEntrada("laberintop.txt", ios::in);
    char finLinea = ' ';

    if (!archivoEnterosEntrada) { // operador ! sobrecargado
        cerr << "No se pudo abrir el archivo de entrada" << endl;
    }

    archivoEnterosEntrada >> pe;
    cout << pe << endl;
    
    // salta a la siguiente para leer el primer número de la línea #2
    archivoEnterosEntrada >> pe;
    while (!archivoEnterosEntrada.eof()) {
        while (!archivoEnterosEntrada.eof()&&(finLinea != 10)) { // 10 ascii de fin de línea
            cout << pe << ' ';
            archivoEnterosEntrada >> pe;
            archivoEnterosEntrada.get(); // consume un blanco
            finLinea = archivoEnterosEntrada.peek(); // intenta leer fin de línea
        }
        if (!archivoEnterosEntrada.eof())
            cout << pe << endl;
        archivoEnterosEntrada >> pe;
        archivoEnterosEntrada.get();
        finLinea = archivoEnterosEntrada.peek();
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
     * bool rsl;
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
