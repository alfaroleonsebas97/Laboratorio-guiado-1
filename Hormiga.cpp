/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hormiga.cpp
 * Author: Alan
 * 
 * Created on 7 de febrero de 2018, 05:53 PM
 */

#include "Hormiga.h"

int Hormiga:: cntVrts = 0; // inicialización de variable static pública

//construye un hormiga en el nido y con destino == nodoFinal.
Hormiga::Hormiga() {
        /* ATRIBUTOS PRIVADOS OBLIGATORIOS */
    //idVrtActual = ; // idVrt del vértice donde se encuentra la hormiga actualmente
    //memoria = ; // vector de idVrt que representa el recorrido de la hormiga, memoria asignada dinámicamente
    haSalido = false; // false mientras no haya salido, true si ya salió
    haRegresado = false; // false mientras no haya regresado de idVrtFinal a idVrtInicial
    destino = 'F'; // 'F' o 'I', indica hacia adónde se dirige la hormiga
    enRetroceso = 0; // si es mayor a cero, la hormiga está retrocediendo esta cantidad de pasos porque topó con un camino sin salida o un ciclo-
    longitudSolucion =  0; // registra la longitud de la solución encontrada para moderar su aporte de ferormona en su retorno
    //deltaFerormona = ; // representa cuánta ferormona aporta la hormiga a cada link y se modula con base en length_solución x encuentros
}

Hormiga::Hormiga(const Hormiga& orig) {
}

Hormiga::~Hormiga() {
}

/* OBSERVADORES */

bool Hormiga::salio() {
}

bool Hormiga::regreso() {
}

char Hormiga::obtDestino() {
}

string Hormiga::obtMemoria() {
}

/* MÉTODOS MODIFICADORES */

void Hormiga::salir(int idVrtInicial) {
}

void Hormiga::mover(const Laberinto& lbrt) {
}

/* MÉTODOS PRIVADOS SUGERIDOS */

void Hormiga::filtraVrtsPosibles(int* vrtsPosibles) {
}

int Hormiga::retroceder() {
}

int Hormiga::seleccionaAdyMasCargada(const Laberinto& lbrt) {
}

bool Hormiga::estaEnMemoria(int idVrt) {
}

void Hormiga::pushMemo() {
}

void Hormiga::popMemo() {
}

void Hormiga::topMemo() {
}