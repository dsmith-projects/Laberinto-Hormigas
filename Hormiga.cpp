/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hormiga.cpp
 * Author: Alan
 * 
 * Created on 7 de febrero de 2018, 05:53 PM
 */

#include "Hormiga.h"
#include <sstream> 
#include <iostream>

int Hormiga::cntVrts = 0; // inicialización de variable static pública

Hormiga::Hormiga(){
    destino = 'F';
}

Hormiga::Hormiga(const Hormiga& orig) {
    cntVrts = orig.cntVrts;
    idVrtActual = orig.idVrtActual;
    memoria = orig.memoria;
    haSalido = orig.haSalido;
    haRegresado = orig.haRegresado;
    destino = orig.destino;
    enRetroceso = orig.haRegresado;
    longitudSolucion = orig.longitudSolucion;
    deltaFerormona = orig.deltaFerormona;
    ultMemo = orig.ultMemo;
}

Hormiga::~Hormiga() {
    delete[] memoria; 
}

/* OBSERVADORES */

bool Hormiga::salio() {
    bool rsp;
    if(cntVrts > 0)
        rsp = true;
    return rsp;
}

bool Hormiga::regreso() {
    bool rsp;
    if((destino == 'I') && (memoria[0] == idVrtActual)){
        rsp = true;
    }
    return rsp;
}

char Hormiga::obtDestino() {
    return destino;
}

string Hormiga::obtMemoria() {
    int size = cntVrts * (cntVrts + 1) / 2;
    stringstream fs;
    fs << '['; 
    for(int contador = 0; contador < size; contador++){
        fs << memoria[contador];
        if(contador != (size - 1))
            fs << ',';
    }        
    fs << ']';
    return fs.str();
}

/* MÉTODOS MODIFICADORES */

void Hormiga::salir(int idVrtInicial) {
    idVrtActual = idVrtInicial;
    haSalido = true;
    cntVrts++;
}

void Hormiga::mover(const Laberinto& lbrt) {
    if(cntVrts == 0){
        cntVrts = lbrt.obtTotVrt();
        //Crea la memoria
        int size = cntVrts * (cntVrts + 1) / 2;
        memoria = new int[size];
        int contador = 0;
        while(contador <= (size - 1)){
            memoria[contador] = -1;
            contador++;
        }
    }
    
    if((haSalido) && (!haRegresado)){
        if(destino == 'F'){
            ultMemo = idVrtActual;
            memoria[cntVrts] == idVrtActual;
        }else{
        
        }  
    }
}

/* MÉTODOS PRIVADOS SUGERIDOS */

void Hormiga::filtraVrtsPosibles(int* vrtsPosibles) {
    int contador;
    int actual;
    
}

int Hormiga::retroceder() {
}

int Hormiga::seleccionaAdyMasCargada(const Laberinto& lbrt) {
}

bool Hormiga::estaEnMemoria(int idVrt) {
    bool rsp;
    int size = 10;
    for(int contador = 0; (contador < size) && (!rsp) ; contador++){
        if(memoria[contador] == idVrt){
            rsp = true;
        }
    }
    return rsp;
}

void Hormiga::pushMemo() {
}

void Hormiga::popMemo() {
}

void Hormiga::topMemo() {
}
