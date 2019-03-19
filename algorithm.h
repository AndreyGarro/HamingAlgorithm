#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "listasimple.h"



class Algorithm
{

private:
    ListaSimple ListaSinError;
    ListaSimple ListaConError;
    ListaSimple ListaCompleta;
    ListaSimple listaP1;
    ListaSimple listaP2;
    ListaSimple listaP3;
    ListaSimple listaP4;
    int paridad;

    void crearListasParidad();


public:
    Algorithm();
    void init(ListaSimple listaA, ListaSimple listaB, int paridad);
    void insertarError();
    void buscarError();
    ListaSimple getListaP1();
    ListaSimple getListaP2();
    ListaSimple getListaP3();
    ListaSimple getListaP4();
};

#endif // ALGORITHM_H
