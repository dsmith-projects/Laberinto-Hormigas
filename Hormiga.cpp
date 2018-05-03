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

Hormiga::Hormiga(){
    destino = 'F';
    memoria = new int[5];
}

Hormiga::Hormiga(const Hormiga& orig) {
    destino = orig.destino;
}

Hormiga::~Hormiga() {
    delete[] memoria; 
}

/* OBSERVADORES */

bool Hormiga::salio() {
    bool rsp;
    if(haSalido)
        rsp = true;
    return rsp;
}

bool Hormiga::regreso() {
}

char Hormiga::obtDestino() {
    return destino;
}

string Hormiga::obtMemoria() {
    stringstream fs;
    fs << '['; 
    for(int contador = 0; contador <= 4; contador++){
        fs << memoria[contador];
        if(contador != 4)
            fs << ',';
    }        
    fs << ']';
    return fs.str();
}

/* MÉTODOS MODIFICADORES */

void Hormiga::salir(int idVrtInicial) {
}

void Hormiga::mover(const Laberinto& lbrt) {
}

/* MÉTODOS PRIVADOS SUGERIDOS */

void Hormiga::filtraVrtsPosibles(int* vrtsPosibles) {
}

int Hormiga::retroceder() {
}

int Hormiga::seleccionaAdyMasCargada(const Laberinto& lbrt) {
}

bool Hormiga::estaEnMemoria(int idVrt) {
}

void Hormiga::pushMemo() {
}

void Hormiga::popMemo() {
}

void Hormiga::topMemo() {
}
