/* 
 * File:   Digrafo.cpp
 * Author: Alan
 * 
 * Created on 1 de setiembre de 2017, 12:25 PM
 */

#include "ListaOrdenada.h"

ListaOrdenada::ListaOrdenada(): inicio(nullptr) {
}

ListaOrdenada::ListaOrdenada(const ListaOrdenada& orig){
    shared_ptr<Nodo> p = orig.inicio;
    if (p == nullptr){
        inicio = nullptr;
    }else{
        inicio = shared_ptr<Nodo>(new Nodo(orig.inicio->pos));
        p = p->sgt;
        shared_ptr<Nodo> ultimo = inicio;
        while(p != nullptr){
            ultimo->sgt = shared_ptr<Nodo>(new Nodo(p->pos));
            p = p->sgt;
            ultimo = ultimo->sgt;
        }
    }
}

ListaOrdenada::~ListaOrdenada() {
}

void ListaOrdenada::agregar(int nPos) {
    bool rsl = false;
    shared_ptr<Nodo> p = inicio;
    shared_ptr<Nodo> ant = nullptr;
    if(inicio == nullptr){
        inicio = shared_ptr<Nodo>(new Nodo(nPos));
        rsl = true;
    } else{
        if (inicio->pos > nPos){ 
        p = shared_ptr<Nodo>(new Nodo(nPos)); 
        p->sgt = inicio; 
        inicio = p; 
        rsl = true;
        } else{
            p = inicio;
            while(p != nullptr){
                if(p->pos == nPos){ 
                    p = nullptr;
                } else{ 
                    if(p->pos < nPos){
                        ant = p;
                        p = p->sgt;
                        if (p == nullptr){
                            rsl = true;
                        }
                    } else { 
                        p = nullptr;
                        rsl = true; 
                    }
                }
            }
            if (rsl){
                p = ant->sgt;
                ant->sgt = shared_ptr<Nodo>(new Nodo(nPos));
                ant->sgt->sgt  = p;
            }
        }
    }
}

bool ListaOrdenada::buscar(int nPos) {
    bool rsl = false;
    shared_ptr<Nodo> p = inicio;
    while(p != nullptr){
        if(p->pos == nPos){
            rsl = true;
            p = nullptr;
        }else{
            if(p->pos < nPos){
                p = p->sgt;
            }
            else{
                p = nullptr;
            }
        }
    }
    return rsl;
}

string ListaOrdenada::toString() {
 stringstream fs;
    fs << '{';
    shared_ptr<Nodo> p = inicio;
    while (p != nullptr){
        fs << p->pos;
        if(p->sgt != nullptr){
            fs << ',';
            p = p->sgt; 
        }  
    }
        fs << '}';
        return fs.str();
}

int* ListaOrdenada::adyacencias() {
    int* arreglo = new int[0];
    shared_ptr<Nodo> p = inicio;
    
    return arreglo;
}

int ListaOrdenada::cantidadAdy() {
    
}