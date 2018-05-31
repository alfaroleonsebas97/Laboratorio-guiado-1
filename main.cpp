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
    ifstream archivo("laberintop.txt");
    if (archivo.is_open()) {
        Laberinto laberinto(archivo);
        cout<< "ingresar p pasos de simulación: " <<endl;
        cout<< "ingresar vértice inicial: " <<endl;
        cout<< "ingresar vértice final: " <<endl;
        cout<< "ingresar cantidad de hormigas en la colonia: " <<endl;
        cout<< "ingresar decrFerormona: " <<endl;
        cout<< "ingresar probMovimientoAzar: " <<endl;
        int p = 5;
        int vrtOrigen = 0;
        int vrtFinal = 4;
        int cntHormigas = 10;
        double decrFerormona = 0.1;
        double probMovimientoAzar = 0.1;
        Simulador simulador(laberinto);
        simulador.iniciar(vrtOrigen, vrtOrigen, cntHormigas, decrFerormona, probMovimientoAzar);
        simulador.ejecutar(p);
        //int cntAdys = laberinto.obtCntAdy(0);
        //int adyacencias[cntAdys];
        //laberinto.obtIdVrtAdys(0, adyacencias);
    }
    archivo.close();
    return 0;
}