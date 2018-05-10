/* 
 * File:   main.cpp
 * Author: alan.calderon
 *
 * Created on 2 de abril de 2018, 10:31 AM
 */

#include <fstream>
#include <iostream>
using namespace std;

#include "Laberinto.h"
#include "Simulador.h"
#include "Hormiga.h"

/*
 * 
 */
int main(int argc, char** argv) {
    /*
    ifstream archivoEntrada;
    Laberinto laberinto(archivoEntrada);
    Simulador simulador(laberinto);
    int cntAdys = laberinto.obtCntAdy(0);
    int adyacencias[cntAdys];
    laberinto.obtIdVrtAdys(0, adyacencias);
     */
    ifstream archivo("laberintop.txt", ios::in);
    if(!archivo){
        cerr << "No se pudo abrir el archivo de entrada" << endl;
        return 1;
    }
    //Laberinto laberinto(archivo);
    //Laberinto laberinto2(10,0.3);
    Hormiga hormigaTest;
    string x = hormigaTest.obtMemoria();
    cout << x << endl;
    return 0;
}
