/* 
 * File:   Digrafo.cpp
 * Author: Alan
 * 
 * Created on 1 de setiembre de 2017, 12:25 PM
 */

#include "ListaOrdenada.h"

ListaOrdenada::ListaOrdenada():inicio(nullptr) {

}

ListaOrdenada::ListaOrdenada(const ListaOrdenada& orig){
    shared_ptr<Nodo> p = orig.inicio;
    
    if(p == nullptr){
        inicio = nullptr;
    } else {
        inicio = shared_ptr<Nodo>(new Nodo(orig.inicio->pos));
        p = inicio->sgt; // vertice->sgt;
        shared_ptr<Nodo> ultimo = inicio;
        
        while(p != nullptr){
            ultimo->sgt = shared_ptr<Nodo>(new Nodo(p->pos));
            p = p->sgt;
            ultimo = ultimo->sgt;
        }
    }
}

ListaOrdenada::~ListaOrdenada() {

}

void ListaOrdenada::agregar(int nPos) {

}

bool ListaOrdenada::buscar(int pos) {

}

string ListaOrdenada::toString() {

}

int* ListaOrdenada::adyacencias() {
    
}

int ListaOrdenada::cantidadAdy() {
    
}