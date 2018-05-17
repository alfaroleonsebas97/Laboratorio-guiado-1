/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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

/*
 * 
 */

int main(int argc, char** argv) {
    /*ifstream archivoEntrada;
    Laberinto laberinto(archivoEntrada);
    Simulador simulador(laberinto);
    int cntAdys = laberinto.obtCntAdy(0);
    int adyacencias[cntAdys];
    laberinto.obtIdVrtAdys(0, adyacencias);*/
    /*ifstream archivo("laberintop.txt");
    if (archivo.is_open()) {
        Laberinto laberinto(archivo);
        int cantidadDeAdyacenciasPorVertice[] = {5,2,5,3,4,4,4,2,4,2};
        for (int j = 0; j < 10; j++) {
            if (cantidadDeAdyacenciasPorVertice[j] != laberinto.obtCntAdy(j)) {
                cout << "cantidad de adyacencias del archivo en el vetice " << j << " es:     " <<cantidadDeAdyacenciasPorVertice[j] <<endl;
                cout << "cantidad de adyacencias del laberinto en el vertice " << j << " es:  " <<laberinto.obtCntAdy(j) <<endl;
                std::cout << "%TEST_FAILED% time=0 testname=testLaberinto2 (Laberinto) message=(Archivo Pequeño)La cantidad de adyacencias del vertice " << j << " no coincide." << std::endl;
            }
        }
    }*/

}