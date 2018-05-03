/* 
 * File:   ListaOrdenada.cpp
 * Author: Alan
 * 
 * Created on 1 de setiembre de 2017, 12:25 PM
 */

#include "ListaOrdenada.h"
#include <sstream> 
#include <iostream>

ListaOrdenada::ListaOrdenada():inicio(nullptr) {
}

ListaOrdenada::ListaOrdenada(const ListaOrdenada& orig){
    shared_ptr<Nodo> p = orig.inicio;
    
    if(p == nullptr){
        inicio = nullptr;
    } else {
        inicio = shared_ptr<Nodo>(new Nodo(orig.inicio->pos));
        p = p->sgt; // inicio->sgt; Causa un error donde solo copia el primer elemento
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
    bool rsl = false;
    shared_ptr<Nodo> p = inicio;
    shared_ptr<Nodo> ant = nullptr;
    
    if(inicio == nullptr){//Se agrega el primer elemento a *this
        inicio = shared_ptr<Nodo>(new Nodo(nPos));
        rsl = true;
    } else if (inicio->pos > nPos){//Insercion antes del inicio
        p = shared_ptr<Nodo>(new Nodo(nPos));
        p->sgt = inicio;
        inicio = p; //se cambia el inicio
        rsl = true;
    } else {
        p = inicio;
        
        while(p != nullptr){
            if (p->pos == nPos){//Se encontro x en *this por lo tanto no se agrega
                p = nullptr;
            } else {//Todavia no se encuentra pero puede que exista
                if(p->pos < nPos){
                    ant = p;
                    p = p->sgt;
                    if(p == nullptr){
                        rsl = true;
                    }
                } else {//se concluye que x no esta en *this
                    p = nullptr;
                    rsl = true;//hay que agragarlo
                }
            }
        }
        
        if(rsl){//Sirve para agragar al medio y al final
           p = ant->sgt;//p podria ser null o cero
           ant->sgt = shared_ptr<Nodo>(new Nodo(nPos));
           ant->sgt->sgt = p;
        }
    }
}

bool ListaOrdenada::buscar(int pos) {
    bool rsl = false;
    shared_ptr<Nodo> p = inicio;
    
    while(p != nullptr){
        if (p->pos == pos){//Se encontro x en *this
            rsl= true;
            p = nullptr;
        } else {//Todavia no se encuentra pero puede que exista
            if(p->pos < pos){
                p = p->sgt;
            } else {//se concluye que x no esta en *this
                p = nullptr;
            }
        }
    }
    
    return rsl;
}

string ListaOrdenada::toString() {
    stringstream fs; //contruye una instancia de flujo de salida
    shared_ptr<Nodo> p = inicio;
    fs << '{';
    
    while(p != nullptr){
        fs << p->pos;
        p = p->sgt;
        if(p != nullptr)
          fs << ','; 
    }
    
    fs << '}';
    return fs.str();
}

int* ListaOrdenada::adyacencias() {
    shared_ptr<Nodo> p = inicio;
    int* arreglo;
    arreglo = new int[cntAdy];
    int indice = 0; //Indice del arreglo
    
    if(p == nullptr){
        arreglo = nullptr; //Puede causar errores en el futuro
    }
    
    while (p != nullptr){
        arreglo[indice] = p->pos;
        indice++;
        p = p->sgt;
    }
    
    return arreglo;//Fuga de memoria
}

int ListaOrdenada::cantidadAdy() {
    int cont = 0;//Contador adyacencias 
    shared_ptr<Nodo> p = inicio;
    
    while(p != nullptr){
        cont++;//Contador suma 1 cifra más
        p = p->sgt;
    }
    
    return cont;//Retorna el contador
}