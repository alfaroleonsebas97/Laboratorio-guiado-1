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

Laberinto::Laberinto(int cantidadVrts, double probabilidadAdy){
    cntVrts = cantidadVrts;
    idVrtInicial = -1;
    idVrtFinal = -1;
    arregloVrts = new Vertice[cntVrts];
    arregloAdys = new Adyacencia[cntVrts * (cntVrts + 1) / 2];
    double numeroAleatorio = 0.0;
    srand (time(NULL));
    for( int i = 0; i < cntVrts; i++ ){
        for(int j=i+1; j < cntVrts; j++){
            numeroAleatorio = (rand() % 1000 + 1) / 1000.0;
            if(numeroAleatorio <= probabilidadAdy){
                arregloVrts[i].lstAdy.agregar(j);
                arregloVrts[j].lstAdy.agregar(i);
            } 
        } 
    }
}

Laberinto::Laberinto(ifstream& archivo){
    
    if ( archivo.is_open() ){
        idVrtInicial = -1;
        idVrtFinal = -1;
        string hileraActual ;
        getline (archivo,hileraActual);
        cntVrts = stoi(hileraActual);
        arregloAdys = new Adyacencia[cntVrts * (cntVrts + 1) / 2];
        arregloVrts = new Vertice[cntVrts];
        int numeroDeAdyacencia;
        string hileraTemporal;
        while ( getline (archivo,hileraActual) ){
            int i = 0;
            while( hileraActual[i] != '\r'){
                if(hileraActual[i] != ' '){ //separados por comas?
                    hileraTemporal += hileraActual[i];
                }else{
                    numeroDeAdyacencia = stoi(hileraTemporal);
                    hileraTemporal = "";
                    arregloVrts[i].lstAdy.agregar(numeroDeAdyacencia);
                }
                i++;
            }
        }
        archivo.close();
    } else {
        idVrtInicial = -1;
        idVrtFinal = -1;
        cntVrts = -1;
        arregloAdys = NULL;
        arregloVrts = NULL;
    }
}

Laberinto::Laberinto(const Laberinto& orig){
    arregloVrts  = new Vertice[50]; //FALTA AVERIGUAR EL TAMAÑO DEL LABERINTO ORIG.
    for( int i = 0; i < 50; i++ ){
            arregloVrts[i].lstAdy = ListaOrdenada ( orig.arregloVrts[i].lstAdy );
        i++;
    }
}

Laberinto::~Laberinto() {
    delete arregloVrts;
    delete arregloAdys;
}

/* MÉTODOS OBSERVADORES BÁSICOS */
bool Laberinto::xstVrt(int idVrt) const {
    return ( ( 0 <= idVrt ) && ( idVrt < cntVrts ) );
}

bool Laberinto::xstAdy(int idVrtO, int idVrtD) const {
    bool adyacencia = false;
    if( ( xstVrt(idVrtO)) && ( xstVrt(idVrtD) ) ){
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
    if (xstVrt(idVrt)){
        rsp = arregloVrts[idVrt].lstAdy.adyacencias();
    }
}

Adyacencia Laberinto::obtDatoAdy(int idVrtO, int idVrtD) const {
    if ( ( xstVrt(idVrtO) ) && ( xstVrt(idVrtD) ) );{
        // EFE: retorna los datos de la adyacencia entre <idVrtO, idVrtD>.
        // NOTA: retorna por valor para que NO pueda ser modificado.
    }
}

int Laberinto::obtCntAdy(int idVrt) const {
    
}

int Laberinto::obtTotAdy() const {
}

int Laberinto::obtTotVrt() const {
    return cntVrts;
}

int Laberinto::caminoMasCorto(int idVrtO, int idVrtD, int*& camino) const {
}

int Laberinto::caminoEncontrado(int idVrtO, int idVrtD, int*& camino) const {
}

double Laberinto::sumaTotalFerormona() const {
}

void Laberinto::asgIdVrtInicial(int idVrtInicialN) {
    idVrtInicial = idVrtInicialN;
}

void Laberinto::asgIdVrtFinal(int idVrtFinalN) {
    idVrtFinal = idVrtFinalN;
}

void Laberinto::asgDatoAdy(int idVrtO, int idVrtD, const Adyacencia& ady) {
}

void Laberinto::decrementarFerormonaAdys(double decrFerormona) {
}

void Laberinto::actualizarValoracionAdys() {
}

int Laberinto::obtIndiceAdy(int f, int c) const {
    if ( f > c){
        int t = f;
        f = c;
        c = f;
    }
    return f * cntVrts + c - f * (f + 1) / 2;
}