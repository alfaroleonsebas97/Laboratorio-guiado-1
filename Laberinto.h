/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Laberinto.h
 * Author: Alan
 *
 * Created on 7 de febrero de 2018, 04:46 PM
 */

#ifndef LABERINTO_H
#define LABERINTO_H

#include <fstream>
#include <memory>
using namespace std;

#include "Adyacencia.h"
#include "ListaOrdenada.h"

class Laberinto {
public:

    /* CONSTRUCTORES */

    // REQ: cantidadVtrs > 0. En este caso, N es igual a cantidadVrts.
    // REQ: 0 < probabilidadAdy < 1.
    // Construye un laberinto con cantidadVrts de vértices en el que el conjunto de
    // adyacencias se determina aleatoriamente utilizando probabilidadAdy. Esto
    // implica que la probabilidad de que un arco exista entre cualesquiera dos
    // vértices es igual a probabilidadAdy
    Laberinto(int cantidadVrts, double probabilidadAdy);

    // Construye un laberinto con base en los datos en el archivo.
    // El archivo debe ser de texto (extensión txt) con datos separados por comas.
    // En la primera línea aparecerá un entero que representa la cantidad N de vértices.
    // Los vértices tienen un índice que va de 0 a N-1.
    // Luego en cada línea aparecerán los índices de los vértices asociados o
    // adyacentes, a cada nodo: 0, 1...N-1.
    // NOTA: todos los vértices son inicializados en cero.
    Laberinto(ifstream& archivo);

    // Construye una copia idéntica a orig.   
    Laberinto(const Laberinto& orig);

    // destructor
    ~Laberinto();

    /* MÉTODOS OBSERVADORES BÁSICOS */

    // EFE: retorna true si 0 <= idVrt < N.
    // NOTA: idNdo significa "identificador de vértice".
    bool xstVrt(int idVrt) const;

    // REQ: 0 <= idVrtO < N && 0 <= idVrtD < N.
    // EFE: retorna true si existe adyacencia entre los vértices idVrtO e idVrtD.
    bool xstAdy(int idNdO, int idVrtD) const;

    // EFE: retorna el id del vértice inicial.
    int obtIdVrtInicial() const;
    
    // EFE: retorna el id del vértice final.
    int obtIdVrtFinal() const;
    
    // REQ: 0 <= idVrt < N.
    // EFE: retorna en "rsp" los idVrt de todos los vértices adyacentes a idVrt.
    void obtIdVrtAdys(int idVrt, int*& rsp) const;

    // REQ: 0 <= idVrt1 < N && 0 <= idVrt2 < N
    // EFE: retorna los datos de la adyacencia entre <idVrtO, idVrtD>.
    // NOTA: retorna por valor para que NO pueda ser modificado.    
    Adyacencia obtDatoAdy(int idVrtO, int idVrtD) const;

    // EFE: retorna el total de arcos o adyacencias para idVrt en el grafo.
    int obtCntAdy(int idVrt) const;
    
    // EFE: retorna el total de arcos o adyacencias en el grafo.
    int obtTotAdy() const;

    // EFE: retorna el total de vértices en el grafo.
    int obtTotVrt() const;

    /* MÉTODOS OBSERVADORES NO BÁSICOS*/

    // REQ: 0 <= idVrt1 < N && 0 <= idVrt2 < N
    // EFE: retorna en "camino" los índices de los vértices que conforman el
    //      camino más corto entre idVrtO y idVrtD.
    //      retorna la longitud de este camino.
    // NOTA: se usa algoritmo de Dijkstra.
    int caminoMasCorto(int idVrtO, int idVrtD, int*& camino) const;
    
    // REQ: 0 <= idVrt1 < N && 0 <= idVrt2 < N
    // EFE: retorna en "camino" los índices de los vértices que conforman el
    //      camino más corto entre idVrtO y idVrtD encontrado por la colonia de hormigas.
    //      retorna la longitud de este camino.    
    int caminoEncontrado(int idVrtO, int idVrtD, int*& camino) const;
    
    // EFE: retorna la suma total de la ferormona de las adyacencias.
    double sumaTotalFerormona() const;

    /* MÉTODOS MODIFICADORES BÁSICOS */
    
    // REQ: 0 <= idVrtInicialN < N
    // EFE: asigna el identificador del vértice inicial del laberinto.
    void asgIdVrtInicial(int idVrtInicialN);
    
    // REQ: 0 <= idVrtFinalN < N
    // EFE: asigna el identificador del vértice inicial del laberinto.    
    void asgIdVrtFinal(int idVrtFinalN);

    // REQ: 0 <= idVrt1 < N && 0 <= idVrt2 < N
    // EFE: asigna el valor "ady" a la adyacencia <idVrtO, idVrtD>.
    void asgDatoAdy(int idVrtO, int idVrtD, const Adyacencia& ady);
    
    /* OTROS MODIFICADORES */
    
    // EFE: decrementa la cantidad de ferormona de cada una de las adyacencias 
    // por un factor decFerormona.
    void decrementarFerormonaAdys(double decrFerormona);
    
    // EFE: actualiza la valoración de las adyacencias con base en la ferormona de cada una.
    void actualizarValoracionAdys();
    
private:

    // REQ: (0 <= f < cntVrts) && (0 <= c < cntVrts)
    // EFE: retorna el índice de la adyacencia de [f,c]
    int obtIndiceAdy(int f, int c) const; //DUDA: PORQUÉ ESTÁ ESTO ACÁ.
    
    struct Vertice {
        ListaOrdenada lstAdy;
        Vertice(){}; // constructor estándar de un vértice
    };
    
    int cntVrts; // cantidad de vértices
    int idVrtInicial; // id vértice inicial
    int idVrtFinal; // id vértice final
    
    Vertice* arregloVrts; // arreglo de vértices de memoria asignada dinámicamente == cntVrts
    Adyacencia* arregloAdys; // arreglo de adyacencias de memoria asignada dinámicamente == cntVrts * (cntVrts + 1) / 2
};

#endif /* LABERINTO_H */

