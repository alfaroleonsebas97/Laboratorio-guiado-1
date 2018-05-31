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
    cntVrts = cantidadVrts;                                                 //inicializa las variables.
    idVrtInicial = -1;
    idVrtFinal = -1;
    arregloVrts = new Vertice[cntVrts];                                     //arreglo de vértices.
    arregloAdys = new Adyacencia[cntVrts * (cntVrts + 1) / 2];              //arreglo de adyacencias.

    for (int k = 0; k < (cntVrts * (cntVrts + 1) / 2); k++) {               //llena el arreglo de adyacencias con -1.
        arregloAdys[k].asgValoracion(-1.0);
        arregloAdys[k].asgCntFerormona(-1.0);
    }

    double numeroAleatorio = 0.0;
    srand(time(NULL));
    for (int i = 0; i < cntVrts; i++) {                                     //agrega deacuerdo a su probabilidad.
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
    idVrtInicial = -1;                                                      //inicializa variables.
    idVrtFinal = -1;
    string hileraActual;
    getline(archivo, hileraActual);
    cntVrts = stoi(hileraActual);
    arregloAdys = new Adyacencia[cntVrts * (cntVrts + 1) / 2];

    for (int k = 0; k < (cntVrts * (cntVrts + 1) / 2); k++) {
        arregloAdys[k].asgValoracion(-1.0);
        arregloAdys[k].asgCntFerormona(-1.0);
    }

    arregloVrts = new Vertice[cntVrts];                                     //arreglo de Vrts.
    int numeroDeAdyacencia;
    string hileraTemporal;
    int numeroDeLinea = 0;
    while (getline(archivo, hileraActual)) {                                //recorre el archivo hasta el final
        int i = 0;
        while (hileraActual[i] != '\r') {                                   //recorre la hilera hasta el final de la línea.
            if (hileraActual[i] != ' ') {                                   //guarda en hilera temporal el número, hasta llegar a un blanco
                hileraTemporal += hileraActual[i];
            } else {                                                        //cuando encuentra un blanco, agrega al arreglo de vértices lo que había en hilera temporal.
                numeroDeAdyacencia = stoi(hileraTemporal);
                hileraTemporal = "";
                arregloVrts[numeroDeLinea].lstAdy.agregar(numeroDeAdyacencia);
            }
            i++;
        }
        numeroDeLinea++;
    }
}

Laberinto::Laberinto(const Laberinto& orig) {                               //crea una copia del laberinto original.
    cntVrts = orig.cntVrts;
    idVrtInicial = -1;
    idVrtFinal = -1;
    arregloAdys = new Adyacencia[cntVrts * (cntVrts + 1) / 2];

    for (int k = 0; k < (cntVrts * (cntVrts + 1) / 2); k++) {
        arregloAdys[k].asgValoracion(-1.0);
        arregloAdys[k].asgCntFerormona(-1.0);
    }

    arregloVrts = new Vertice[cntVrts];
    for (int i = 0; i < cntVrts; i++) {                                     //recorre el laberinto copiándolo.
        arregloVrts[i].lstAdy = orig.arregloVrts[i].lstAdy;
    }
}

Laberinto::~Laberinto() {
    delete[] arregloVrts;
    delete[] arregloAdys;

}

/* MÉTODOS OBSERVADORES BÁSICOS */
bool Laberinto::xstVrt(int idVrt) const {
    return ( (0 <= idVrt) && (idVrt < cntVrts));                            //retorna true si el vertice existe o está entre 0 y n;
}

bool Laberinto::xstAdy(int idVrtO, int idVrtD) const {
    bool adyacencia = false;
    if ((xstVrt(idVrtO)) && (xstVrt(idVrtD))) {                             //si ambos vértices existen,
        adyacencia = arregloVrts[idVrtO].lstAdy.buscar(idVrtD);             //busca si hay adyacencia entre el vértice origen y el destino.
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
    if (xstVrt(idVrt)) {                                                    //si existe el vértice, obtiene sus adyacencias.
        rsp = arregloVrts[idVrt].lstAdy.adyacencias();
    }
}

Adyacencia Laberinto::obtDatoAdy(int idVrtO, int idVrtD) const {
    Adyacencia result;
    if ((xstVrt(idVrtO)) && (xstVrt(idVrtD))){                              //si existen ambos vértices,
        if (xstAdy(idVrtO, idVrtD)) {                                       //y si existe adyacencia entre ambos, obtiene el dato de adyacencia.
            int k = obtIndiceAdy(idVrtO, idVrtD);
            result = arregloAdys[k];
        }
    }
    return result;
}

int Laberinto::obtCntAdy(int idVrt) const {
    int cantidadDeAdyacencias = -1;
    if (xstVrt(idVrt)) {                                                     //si existe el vértice, obtiene la cantidad de adyacencias.
        cantidadDeAdyacencias = arregloVrts[idVrt].lstAdy.cantidadAdy();
    }
    return cantidadDeAdyacencias;
}

int Laberinto::obtTotAdy() const {
    int cntTtlAdy = -1;
    for (int i = 0; i < cntVrts; i++) {                                     //obtiene la cantidad total de adyacencias, sumandolas vértice por vértice.
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
    if (xstVrt(idVrtO) && xstVrt(idVrtD)) {                                 //si existen ambos vértices.
        int distancia[cntVrts];                                             //vector de distancias.
        bool visto[cntVrts];                                                //para controlar los vértices visitados.
        for (auto& currentElement: visto) {                                 //inicializa visto en false
           currentElement = false;
        }
        int antecesores[cntVrts];
        for (int i = 0; i < cntVrts; i++) {                                 //recorre todos los vérties
            if (!xstAdy(idVrtO, i)) {                                       //si no existe adyacencia con el vértice origen,
                distancia[i] = INT_MAX;                                     //asigna infinito.
                antecesores[i] = -2;                                        //y un antecesor inválido.
            } else {                                                        //en el caso de que si exista adyacencia
                distancia[i] = 1;                                           //asigna peso 1
                antecesores[i] = idVrtO;                                    //y asigna antecesor el vértice origen.
            }
        }
        distancia[idVrtO] = 0;                                              //invalida el vértice origen y lo pone visitado
        antecesores[idVrtO] = -1;
        visto[idVrtO] = true;

        while (visto[idVrtD] == false) {                                    //mientras no estén todos en visto.
            
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
            visto[vertice] = true;                                          //ese vértice mínimo lo pone en visitado.
            
            int* sucesores = arregloVrts[vertice].lstAdy.adyacencias();
            for( int j = 0; j < obtCntAdy(vertice); j++ ){                  //para cada sucesor
                if( distancia[sucesores[j]] > ( distancia[vertice] + 1 ) ){ //si el nuevo peso es menor.
                    distancia[sucesores[j]] = distancia[vertice] + 1;       //cambiar el peso y el antecesor.
                    antecesores[sucesores[j]] = vertice;
                }
            }
        }
        
        //recorre el camino más corto, desde el vértice destino hasta el vértice origen agregándolo en camino
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
        size = distancia[ idVrtD ];                                         //distancia del camino más corto.
    }
    return size;
}


int Laberinto::caminoEncontrado(int idVrtO, int idVrtD, int*& camino) const {
    int size = -1;
    if (xstVrt(idVrtO) && xstVrt(idVrtD)) {
        //No tiene el include de hormiga, entonces cómo devuelve el camino entcontrado por las hormigas?   
    }
    return size;
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