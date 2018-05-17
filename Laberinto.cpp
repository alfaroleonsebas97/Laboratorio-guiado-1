/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Laberinto.cpp
 * Author: Alan
 * 
 * Created on 7 de febrero de 2018, 04:46 PM
 */

#include "Laberinto.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <climits>

Laberinto::Laberinto(int cantidadVrts, double probabilidadAdy) {
    cntVrts = cantidadVrts;
    idVrtInicial = -1;
    idVrtFinal = -1;
    arregloVrts = new Vertice[cntVrts];
    arregloAdys = new Adyacencia[cntVrts * (cntVrts + 1) / 2];

    for (int k = 0; k < (cntVrts * (cntVrts + 1) / 2); k++) {
        arregloAdys[k].asgValoracion(-1.0);
        arregloAdys[k].asgCntFerormona(-1.0);
    }

    double numeroAleatorio = 0.0;
    srand(time(NULL));
    for (int i = 0; i < cntVrts; i++) {
        for (int j = i + 1; j < cntVrts; j++) {
            numeroAleatorio = (rand() % 1000 + 1) / 1000.0;
            if (numeroAleatorio <= probabilidadAdy) {
                arregloVrts[i].lstAdy.agregar(j);
                arregloVrts[j].lstAdy.agregar(i);
            }
        }
    }
}

Laberinto::Laberinto(ifstream& archivo) {
    idVrtInicial = -1;
    idVrtFinal = -1;
    string hileraActual;
    getline(archivo, hileraActual);
    cntVrts = stoi(hileraActual);
    arregloAdys = new Adyacencia[cntVrts * (cntVrts + 1) / 2];

    for (int k = 0; k < (cntVrts * (cntVrts + 1) / 2); k++) {
        arregloAdys[k].asgValoracion(-1.0);
        arregloAdys[k].asgCntFerormona(-1.0);
    }

    arregloVrts = new Vertice[cntVrts];
    int numeroDeAdyacencia;
    string hileraTemporal;
    int numeroDeLinea = 0;
    while (getline(archivo, hileraActual)) {
        int i = 0;
        while (hileraActual[i] != '\r') {
            if (hileraActual[i] != ' ') {
                hileraTemporal += hileraActual[i];
            } else {
                numeroDeAdyacencia = stoi(hileraTemporal);
                hileraTemporal = "";
                arregloVrts[numeroDeLinea].lstAdy.agregar(numeroDeAdyacencia);
            }
            i++;
        }
        numeroDeLinea++;
    }
}

Laberinto::Laberinto(const Laberinto& orig) {
    cntVrts = orig.cntVrts;
    idVrtInicial = -1;
    idVrtFinal = -1;
    arregloAdys = new Adyacencia[cntVrts * (cntVrts + 1) / 2];

    for (int k = 0; k < (cntVrts * (cntVrts + 1) / 2); k++) {
        arregloAdys[k].asgValoracion(-1.0);
        arregloAdys[k].asgCntFerormona(-1.0);
    }

    arregloVrts = new Vertice[cntVrts];
    for (int i = 0; i < cntVrts; i++) {
        arregloVrts[i].lstAdy = orig.arregloVrts[i].lstAdy;
    }
}

Laberinto::~Laberinto() {
    delete[] arregloVrts;
    delete[] arregloAdys;

}

/* MÉTODOS OBSERVADORES BÁSICOS */
bool Laberinto::xstVrt(int idVrt) const {
    return ( (0 <= idVrt) && (idVrt < cntVrts)); //retorna true si el vertice existe o está entre 0 y n;
}

bool Laberinto::xstAdy(int idVrtO, int idVrtD) const {
    bool adyacencia = false;
    if ((xstVrt(idVrtO)) && (xstVrt(idVrtD))) {
        adyacencia = arregloVrts[idVrtO].lstAdy.buscar(idVrtD);
    }
    return adyacencia;
}

int Laberinto::obtIdVrtInicial() const {
    return idVrtInicial;
}

int Laberinto::obtIdVrtFinal() const {
    return idVrtFinal;
}

void Laberinto::obtIdVrtAdys(int idVrt, int*& rsp) const {
    if (xstVrt(idVrt)) {
        rsp = arregloVrts[idVrt].lstAdy.adyacencias();
    }
}

Adyacencia Laberinto::obtDatoAdy(int idVrtO, int idVrtD) const {
    Adyacencia result;
    if ((xstVrt(idVrtO)) && (xstVrt(idVrtD)));
    {
        if (xstAdy(idVrtO, idVrtD)) {
            int k = obtIndiceAdy(idVrtO, idVrtD);
            result = arregloAdys[k];
        }
    }
    return result;
}

int Laberinto::obtCntAdy(int idVrt) const {
    int cantidadDeAdyacencias = -1;
    if (xstVrt(idVrt)) {
        cantidadDeAdyacencias = arregloVrts[idVrt].lstAdy.cantidadAdy();
    }
    return cantidadDeAdyacencias;
}

int Laberinto::obtTotAdy() const {
    int cntTtlAdy = -1;
    for (int i = 0; i < cntVrts; i++) {
        cntTtlAdy += arregloVrts[i].lstAdy.cantidadAdy();
        ;
    }
    return cntTtlAdy;
}

int Laberinto::obtTotVrt() const {
    return cntVrts;
}

int Laberinto::caminoMasCorto(int idVrtO, int idVrtD, int*& camino) const {
    int size = -1;
    if (xstVrt(idVrtO) && xstVrt(idVrtD)) {
        int distancia[cntVrts];
        bool visto[cntVrts];
        for (bool& index: visto) {
            index = false;
        }
        int antecesores[cntVrts];
        for (int i = 0; i < cntVrts; i++) {
            if (!xstAdy(idVrtO, i)) {
                distancia[i] = INT_MAX;
                antecesores[i] = -2;
            } else {
                distancia[i] = 1;
                antecesores[i] = idVrtO;
            }
        }
        distancia[idVrtO] = 0;
        antecesores[idVrtO] = -1;
        visto[idVrtO] = true;

        while (visto[idVrtD] == false) {
            
            //tomar_el_mínimo_del_vector distancia y que no esté visto;
            int vertice = 0;
            while( visto[vertice] ){
                vertice++;
            }
            for (int m = 0; m < cntVrts; m++) {
                if ( ( !visto[m] ) && ( distancia[m] < distancia[vertice] ) ) {
                    vertice = m;
                }
            }
            visto[vertice] = true;
            
            int* sucesores = arregloVrts[vertice].lstAdy.adyacencias();
            for( int j = 0; j < obtCntAdy(vertice); j++ ){                      //para cada w ∈ sucesores (G, vértice) hacer
                if( distancia[sucesores[j]] > ( distancia[vertice] + 1 ) ){     //si distancia[w]>distancia[vértice]+ peso (vértice, w) entonces
                    distancia[sucesores[j]] = distancia[vertice] + 1;           //distancia[w] = distancia[vértice]+peso (vértice, w)
                    antecesores[sucesores[j]] = vertice;
                }
            }
        }
        
        size = distancia[ idVrtD ] + 1;
        camino = new int[ size ];
        size = size - 1;
        int k = idVrtD;
        int index = distancia[idVrtD];                                          
        while( antecesores[k] != -1){
            camino[index] = k;
            index--;
            k = antecesores[k];
        }
        camino[0] = idVrtO;
        size = distancia[ idVrtD ];
    }
    return size;
}

int Laberinto::caminoEncontrado(int idVrtO, int idVrtD, int*& camino) const {
    
}

double Laberinto::sumaTotalFerormona() const {
    double suma = 0.0;
    for (int i = 0; i < (cntVrts * (cntVrts + 1) / 2); i++) {
        suma += arregloAdys[i].obtCntFerormona();
    }
    return suma;
}

void Laberinto::asgIdVrtInicial(int idVrtInicialN) {
    idVrtInicial = idVrtInicialN;
}

void Laberinto::asgIdVrtFinal(int idVrtFinalN) {
    idVrtFinal = idVrtFinalN;
}

void Laberinto::asgDatoAdy(int idVrtO, int idVrtD, const Adyacencia& ady) {
    int k = obtIndiceAdy(idVrtO, idVrtD);
    arregloAdys[k] = Adyacencia(ady);
}

void Laberinto::decrementarFerormonaAdys(double decrFerormona) {
    for (int i = 0; i < (cntVrts * (cntVrts + 1) / 2); i++) {
        if (arregloAdys[i].obtCntFerormona() != (-1.0)) {
            arregloAdys[i].asgCntFerormona((arregloAdys[i].obtCntFerormona()) * (decrFerormona));
        }
    }
}

void Laberinto::actualizarValoracionAdys() {
    for (int i = 0; i < (cntVrts * (cntVrts + 1) / 2); i++) {
        if (arregloAdys[i].obtValoracion() != (-1.0)) {
            arregloAdys[i].asgValoracion((arregloAdys[i].obtCntFerormona()) / (sumaTotalFerormona()));
        }
    }
}

int Laberinto::obtIndiceAdy(int f, int c) const {
    if (f > c) {
        int t = f;
        f = t;
        c = f;
    }
    return f * cntVrts + c - f * (f + 1) / 2;
}