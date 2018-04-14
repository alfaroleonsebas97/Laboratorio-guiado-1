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

Hormiga::Hormiga() {
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