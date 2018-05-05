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
    double probabilidadAdy = 0.7;
    probabilidadAdy = 0.16 + probabilidadAdy * (0.68); // MIN + P*(MAX-MIN):: MIN = 0.16,  MAX = 0.84
    Laberinto laberinto(cantidadVrts, probabilidadAdy);
    int totVrt = laberinto.obtTotVrt();
    int totAdy = laberinto.obtTotAdy();
    for (int i = 0; i < 50000; ++i) {
        Laberinto laberinto(cantidadVrts, probabilidadAdy);
        totAdy += laberinto.obtTotAdy();
    }
    double promedio = totAdy / 50000.0;
    double media = probabilidadAdy * 50 * (49); //p*n*(n-1), n = 50
    if (totVrt != 50) {
        std::cout << "%TEST_FAILED% time=0 testname=testLaberinto (Laberinto) message=La cantidad total no es igual a 50" << std::endl;
    }
    if (promedio < media - (15)) {
        std::cout << "%TEST_FAILED% time=0 testname=testLaberinto (Laberinto) message=El promedio está más abajo de la media esperada" << std::endl;
    }
    if (promedio > media + (15)) {
        std::cout << "%TEST_FAILED% time=0 testname=testLaberinto (Laberinto) message=El promedio está más arriba de la media esperada" << std::endl;
    }
}

void testLaberinto2() {
    ifstream archivo("laberintop.txt");
    if (archivo.is_open()) {
        int cantidadDeVerticesEnElArchivo;
        string hileraActual;
        getline(archivo, hileraActual);

        cantidadDeVerticesEnElArchivo = stoi(hileraActual);
        int cantidadDeAdyacenciasPorVertice[10];
        int NumeroDeLinea = 0;

        while (getline(archivo, hileraActual)) {
            int contadorEspaciosEnBlanco = 0;
            int indiceDeLaHilera = 0;
            while (hileraActual[indiceDeLaHilera] != '\r') {
                if (hileraActual[indiceDeLaHilera] == ' ') {
                    contadorEspaciosEnBlanco++;
                }
                indiceDeLaHilera++;
            }
            cantidadDeAdyacenciasPorVertice[NumeroDeLinea] = contadorEspaciosEnBlanco;
            NumeroDeLinea++;
        }

        archivo.close();
        ifstream archivo2("laberintop.txt");
        if (archivo2.is_open()) {
            Laberinto laberinto2(archivo2);
            if (cantidadDeVerticesEnElArchivo != laberinto2.obtTotVrt()) {
                std::cout << "%TEST_FAILED% time=0 testname=testLaberinto2 (Laberinto) message=(Archivo Pequeño)Cantidad de vertices total no coincide." << std::endl;
            }
            for (int j = 0; j < 10; j++) {
                if (cantidadDeAdyacenciasPorVertice[j] != laberinto2.obtCntAdy(j)) {
                    std::cout << "%TEST_FAILED% time=0 testname=testLaberinto2 (Laberinto) message=(Archivo Pequeño)La cantidad de adyacencias del vertice " << j << " no coincide." << std::endl;
                }
            }
            archivo2.close();
        }
    } else {
        cout << "No se pudo abrir el archivo de entrada" << endl;
    }
}

void testLaberinto3() {
    ifstream archivo("laberintop.txt");
    if (archivo.is_open()) {
        Laberinto laberintoOriginal(archivo);
        Laberinto laberintoCopia(laberintoOriginal);
        int cantidadDeVertices;
        cantidadDeVertices = laberintoCopia.obtTotVrt();
        if (cantidadDeVertices != 10) {
            std::cout << "%TEST_FAILED% time=0 testname=testLaberinto3 (Laberinto) message=la cantidad de vertices no coinciden" << std::endl;
        } else {
            for (int i = 0; i < 10; i++) {
                if (laberintoOriginal.obtCntAdy(i) != laberintoCopia.obtCntAdy(i)) {
                    std::cout << "%TEST_FAILED% time=0 testname=testLaberinto3 (Laberinto) message=la cantidad de adyacencias no coinciden en el vertice: " << i << std::endl;
                }
            }
        }
        archivo.close();
    }
}

void testCaminoMasCorto() {
    //tres pruebas.1,2,3.
    //sin cola de prioridad Dijkstra en 
    //int idVrtO;
    //int idVrtD;
    //int* camino;
    //Laberinto laberinto;
    //int result = laberinto.caminoMasCorto(idVrtO, idVrtD, camino);
    //if (true) {
    //    std::cout << "%TEST_FAILED% time=0 testname=testCaminoMasCorto (Laberinto) message=error message sample" << std::endl;
    //}
}

void testCaminoEncontrado() {
    //int idVrtO;
    //int idVrtD;
    //int* camino;
    //Laberinto laberinto;
    //int result = laberinto.caminoEncontrado(idVrtO, idVrtD, camino);
    //if (true) {
    //  std::cout << "%TEST_FAILED% time=0 testname=testCaminoEncontrado (Laberinto) message=error message sample" << std::endl;
    //}
}

void testSumaTotalFerormona() {
    //asignar un 1 a la ferormona de todas las aristas que existen en el laberinto.
    //suma total = total de adyacencias.
    ifstream archivo("laberintop.txt");
    if (archivo.is_open()) {
        Laberinto laberinto("laberintop.txt");
        int cntVrts = laberinto.obtTotVrt();
        int cntAdy;
        Adyacencia ady( 1.0, 1.0 );
        int rsp;
        for (int verticeOrigen = 0; verticeOrigen < cntVrts; verticeOrigen++) {
            cntAdy = laberinto.obtCntAdy(verticeOrigen);
            for (int verticeDestino = 0; verticeDestino < cntAdy; verticeDestino++) {
                rsp = laberinto.obtIdVrtAdys(verticeDestino);
                laberinto.asgDatoAdy(verticeOrigen, rsp, ady);
            }
        }
        archivo.close();
        if ( laberinto.sumaTotalFerormona() != laberinto.obtTotAdy() ) {
            std::cout << "%TEST_FAILED% time=0 testname=testSumaTotalFerormona (Laberinto) message=error message sample" << std::endl;
        }
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% Laberinto" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    //std::cout << "%TEST_STARTED% testLaberinto (Laberinto)" << std::endl;
    //testLaberinto();
    //std::cout << "%TEST_FINISHED% time=0 testLaberinto (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testLaberinto2 (Laberinto)" << std::endl;
    testLaberinto2();
    std::cout << "%TEST_FINISHED% time=0 testLaberinto2 (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testLaberinto3 (Laberinto)" << std::endl;
    testLaberinto3();
    std::cout << "%TEST_FINISHED% time=0 testLaberinto3 (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testCaminoMasCorto (Laberinto)" << std::endl;
    testCaminoMasCorto();
    std::cout << "%TEST_FINISHED% time=0 testCaminoMasCorto (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testCaminoEncontrado (Laberinto)" << std::endl;
    testCaminoEncontrado();
    std::cout << "%TEST_FINISHED% time=0 testCaminoEncontrado (Laberinto)" << std::endl;

    std::cout << "%TEST_STARTED% testSumaTotalFerormona (Laberinto)" << std::endl;
    testSumaTotalFerormona();
    std::cout << "%TEST_FINISHED% time=0 testSumaTotalFerormona (Laberinto)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

