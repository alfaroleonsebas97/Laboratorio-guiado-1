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

int Hormiga::cntVrts = 0; // inicialización de variable static pública.

//construye un hormiga en el nido y con destino == nodoFinal.

Hormiga::Hormiga() {
    idVrtActual = -1; 
    memoria = new int[cntVrts]; 
    for (int i = 0; i < cntVrts; i++) {                                     //asigna -1 en toda la memoria.
        memoria[i] = -1;
    }
    haSalido = false; 
    haRegresado = false;
    destino = 'F'; 
    enRetroceso = 0;
    longitudSolucion = 0;
    deltaFerormona = 0.0;
    ultMemo = -1;
}

Hormiga::Hormiga(const Hormiga& orig) {                                     //crea una copia de la hormiga.
    idVrtActual = orig.idVrtActual;
    memoria = orig.memoria;
    haSalido = orig.haSalido;
    haRegresado = orig.haRegresado;
    destino = orig.destino;
    enRetroceso = orig.enRetroceso;
    longitudSolucion = orig.longitudSolucion;
    deltaFerormona = orig.deltaFerormona;
    ultMemo = orig.ultMemo;
}

Hormiga::~Hormiga() {
    //delete[] memoria;                                                       //borra la memoria.
}

/* OBSERVADORES */

bool Hormiga::salio() {
    return haSalido;
}

// EFE: retorna true si la hormiga ya regresó al vértice inicial después de encontrar el vértice final.

bool Hormiga::regreso() {
    return haRegresado;
}

char Hormiga::obtDestino() {
    return destino;                                                         //retorna el destino.
}

string Hormiga::obtMemoria() {
    string memoriaHilera = "{";
    if (-1 != memoria[0]) {                                                 //si hay vértices en memoria,
        memoriaHilera += memoria[0];                                        //copia el primer vértice en la string.
        for (int i = 1; i < ultMemo; i++) {                                 //recorre el resto de la memoria.
            memoriaHilera += "," + memoria[i];                              //copia una coma y el vértice.
        }
    }
    memoriaHilera += "}";
    return memoriaHilera;                                                   //retorna la hilera de memoria.
}

/* MÉTODOS MODIFICADORES */

void Hormiga::salir(int idVrtInicial) {
    idVrtActual = idVrtInicial;                                            //ubica la hormiga en el nodo inicial.
    pushMemo();
    haSalido = true;
}

// REQ: que la hormiga (*this) esté activa.
// EFE: la hormiga avanza a un vértice adyacente.

void Hormiga::mover(const Laberinto& lbrt) {
    
    for (int i = 0; i < cntVrts; i++) {                                     //asigna -1 en toda la memoria.
        memoria[i] = -1;
    }
    if ( ( haSalido ) && ( !haRegresado) ){                                 //si ya ya salió y no ha regresado.
        if ( idVrtActual == lbrt.obtIdVrtFinal() ){                         //si ya llegó al vértice final, cambia el destino                                                           //pregtuntar que si ya llegó al final, para empezar a devoverse.
            destino = 'I';
            longitudSolucion = ultMemo + 1;                                     //y asigna la longitud de la solución.
            deltaFerormona = 1.0 / longitudSolucion ;
        }
        if( destino == 'I'){                                                //se mueve un vértice de regreso.
            double  f = lbrt.obtDatoAdy(memoria[ultMemo -1],idVrtActual).obtCntFerormona();
            lbrt.obtDatoAdy(memoria[ultMemo -1],idVrtActual).asgCntFerormona(f+deltaFerormona);
            popMemo();
            if( lbrt.obtIdVrtInicial() == idVrtActual ){
                haRegresado = true;
             }
        }else{   
            int sgtVrt = seleccionaAdyMasCargada(lbrt);                     //elige el siguiente vértice.
            if( sgtVrt == -1 ){                                             //si el siguiente vértice es inválido,
                retroceder();
            }else{                                                          //sino es un vértice válido.                                                        //se mueve un vértice.
                if( idVrtActual == lbrt.obtIdVrtFinal()){
                    longitudSolucion = ultMemo;
                }    
                idVrtActual = sgtVrt;
                pushMemo();
            }
        }
    }
}

/* MÉTODOS PRIVADOS SUGERIDOS */

//REQ: que los idVrt en vrtsPosibles sean índices válidos de vértices en el laberinto que está recorriendo la hormiga.
// EFE: elimina de vrtsPosibles los idVrt que ya aparecen en la memoria. osea que no haya ciclo ni camino sin salida

int Hormiga::filtraVrtsPosibles( int* vrtsPosibles, int vrtDestino, int longitudOriginal ) {
    int longitudDeAdy = longitudOriginal;                                   //longitud de los vértices posibles.
    int contador = 0;                                                       //contador de vértices inválidos.
    for( int i = 0; i < longitudOriginal;i++ ){                             //recorre los vértices posibles.
        for( int j = 0; j <= ultMemo; j++ ){                                //recorre la memoria de la hormiga.
            if ( ( vrtsPosibles[i] == memoria[j] ) && ( vrtsPosibles[i] != vrtDestino ) ){                           //si el vértice está en momoria, le asigna -1, y aumenta el contador.
                vrtsPosibles[i] = -1;
                contador ++;
            }
        }
    }
    if( contador != 0 ){                                                    //si el contador no es 0.
        longitudDeAdy = longitudOriginal - contador;                        //asgina el nuevo tamaño de los vértices posibles.
        int temporal[longitudDeAdy];                                        //arreglo temporal.
        int n = 0;                                                          //índice para temporal.
        for ( int m = 0; m < longitudOriginal; m++ ){                       //recorre los vertices posibles.
            if( vrtsPosibles[m] != -1 ){                                    //si no es un vértice inválido,
                temporal[n] = vrtsPosibles[m];                              //lo copia en en arreglo temporal,
                n++;                                                        //y aumenta el índice de temporal.
            }
        }
        vrtsPosibles = &temporal[0];                                        //actualiza los vértices posibles.
    }
    return longitudDeAdy;                                                   //retorna la longitud de los vértices posibles.
}

void Hormiga::retroceder() {
    //srand (time(NULL));
    enRetroceso  = 1;//rand ()% ultMemo + 1;                               //genera un random,
    for ( int i = 0; i <= enRetroceso; i++ ){                              //y retrocede esa cantidad de veces.
        popMemo();
    }
    enRetroceso = 0;
}

int Hormiga::seleccionaAdyMasCargada(const Laberinto& lbrt) {
    int sgtVrt = -1;                                                        //vértice a escoger.
    int *ady;                                                               //crea ady.
    lbrt.obtIdVrtAdys( idVrtActual, ady );                                  //al objeto ady se le asignan las adyacencias del vértice actual.
    int longitudDeAdy = filtraVrtsPosibles( ady, lbrt.obtIdVrtFinal(), lbrt.obtCntAdy( idVrtActual ) ); //filtra los vértices posibles de ady, y obtiene el nuevo tamaño de ady.
    if( longitudDeAdy != 0){
        int cntFerormona[ longitudDeAdy ];                                  //crea un arreglo de ferormonas.
        int sumaFerormona = 0;                                              //suma de todas las ferormonas.
        int cantidadDeCeros = 0;                                            //cantidad de adyacencias con ferormona igual a cero

        for (int i = 0; i < longitudDeAdy; i++) {                           //recorro el arreglo de ferormonas
            cntFerormona[i] = lbrt.obtDatoAdy(idVrtActual, ady[i]).obtCntFerormona(); //asignando la cantidad de ferormona por adyacencia
            sumaFerormona = sumaFerormona + cntFerormona[i];                //suma la ferormona
            if (cntFerormona[i] == 0) {                                     //si la ferormona de la adyacencia es cero
                cantidadDeCeros++;                                          //aumenta cantidadDeCeros
            }
        }

        double porcentajes[longitudDeAdy];                                  //arreglo de porcentajes
        double porcentajeSumado = 0.0;                                      //porcentaje que va de 0 a 1.
        for (int k = 0; k < longitudDeAdy; k++) {                           //recorre el arreglo de porcentajes
            if (cntFerormona[k] == 0) {                                     //si la ferormona de la adyacencia es 0, su porcentaje es 0.01 + porcentajeTotal;
                porcentajes[k] = porcentajeSumado + 0.01;                   //y suma porcentaje.
                porcentajeSumado = porcentajeSumado + 0.01;
            } else {                                                        //sino, asigna el porcentaje correspondiente y suma porcentaje.
                porcentajes[k] = porcentajeSumado + ((cntFerormona[k] / sumaFerormona) * (1 - (cantidadDeCeros * (0.01))));
                porcentajeSumado = ((cntFerormona[k] / sumaFerormona) * (1 - (cantidadDeCeros * (0.01))));
            }
        }
        
        srand (time(NULL));
        double numeroAleatorio = (rand() % 1000 + 1) / 1000.0;              //gerenera un número al azar entre 0 y 1.
        int m = 0;                                                          //índice para recorrer el arreglo de porcentajes.
        if (numeroAleatorio < porcentajes[m]) {                             //si el número aleatorio está en el rango del primer vértice,
            sgtVrt = ady[m];                                                //entonces ese el siguiente vértice a escoger.
        } else {                                                            //sino sigue buscando hasta encontrarlo.
            while ( numeroAleatorio >= porcentajes[m] ) {
                m++;
                if ( numeroAleatorio < porcentajes[m] ) {                   //si encuentra el rango.
                    sgtVrt = ady[m];                                        //asigna el siguiente vértice.
                }
            }
        }
    }
    return sgtVrt;                                                          //retorna el siguiente vértice.
}


bool Hormiga::estaEnMemoria(int idVrt) {
    bool estoy = false;
    for (int i = 0; i <= ultMemo && !estoy; i++) {                          //recorre la memoria de la hormiga, buscando el vértice.
        if (memoria[i] == idVrt) {                                          //si lo encuentra devuelve true.
            estoy = true;
        }
    }
    return estoy;
}

void Hormiga::pushMemo() {
    ultMemo++;                                                              //aumenta ultMemo.
    memoria[ultMemo] = idVrtActual;                                         //agrega el vértice actual a la memoria.
}

void Hormiga::popMemo() {
    memoria[ultMemo] = -1;                                                  //elimina la última posición en memoria.
    ultMemo = ultMemo - 1;                                                  //actualiza ultMemo.
    idVrtActual = memoria[ultMemo];                                         //actualiza el vértice actual.
}

void Hormiga::topMemo() {
}