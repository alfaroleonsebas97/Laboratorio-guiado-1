/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PbsHormiga.cpp
 * Author: alfar
 *
 * Created on 17 de mayo de 2018, 10:34 AM
 */

#include <stdlib.h>
#include <iostream>
#include "Hormiga.h"

/*
 * Simple C++ Test Suite
 */


void testMover() {
    
    ifstream archivo("LaberintoPruebaCaminoSimple.txt");
    if (archivo.is_open()) {
        Laberinto lbrt(archivo);
        Hormiga hormiga;
        hormiga.salir(0);
        for (int i = 0; i < 4; i++) {
            hormiga.mover(lbrt);
        }
        if ( "{0,1,2,3}" == hormiga.obtMemoria() ) {
            std::cout << "%TEST_FAILED% time=0 testname=testMover (PbsHormiga) message=La hormiga se encicló y no retrocedió" << std::endl;
        }
        archivo.close();
    }

    ifstream archivo2("LaberintoPruebaCaminoEnciclado.txt");
    if (archivo2.is_open()) {
        Laberinto lbrt(archivo2);
        Hormiga hormiga2;
        hormiga2.salir(0);
        for (int i = 0; i < 4; i++) {
            hormiga2.mover(lbrt);
        }
        if ( hormiga2.obtMemoria().size() >= 9  ) {
            std::cout << "%TEST_FAILED% time=0 testname=testMover (PbsHormiga) message=La hormiga se encicló y no retrocedió" << std::endl;
        }
        archivo2.close();
    }
    
    ifstream archivo3("LaberintoPruebaCaminoSimple.txt");
    if (archivo3.is_open()) {
        Laberinto lbrt(archivo3);
        lbrt.asgIdVrtFinal(3);
        Hormiga hormiga3;
        hormiga3.salir(0);
        for (int i = 0; i < 4; i++) {
            hormiga3.mover(lbrt);
        }
        if ( hormiga3.obtMemoria() != "{0,1,2}"  ) {
            std::cout << "%TEST_FAILED% time=0 testname=testMover (PbsHormiga) message=La hormiga no llegó al vértice final" << std::endl;
        }
        archivo3.close();
    }
    
    ifstream archivo4("LaberintoPruebaCaminoSimple.txt");
    if (archivo4.is_open()) {
        Laberinto lbrt(archivo3);
        lbrt.asgIdVrtFinal(3);
        Hormiga hormiga4;
        hormiga4.salir(0);
        for (int i = 0; i < 6; i++) {
            hormiga4.mover(lbrt);
        }
        if ( hormiga4.obtMemoria() != "{}"  ) {
            std::cout << "%TEST_FAILED% time=0 testname=testMover (PbsHormiga) message=La hormiga no regresó" << std::endl;
        }
    }
    archivo4.close();
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

