/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PbsLaberinto.cpp
 * Author: b74429
 *
 * Created on 16 de abril de 2018, 07:56 AM
 */

#include <stdlib.h>
#include <iostream>
#include <Laberinto.h>

/*
 * Simple C++ Test Suite
 */

void testLaberinto() {
    Laberinto laberinto(10,0.3);
    int totalAdy = laberinto.obtTotAdy();
    int totalVrts = laberinto.obtTotVrt();
    int maxAdy = totalVrts*(totalVrts-1);
    if(totalVrts != 10) 
        std::cout << "Falló el constructor estándar" << std::endl;
    
    if(totalAdy > maxAdy)
        std::cout << "Falló el constructor estándar" << std::endl;

}

void testLaberinto2() { 
    Laberinto laberintoP("laberintop.txt");
    Laberinto laberintoM("laberintom.txt");
    int laberintoPVrt = laberintoP.obtTotVrt();
    int laberintoMVrt = laberintoM.obtTotVrt();
    if((laberintoPVrt != 10) || (laberintoPVrt != 50)){
        std::cout << "Fallo el constructor con archivos en cuanto a la cantidad de vertices" << std::endl;
    }
    
    int flujoSalida;
    char charFinLinea = ' '; 
    ifstream archivo("laberintop.txt", ios::in);
    if(!archivo){
        cerr << "No se pudo abrir el archivo de entrada" << endl;
    }
    
    archivo >> flujoSalida;
    int contador = 0;
    
    //Linea #2   
    archivo >> flujoSalida; 
    while(!archivo.eof()){ 
        while(!archivo.eof() && charFinLinea != 10){ 
            contador++;
            archivo >> flujoSalida;
            archivo.get(); 
            charFinLinea = archivo.peek(); 
        }
        
        if(!archivo.eof())
            contador++;
        
        archivo >> flujoSalida; 
        archivo.get(); 
        charFinLinea = archivo.peek();                 
    }
    
    if(archivo.eof())
        contador++;
    
    if(laberintoP.obtTotAdy() != contador)
        std::cout << "Fallo el constructor con archivos en cuanto a la cantidad de adyacencias" << std::endl;
    
    archivo("laberintom.txt", ios::in);
    if(!archivo){
        cerr << "No se pudo abrir el archivo de entrada" << endl;
    }
    
    archivo >> flujoSalida;
    int contador = 0;
    
    //Linea #2   
    archivo >> flujoSalida; 
    while(!archivo.eof()){ 
        while(!archivo.eof() && charFinLinea != 10){ 
            contador++;
            archivo >> flujoSalida;
            archivo.get(); 
            charFinLinea = archivo.peek(); 
        }
        
        if(!archivo.eof())
            contador++;
        
        archivo >> flujoSalida; 
        archivo.get(); 
        charFinLinea = archivo.peek();                 
    }
    
    if(archivo.eof())
        contador++;
    
    if(laberintoM.obtTotAdy() != contador)
        std::cout << "Fallo el constructor con archivos en cuanto a la cantidad de adyacencias" << std::endl;    
}

void testLaberinto3() {
    Laberinto laberinto10(10,0.3);
    Laberinto laberinto100(100,0.3);
    Laberinto laberinto10C(laberinto10);
    Laberinto laberinto100C(laberinto100);
    int vrt10 = laberinto10.obtTotVrt();
    int vrt10C = laberinto10C.obtTotVrt();
    int vrt100 = laberinto100.obtTotVrt();
    int vrt100C = laberinto100C.obtTotVrt();
    int ady10 = laberinto10.obtTotAdy();
    int ady10C = laberinto10C.obtTotAdy();
    int ady100 = laberinto100.obtTotAdy();
    int ady100C = laberinto100C.obtTotAdy();
    if((vrt10 != vrt10C) || (vrt100 != vrt100C))
        std::cout << "Falló el constructor de copias en cuanto a la cantidad de vertices" << std::endl;
    
    if((ady10 != ady10C) || (ady100 != ady100C))
         std::cout << "Falló el constructor de copias en cuanto a la cantidad de adyacencias totales" << std::endl;
}

void testCaminoMasCorto() {
    std::cout << "" << std::endl;
}

void testCaminoEncontrado() {
    std::cout << "" << std::endl;
}

void testSumaTotalFerormona() {
    std::cout << "" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% PbsLaberinto" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testLaberinto (PbsLaberinto)" << std::endl;
    testLaberinto();
    std::cout << "%TEST_FINISHED% time=0 testLaberinto (PbsLaberinto)" << std::endl; 
    
    std::cout << "%TEST_STARTED% testLaberinto2 (PbsLaberinto)" << std::endl;
    testLaberinto2();
    std::cout << "%TEST_FINISHED% time=0 testLaberinto2 (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testLaberinto3 (PbsLaberinto)" << std::endl;
    testLaberinto3();
    std::cout << "%TEST_FINISHED% time=0 testLaberinto3 (PbsLaberinto)" << std::endl;
                 
    std::cout << "%TEST_STARTED% testCaminoMasCorto (PbsLaberinto)" << std::endl;
    testCaminoMasCorto();
    std::cout << "%TEST_FINISHED% time=0 testCaminoMasCorto (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testCaminoEncontrado (PbsLaberinto)" << std::endl;
    testCaminoEncontrado();
    std::cout << "%TEST_FINISHED% time=0 testCaminoEncontrado (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testSumaTotalFerormona (PbsLaberinto)" << std::endl;
    testSumaTotalFerormona();
    std::cout << "%TEST_FINISHED% time=0 testSumaTotalFerormona (PbsLaberinto)" << std::endl;
              
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}
