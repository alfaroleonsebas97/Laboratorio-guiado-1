/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Laberinto.cpp
 * Author: alfar
 *
 * Created on 20 de abril de 2018, 07:13 PM
 */

#include <stdlib.h>
#include <iostream>
#include "Laberinto.h"
#include <cstdlib>
#include <fstream>
#include <string>


/*
 * Simple C++ Test Suite
 */

void testLaberinto() {
    int cantidadVrts = 50;
    double probabilidadAdy = (double) rand() / RAND_MAX;
    probabilidadAdy = 0.11 + probabilidadAdy * (0.78); // MIN + P*(MAX-MIN):: MIN = 0.11,  MAX = 0.89
    Laberinto laberinto(cantidadVrts, probabilidadAdy);
    int totVrt = laberinto.obtTotVrt();
    int totAdy = laberinto.obtTotAdy();
    for (int i = 0; i < 100; ++i) {
        Laberinto laberinto(cantidadVrts, probabilidadAdy);
        totAdy += laberinto.obtTotAdy();
    }
    double promedio = totAdy / 100.0;
    double media =  probabilidadAdy*50*(49);
    if (totVrt != 50 || ((promedio < media-(0.1)) || (promedio > media + (0.1)))) {
        std::cout << "%TEST_FAILED% time=0 testname=testLaberinto (Laberinto) message=error message sample" << std::endl;
    }
}

void testLaberinto2() {
    ifstream archivo("laberintop.txt");
        if (!archivo) { // operador ! sobrecargado
        cout<< "No se pudo abrir el archivo de entrada" << endl;
    }
    Laberinto laberinto2(archivo);
    archivo.open("laberintop.txt");
    string totalDeNodos;
    getline(archivo, totalDeNodos);
    //int cntTtlVrt = stoi(totalDeNodos);
    //int totVrt = laberinto2.obtTotVrt();
    //if (cntTtlVrt != totVrt) {
    //    std::cout << "%TEST_FAILED% time=0 testname=testLaberinto2 (Laberinto) message=error message sample" << std::endl;
    //}
    int nodoAdy;
    string adyacencias,nodoDeAdy;
    int i;
    int vertice = 0;
    bool existenciaDeAdyacencia;
    while(getline(archivo,adyacencias)){
        i = 0;
        while(adyacencias[i] != '\n'){
            if(adyacencias[i] != ' '){
                nodoDeAdy += adyacencias[i];
                cout <<nodoDeAdy + "," ;
            }else{
                nodoAdy = stoi(nodoDeAdy);
                nodoDeAdy="";
                //existenciaDeAdyacencia = laberinto2.xstAdy(vertice,nodoAdy);
                //if (!existenciaDeAdyacencia){
                //    std::cout << "%TEST_FAILED% time=0 testname=testLaberinto2 (Laberinto) message=error message sample" << std::endl;
                //}
            }
            i++;
        }
        cout << endl;
        vertice++;
    }
        archivo.close();
}

void testLaberinto3() {
    //const Laberinto& orig;
    //Laberinto laberinto(orig);
    //if (true /*check result*/) {
    //    std::cout << "%TEST_FAILED% time=0 testname=testLaberinto3 (Laberinto) message=error message sample" << std::endl;
    //}
}

void testXstVrt() {
    int idVrt;
    //Laberinto laberinto;
    //bool result = laberinto.xstVrt(idVrt);
    //if (true /*check result*/) {
     //   std::cout << "%TEST_FAILED% time=0 testname=testXstVrt (Laberinto) message=error message sample" << std::endl;
    //}
}

void testXstAdy() {
    /*int idNdO;
    int idVrtD;
    Laberinto laberinto;
    bool result = laberinto.xstAdy(idNdO, idVrtD);
    if (true) {
        std::cout << "%TEST_FAILED% time=0 testname=testXstAdy (Laberinto) message=error message sample" << std::endl;
    }*/
}

void testObtIdVrtInicial() {
    /*Laberinto laberinto;
    int result = laberinto.obtIdVrtInicial();
    if (true) {
        std::cout << "%TEST_FAILED% time=0 testname=testObtIdVrtInicial (Laberinto) message=error message sample" << std::endl;
    }*/
}

void testObtIdVrtFinal() {
    /*Laberinto laberinto;
    int result = laberinto.obtIdVrtFinal();
    if (true) {
        std::cout << "%TEST_FAILED% time=0 testname=testObtIdVrtFinal (Laberinto) message=error message sample" << std::endl;
    }*/
}

void testObtIdVrtAdys() {
    /*int idVrt;
    int* rsp;
    Laberinto laberinto;
    laberinto.obtIdVrtAdys(idVrt, rsp);
    if (true) {
        std::cout << "%TEST_FAILED% time=0 testname=testObtIdVrtAdys (Laberinto) message=error message sample" << std::endl;
    }*/
}

void testObtDatoAdy() {
    /*int idVrtO;
    int idVrtD;
    Laberinto laberinto;
    Adyacencia result = laberinto.obtDatoAdy(idVrtO, idVrtD);
    if (true) {
        std::cout << "%TEST_FAILED% time=0 testname=testObtDatoAdy (Laberinto) message=error message sample" << std::endl;
    }*/
}

void testObtCntAdy() {
    /*int idVrt;
    Laberinto laberinto;
    int result = laberinto.obtCntAdy(idVrt);
    if (true) {
        std::cout << "%TEST_FAILED% time=0 testname=testObtCntAdy (Laberinto) message=error message sample" << std::endl;
    }*/
}

void testObtTotAdy() {
    /*Laberinto laberinto;
    int result = laberinto.obtTotAdy();
    if (true) {
        std::cout << "%TEST_FAILED% time=0 testname=testObtTotAdy (Laberinto) message=error message sample" << std::endl;
    }*/
}

void testObtTotVrt() {
    /*Laberinto laberinto;
    int result = laberinto.obtTotVrt();
    if (true) {
        std::cout << "%TEST_FAILED% time=0 testname=testObtTotVrt (Laberinto) message=error message sample" << std::endl;
    }*/
}

void testCaminoMasCorto() {
    /*int idVrtO;
    int idVrtD;
    int* camino;
    Laberinto laberinto;
    int result = laberinto.caminoMasCorto(idVrtO, idVrtD, camino);
    if (true) {
        std::cout << "%TEST_FAILED% time=0 testname=testCaminoMasCorto (Laberinto) message=error message sample" << std::endl;
    }*/
}

void testCaminoEncontrado() {
    /*int idVrtO;
    int idVrtD;
    int* camino;
    Laberinto laberinto;
    int result = laberinto.caminoEncontrado(idVrtO, idVrtD, camino);
    if (true) {
        std::cout << "%TEST_FAILED% time=0 testname=testCaminoEncontrado (Laberinto) message=error message sample" << std::endl;
    }*/
}

void testSumaTotalFerormona() {
    /*Laberinto laberinto;
    double result = laberinto.sumaTotalFerormona();
    if (true) {
        std::cout << "%TEST_FAILED% time=0 testname=testSumaTotalFerormona (Laberinto) message=error message sample" << std::endl;
    }*/
}

void testAsgIdVrtInicial() {
    /*int idVrtInicialN;
    Laberinto laberinto;
    laberinto.asgIdVrtInicial(idVrtInicialN);
    if (true) {
        std::cout << "%TEST_FAILED% time=0 testname=testAsgIdVrtInicial (Laberinto) message=error message sample" << std::endl;
    }*/
}

void testAsgIdVrtFinal() {
    /*int idVrtFinalN;
    Laberinto laberinto;
    laberinto.asgIdVrtFinal(idVrtFinalN);
    if (true) {
        std::cout << "%TEST_FAILED% time=0 testname=testAsgIdVrtFinal (Laberinto) message=error message sample" << std::endl;
    }*/
}

void testAsgDatoAdy() {
    /*int idVrtO;
    int idVrtD;
    const Adyacencia& ady;
    Laberinto laberinto;
    laberinto.asgDatoAdy(idVrtO, idVrtD, ady);
    if (true) {
        std::cout << "%TEST_FAILED% time=0 testname=testAsgDatoAdy (Laberinto) message=error message sample" << std::endl;
    }*/
}

void testDecrementarFerormonaAdys() {
    /*double decrFerormona;
    Laberinto laberinto;
    laberinto.decrementarFerormonaAdys(decrFerormona);
    if (true) {
        std::cout << "%TEST_FAILED% time=0 testname=testDecrementarFerormonaAdys (Laberinto) message=error message sample" << std::endl;
    }*/
}

void testActualizarValoracionAdys() {
    /*Laberinto laberinto;
    laberinto.actualizarValoracionAdys();
    if (true) {
        std::cout << "%TEST_FAILED% time=0 testname=testActualizarValoracionAdys (Laberinto) message=error message sample" << std::endl;
    }*/
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% Laberinto" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testLaberinto (Laberinto)" << std::endl;
    testLaberinto();
    std::cout << "%TEST_FINISHED% time=0 testLaberinto (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testLaberinto2 (Laberinto)" << std::endl;
    testLaberinto2();
    std::cout << "%TEST_FINISHED% time=0 testLaberinto2 (Laberinto)" << std::endl;

     /*std::cout << "%TEST_STARTED% testLaberinto3 (Laberinto)" << std::endl;
    testLaberinto3();
    std::cout << "%TEST_FINISHED% time=0 testLaberinto3 (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testXstVrt (Laberinto)" << std::endl;
    testXstVrt();
    std::cout << "%TEST_FINISHED% time=0 testXstVrt (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testXstAdy (Laberinto)" << std::endl;
    testXstAdy();
    std::cout << "%TEST_FINISHED% time=0 testXstAdy (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testObtIdVrtInicial (Laberinto)" << std::endl;
    testObtIdVrtInicial();
    std::cout << "%TEST_FINISHED% time=0 testObtIdVrtInicial (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testObtIdVrtFinal (Laberinto)" << std::endl;
    testObtIdVrtFinal();
    std::cout << "%TEST_FINISHED% time=0 testObtIdVrtFinal (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testObtIdVrtAdys (Laberinto)" << std::endl;
    testObtIdVrtAdys();
    std::cout << "%TEST_FINISHED% time=0 testObtIdVrtAdys (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testObtDatoAdy (Laberinto)" << std::endl;
    testObtDatoAdy();
    std::cout << "%TEST_FINISHED% time=0 testObtDatoAdy (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testObtCntAdy (Laberinto)" << std::endl;
    testObtCntAdy();
    std::cout << "%TEST_FINISHED% time=0 testObtCntAdy (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testObtTotAdy (Laberinto)" << std::endl;
    testObtTotAdy();
    std::cout << "%TEST_FINISHED% time=0 testObtTotAdy (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testObtTotVrt (Laberinto)" << std::endl;
    testObtTotVrt();
    std::cout << "%TEST_FINISHED% time=0 testObtTotVrt (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testCaminoMasCorto (Laberinto)" << std::endl;
    testCaminoMasCorto();
    std::cout << "%TEST_FINISHED% time=0 testCaminoMasCorto (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testCaminoEncontrado (Laberinto)" << std::endl;
    testCaminoEncontrado();
    std::cout << "%TEST_FINISHED% time=0 testCaminoEncontrado (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testSumaTotalFerormona (Laberinto)" << std::endl;
    testSumaTotalFerormona();
    std::cout << "%TEST_FINISHED% time=0 testSumaTotalFerormona (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testAsgIdVrtInicial (Laberinto)" << std::endl;
    testAsgIdVrtInicial();
    std::cout << "%TEST_FINISHED% time=0 testAsgIdVrtInicial (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testAsgIdVrtFinal (Laberinto)" << std::endl;
    testAsgIdVrtFinal();
    std::cout << "%TEST_FINISHED% time=0 testAsgIdVrtFinal (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testAsgDatoAdy (Laberinto)" << std::endl;
    testAsgDatoAdy();
    std::cout << "%TEST_FINISHED% time=0 testAsgDatoAdy (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testDecrementarFerormonaAdys (Laberinto)" << std::endl;
    testDecrementarFerormonaAdys();
    std::cout << "%TEST_FINISHED% time=0 testDecrementarFerormonaAdys (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testActualizarValoracionAdys (Laberinto)" << std::endl;
    testActualizarValoracionAdys();
    std::cout << "%TEST_FINISHED% time=0 testActualizarValoracionAdys (Laberinto)" << std::endl;*/

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

