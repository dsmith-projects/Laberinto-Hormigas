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
    int size = 10;
    memoria = new int[size];
    int contador = 0;
    while(contador <= (size - 1)){
        memoria[contador] = -1;
        contador++;
    } 
}

Hormiga::Hormiga(const Hormiga& orig) {
    destino = orig.destino;
    memoria = orig.memoria;
}

Hormiga::~Hormiga() {
    delete[] memoria; 
}

/* OBSERVADORES */

bool Hormiga::salio() {
    bool rsp;
    if(memoria[1] != -1)
        rsp = true;
    return rsp;
}

bool Hormiga::regreso() {
    bool rsp;
    if((destino == 'I') && (memoria[0] ==idVrtActual)){
        rsp = true;
    }
    return rsp;
}

char Hormiga::obtDestino() {
    return destino;
}

string Hormiga::obtMemoria() {
    int size = 10;
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
    memoria[0] = idVrtInicial;
}

void Hormiga::mover(const Laberinto& lbrt) {
    
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
