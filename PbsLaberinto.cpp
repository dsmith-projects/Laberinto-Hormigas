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

void testLaberinto(int cantidadVrts, double probabilidadAdy) {
    Laberinto laberinto(10,0.3);
    int totalAdy = laberinto.obtTotAdy();
    int totalVrts = laberinto.obtTotVrt();
    int maxAdy = totalVrts*(totalVrts-1);
    if(totalVrts != cantidadVrts) 
        std::cout << "Falló el constructor estándar" << std::endl;
    if(totalAdy > maxAdy)
        std::cout << "Falló el constructor estándar" << std::endl;

}

void testLaberinto2(ifstream& archivo) {
    std::cout << "" << std::endl;
}

void testLaberinto3() {
    std::cout << "" << std::endl;
}

void testXstVrt() {
    std::cout << "" << std::endl;
}

void testXstAdy() {
    std::cout << "" << std::endl;
}

void testObtIdVrtInicial() {
    std::cout << "" << std::endl;
}

void testObtIdVrtFinal() {
    std::cout << "" << std::endl;
}

void testObtIdVrtAdys() {
    std::cout << "" << std::endl;
}

void testObtDatoAdy() {
    std::cout << "" << std::endl;
}

void testObtCntAdy() {
    std::cout << "" << std::endl;
}

void testObtTotAdy() {
    std::cout << "" << std::endl;
}

void testObtTotVrt() {
    std::cout << "" << std::endl;
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

void testAsgIdVrtInicial() {
    std::cout << "" << std::endl;
}

void testAsgIdVrtFinal() {
    std::cout << "" << std::endl;
}

void testAsgDatoAdy() {
    std::cout << "" << std::endl;
}

void testDecrementarFerormonaAdys() {
    std::cout << "" << std::endl;
}

void testActualizarValoracionAdys() {
    std::cout << "" << std::endl;
}

void testObtIndiceAdy() {
    std::cout << "" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
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
    
    std::cout << "%TEST_STARTED% testXstVrt (PbsLaberinto)" << std::endl;
    testXstVrt();
    std::cout << "%TEST_FINISHED% time=0 testXstVrt (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testXstAdy (PbsLaberinto)" << std::endl;
    testXstAdy();
    std::cout << "%TEST_FINISHED% time=0 testXstAdy (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testObtIdVrtInicial (PbsLaberinto)" << std::endl;
    testObtIdVrtInicial();
    std::cout << "%TEST_FINISHED% time=0 testObtIdVrtInicial (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testObtIdVrtFinal (PbsLaberinto)" << std::endl;
    testObtIdVrtFinal;
    std::cout << "%TEST_FINISHED% time=0 testObtIdVrtFinal (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testObtIdVrtAdys (PbsLaberinto)" << std::endl;
    testObtIdVrtAdys();
    std::cout << "%TEST_FINISHED% time=0 testObtIdVrtAdys (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testObtDatoAdy() (PbsLaberinto)" << std::endl;
    testObtDatoAdy();
    std::cout << "%TEST_FINISHED% time=0 testObtDatoAdy() (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testobtCntAdy() (PbsLaberinto)" << std::endl;
    testObtCntAdy();
    std::cout << "%TEST_FINISHED% time=0 testobtCntAdy() (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testObtTotAdy() (PbsLaberinto)" << std::endl;
    testObtTotAdy();
    std::cout << "%TEST_FINISHED% time=0 testObtTotAdy() (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testObtTotVrt (PbsLaberinto)" << std::endl;
    testObtTotVrt();
    std::cout << "%TEST_FINISHED% time=0 testObtTotVrt (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testCaminoMasCorto (PbsLaberinto)" << std::endl;
    testCaminoMasCorto();
    std::cout << "%TEST_FINISHED% time=0 testCaminoMasCorto (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testCaminoEncontrado (PbsLaberinto)" << std::endl;
    testCaminoEncontrado();
    std::cout << "%TEST_FINISHED% time=0 testCaminoEncontrado (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testSumaTotalFerormona (PbsLaberinto)" << std::endl;
    testSumaTotalFerormona();
    std::cout << "%TEST_FINISHED% time=0 testSumaTotalFerormona (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testAsgIdVrtInicial (PbsLaberinto)" << std::endl;
    testAsgIdVrtInicial();
    std::cout << "%TEST_FINISHED% time=0 testAsgIdVrtInicial (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testAsgIdVrtFinal (PbsLaberinto)" << std::endl;
    testAsgIdVrtFinal();
    std::cout << "%TEST_FINISHED% time=0 testAsgIdVrtFinal (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testAsgDatoAdy (PbsLaberinto)" << std::endl;
    testAsgDatoAdy();
    std::cout << "%TEST_FINISHED% time=0 testAsgDatoAdy (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testDecrementarFerormonaAdys (PbsLaberinto)" << std::endl;
    testDecrementarFerormonaAdys();
    std::cout << "%TEST_FINISHED% time=0 testDecrementarFerormonaAdys (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testActualizarValoracionAdys (PbsLaberinto)" << std::endl;
    testActualizarValoracionAdys();
    std::cout << "%TEST_FINISHED% time=0 testActualizarValoracionAdys (PbsLaberinto)" << std::endl;
    
    std::cout << "%TEST_STARTED% testObtIndiceAdy (PbsLaberinto)" << std::endl;
    testObtIndiceAdy();
    std::cout << "%TEST_FINISHED% time=0 testObtIndiceAdy (PbsLaberinto)" << std::endl;
    
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

