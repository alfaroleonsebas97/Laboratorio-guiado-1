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
    ifstream archivoEntrada;
    Laberinto laberinto(archivoEntrada);
    Simulador simulador(laberinto);
    int cntAdys = laberinto.obtCntAdy(0);
    int adyacencias[cntAdys];
    laberinto.obtIdVrtAdys(0, adyacencias);
    return 0;
}

