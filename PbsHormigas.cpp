/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PbsHormiga.cpp
 * Author: aleja
 *
 * Created on May 2, 2018, 10:37 PM
 */

#include <stdlib.h>
#include <iostream>
#include <Hormiga.h>
#include <Laberinto.h>

/*
 * Simple C++ Test Suite
 */

void testMover() {
    ifstream archivo("laberintop.txt", ios::in);
    Laberinto laberinto(archivo);
    std::cout << "PbsHormiga testMover" << std::endl;
}


int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% PbsHormiga" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testMover (PbsHormiga)" << std::endl;
    testMover();
    std::cout << "%TEST_FINISHED% time=0 testMover (PbsHormiga)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

