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

void testHormiga() {
    Hormiga hormiga();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testHormiga (PbsHormiga) message=error message sample" << std::endl;
    }
}

void testHormiga2() {
    const Hormiga& orig;
    Hormiga hormiga(orig);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testHormiga2 (PbsHormiga) message=error message sample" << std::endl;
    }
}

void testSalio() {
    Hormiga hormiga;
    bool result = hormiga.salio();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSalio (PbsHormiga) message=error message sample" << std::endl;
    }
}

void testRegreso() {
    Hormiga hormiga;
    bool result = hormiga.regreso();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testRegreso (PbsHormiga) message=error message sample" << std::endl;
    }
}

void testObtDestino() {
    Hormiga hormiga;
    char result = hormiga.obtDestino();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testObtDestino (PbsHormiga) message=error message sample" << std::endl;
    }
}

void testObtMemoria() {
    Hormiga hormiga;
    string result = hormiga.obtMemoria();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testObtMemoria (PbsHormiga) message=error message sample" << std::endl;
    }
}

void testSalir() {
    int idVrtInicial;
    Hormiga hormiga;
    hormiga.salir(idVrtInicial);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSalir (PbsHormiga) message=error message sample" << std::endl;
    }
}

void testMover() {
    
    ifstream archivo("LaberintoPruebaCaminoSinSalida.txt");
    if (archivo.is_open()) {
        Laberinto lbrt(archivo);
        Hormiga hormiga;
        hormiga.salir();
        for (int i = 0; i < 4; i++) {
            hormiga.mover(lbrt);
        }
        if ( "{0,1,2,3}" == hormiga.obtMemoria() ) {
            std::cout << "%TEST_FAILED% time=0 testname=testMover (PbsHormiga) message=La hormiga se encicló y no retrocedió" << std::endl;
        }
    }

    ifstream archivo2("LaberintoPruebaCaminoEnciclado.txt");
    if (archivo2.is_open()) {
        Laberinto lbrt(archivo2);
        Hormiga hormiga2;
        hormiga2.salir();
        for (int i = 0; i < 4; i++) {
            hormiga2.mover(lbrt);
        }
        if ( hormiga2.obtMemoria().size() >= 9  ) {
            std::cout << "%TEST_FAILED% time=0 testname=testMover (PbsHormiga) message=La hormiga se encicló y no retrocedió" << std::endl;
        }
    }
    
    /*if () {
        std::cout << "%TEST_FAILED% time=0 testname=testMover (PbsHormiga) message=La hormiga no llegó al vértice final" << std::endl;
    }*/
    
    ifstream archivo3("LaberintoPruebaHaRegresado.txt");
    if (archivo3.is_open()) {
        Laberinto lbrt(archivo3);
        Hormiga hormiga3;
        hormiga3.salir();
        for (int i = 0; i < 6; i++) {
            hormiga3.mover(lbrt);
        }
        if ( hormiga3.obtMemoria() != "{}"  ) {
            std::cout << "%TEST_FAILED% time=0 testname=testMover (PbsHormiga) message=La hormiga no regresó" << std::endl;
        }
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% PbsHormiga" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testHormiga (PbsHormiga)" << std::endl;
    testHormiga();
    std::cout << "%TEST_FINISHED% time=0 testHormiga (PbsHormiga)" << std::endl;

    std::cout << "%TEST_STARTED% testHormiga2 (PbsHormiga)" << std::endl;
    testHormiga2();
    std::cout << "%TEST_FINISHED% time=0 testHormiga2 (PbsHormiga)" << std::endl;

    std::cout << "%TEST_STARTED% testSalio (PbsHormiga)" << std::endl;
    testSalio();
    std::cout << "%TEST_FINISHED% time=0 testSalio (PbsHormiga)" << std::endl;

    std::cout << "%TEST_STARTED% testRegreso (PbsHormiga)" << std::endl;
    testRegreso();
    std::cout << "%TEST_FINISHED% time=0 testRegreso (PbsHormiga)" << std::endl;

    std::cout << "%TEST_STARTED% testObtDestino (PbsHormiga)" << std::endl;
    testObtDestino();
    std::cout << "%TEST_FINISHED% time=0 testObtDestino (PbsHormiga)" << std::endl;

    std::cout << "%TEST_STARTED% testObtMemoria (PbsHormiga)" << std::endl;
    testObtMemoria();
    std::cout << "%TEST_FINISHED% time=0 testObtMemoria (PbsHormiga)" << std::endl;

    std::cout << "%TEST_STARTED% testSalir (PbsHormiga)" << std::endl;
    testSalir();
    std::cout << "%TEST_FINISHED% time=0 testSalir (PbsHormiga)" << std::endl;

    std::cout << "%TEST_STARTED% testMover (PbsHormiga)" << std::endl;
    testMover();
    std::cout << "%TEST_FINISHED% time=0 testMover (PbsHormiga)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

