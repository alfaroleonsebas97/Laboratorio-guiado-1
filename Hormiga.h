/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hormiga.h
 * Author: Alan
 *
 * Created on 7 de febrero de 2018, 05:53 PM
 */

#ifndef HORMIGA_H
#define HORMIGA_H

#include <stdlib.h>     /* para srand, rand al moverse*/
#include <string>
using namespace std;

#include "Laberinto.h"

class Hormiga {
public:
    
    // EFE: construye un hormiga en el nido y con destino == nodoFinal.
    Hormiga();
    
    // EFE: construye una copia idéntica e independiente de orig.
    Hormiga(const Hormiga& orig);
    
    virtual ~Hormiga();

    /* MÉTODOS OBSERVADORES */
    
    // EFE: retorna true si la hormiga ya salió del vértice inicial.
    bool salio();
    
    // EFE: retorna true si la hormiga ya regresó al vértice inicial después de encontrar el vértice final.
    bool regreso();
    
    // EFE: retorna 'F' o 'I' para indicar el destino de la hormiga.
    char obtDestino();
    
    // EFE: retorna una hilera con la memoria de la hormiga.
    // EJEMPLO: "[2,6,7,12,54]" indicaría que la hormiga salió por 2 y viajó en
    // el orden de la secuencia hasta 54.
    string obtMemoria();

    /* MÉTODOS MODIFICADORES */

    // EFE: activa la hormiga y la ubica en nodoInicial.
    void salir(int idVrtInicial);

    // REQ: que la hormiga (*this) esté activa.
    // EFE: la hormiga avanza a un vértice adyacente.
    void mover(const Laberinto& lbrt);

private:

    /* MÉTODOS PRIVADOS SUGERIDOS */
    
    // REQ: memoria.size() > 0.
    // RET: la posición anterior en la memoria de la hormiga cuando retrocede.
    int retroceder();
    
    // EFE: retorna -1 en caso de que la hormiga llegue a camino sin salida,
    // y un idVrt válido en caso de que la hormiga pueda continuar.
    int seleccionaAdyMasCargada(const Laberinto& lbrt);

    /* MÉTODOS AUXILIARES */
    // REQ: que los idVrt en vrtsPosibles sean índices válidos de vértices en el laberinto que está recorriendo la hormiga.
    // EFE: elimina de vrtsPosibles los idVrt que ya aparecen en la memoria.
    void filtraVrtsPosibles(int* vrtsPosibles);

    /* OPERACIONES SOBRE LA MEMORIA DE LA HORMIGA */
    
    // RET: true si idVrt está en memoria y false en caso contrario.
    bool estaEnMemoria(int idVrt);
    void pushMemo();
    void popMemo();
    void topMemo();
    
    /* ATRIBUTOS PRIVADOS OBLIGATORIOS */
    int idVrtActual; // idVrt del vértice donde se encuentra la hormiga actualmente
    int* memoria; // vector de idVrt que representa el recorrido de la hormiga, memoria asignada dinámicamente
    bool haSalido; // false mientras no haya salido, true si ya salió
    bool haRegresado; // false mientras no haya regresado de idVrtFinal a idVrtInicial
    char destino; // 'F' o 'I', indica hacia adónde se dirige la hormiga
    int enRetroceso; // si es mayor a cero, la hormiga está retrocediendo esta cantidad de pasos porque topó con un camino sin salida o un ciclo-
    int longitudSolucion; // registra la longitud de la solución encontrada para moderar su aporte de ferormona en su retorno
    double deltaFerormona; // representa cuánta ferormona aporta la hormiga a cada link y se modula con base en length_solución x encuentros

};
#endif /* HORMIGA_H */

