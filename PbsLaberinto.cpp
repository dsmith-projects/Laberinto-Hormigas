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
    //55000 laberinto con diferencfia +-15
    //Destruir el laberinto para evitar fugas de memoria
    Laberinto laberinto(10,0.3);
    int totalVrts = laberinto.obtTotVrt();
    if(totalVrts != 10) 
        std::cout << "Falló el constructor estándar" << std::endl;
    int totAdy = 0;
    
    for(int contador = 0; contador = 10; contador++){
        Laberinto laberinto2(50,0.3);
        totAdy = totAdy + laberinto2.obtTotAdy();
    }
    double proTest = totAdy/100;
    double proMax = (0.3)*(50)*(50-1);
    double rsl = proMax - proTest;
    
    if(!(-15 < rsl < 15)){
        std::cout << "Falló el constructor estándar en cuanto a la cantidad de adyacencias" << std::endl;
    }
}

void testLaberinto2() { 
    int flujoSalida;
    char charFinLinea = ' '; 
    ifstream archivo("laberintop.txt", ios::in);
    
    archivo >> flujoSalida;
    int contador = 0;
    int contadorVrts = 0;
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
            contadorVrts++;
        
        archivo >> flujoSalida; 
        archivo.get(); 
        charFinLinea = archivo.peek();                 
    }
    
    if(archivo.eof())
        contador++;
    
    if(18 != (contador/2))
        std::cout << "Falló el constructor con archivos en cuanto a la cantidad de adyacencias" << std::endl;
    if(contadorVrts != 10)
        std::cout << "Falló el constructor con archivos en cuanto a la cantidad de vertices" << std::endl;
    
    //LaberintoM
    ifstream archivo2("laberintom.txt", ios::in);
    
    //Linea #1
    archivo2 >> flujoSalida;
    contador = 0;
    contadorVrts = 0;
    
    //Linea #2   
    archivo2 >> flujoSalida; 
    while(!archivo2.eof()){ 
        while(!archivo2.eof() && charFinLinea != 10){ 
            contador++;
            archivo2 >> flujoSalida;
            archivo2.get(); 
            charFinLinea = archivo2.peek(); 
        }
        
        if(!archivo2.eof())
            contador++;
            contadorVrts++;
        
        archivo2 >> flujoSalida; 
        archivo2.get(); 
        charFinLinea = archivo2.peek();                 
    }
    
    if(archivo2.eof())
        contador++;
    
    if(209 != (contador/2))
        std::cout << "Falló el constructor con archivos en cuanto a la cantidad de adyacencias" << std::endl;   
    if(contadorVrts != 50)
        std::cout << "Falló el constructor con archivos en cuanto a la cantidad de vertices" << std::endl;    
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
