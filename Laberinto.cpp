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

Laberinto::Laberinto(int cantidadVrts, double probabilidadAdy){
    arregloVrts = new Vertice[cantidadVrts];
    for( int i = 0; i < cantidadVrts; i++ ){
        arregloVrts[i] = Vertice;
    }
    //cout << arregloVrts[0,1,2,...,cantidadVrts-1]; TO_DO: En el arreglo hay basura, debe llenarlo ocn gente apliacando lo de probabilidad.
    //arregloAdys = new int[cantidadVrts * (cantidadVrts + 1) / 2];//TO_DO: repensarlo o preguntarlo.
}

Laberinto::Laberinto(ifstream& archivo){
}

Laberinto::Laberinto(const Laberinto& orig){
}

Laberinto::~Laberinto() {
}

/* MÉTODOS OBSERVADORES BÁSICOS */
bool Laberinto::xstVrt(int idVrt) const {
    return true;
}

bool Laberinto::xstAdy(int idVrtO, int idVrtD) const {
    return true;
}

int Laberinto::obtIdVrtInicial() const {
}

int Laberinto::obtIdVrtFinal() const {
}

void Laberinto::obtIdVrtAdys(int idVrt, int*& rsp) const {
}

Adyacencia Laberinto::obtDatoAdy(int idVrtO, int idVrtD) const {
}

int Laberinto::obtCntAdy(int idVrt) const {
}

int Laberinto::obtTotAdy() const {
}

int Laberinto::obtTotVrt() const {
}

int Laberinto::caminoMasCorto(int idVrtO, int idVrtD, int*& camino) const {
}

int Laberinto::caminoEncontrado(int idVrtO, int idVrtD, int*& camino) const {
}

double Laberinto::sumaTotalFerormona() const {
}

void Laberinto::asgIdVrtInicial(int idVrtInicialN) {
}

void Laberinto::asgIdVrtFinal(int idVrtFinalN) {
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