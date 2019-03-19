#include "algorithm.h"

#include <iostream>

using namespace std;

Algorithm::Algorithm()
{

}

void Algorithm::init(ListaSimple listaA, ListaSimple listaB, int paridad){
    this->ListaSinError = listaA;
    this->ListaConError = listaB;
    this->paridad = paridad;
    this->crearListasParidad();
}

void Algorithm::insertarError()
{
    ListaConError.addinPos(*listaP1.getData(0), 0);
    ListaConError.addinPos(*listaP2.getData(0), 1);
    ListaConError.addinPos(*listaP3.getData(0), 3);
    ListaConError.addinPos(*listaP4.getData(0), 7);
}

void Algorithm::crearListasParidad()
{
    //Crea la primer lista con el bit de paridad 1
    listaP1.add(*ListaSinError.getData(0));
    listaP1.add(*ListaSinError.getData(1));
    listaP1.add(*ListaSinError.getData(3));
    listaP1.add(*ListaSinError.getData(4));
    listaP1.add(*ListaSinError.getData(6));
    listaP1.add(*ListaSinError.getData(8));
    listaP1.add(*ListaSinError.getData(10));

    int suma = 0;
    for(int i = 0; i < listaP1.getLength(); i++){
        if(*listaP1.getData(i) == 1){
            suma++;
        }
    }

    if (paridad == 1){
        if(suma%2 == 0){
            listaP1.addinPos(1, 0);
        }
        else{
            listaP1.addinPos(0,0);
        }
    }
    else{
        if(suma%2 == 0){
            listaP1.addinPos(0, 0);
        }
        else{
            listaP1.addinPos(1,0);
        }
    }

    //Fin paridad 1

    //Crea la segunda lista con el bit de paridad 2

    listaP2.add(*ListaSinError.getData(0));
    listaP2.add(*ListaSinError.getData(2));
    listaP2.add(*ListaSinError.getData(3));
    listaP2.add(*ListaSinError.getData(5));
    listaP2.add(*ListaSinError.getData(6));
    listaP2.add(*ListaSinError.getData(9));
    listaP2.add(*ListaSinError.getData(10));

    suma = 0;
    for(int i = 0; i < listaP2.getLength(); i++){
        if(*listaP2.getData(i) == 1){
            suma++;
        }
    }

    if (paridad == 1){
        if(suma%2 == 0){
            listaP2.addinPos(1, 0);
        }
        else{
            listaP2.addinPos(0,0);
        }
    }
    else{
        if(suma%2 == 0){
            listaP2.addinPos(0, 0);
        }
        else{
            listaP2.addinPos(1,0);
        }
    }
    //Fin paridad 2


    //Crea la tercera lista con el bit de paridad 3
    listaP3.add(*ListaSinError.getData(1));
    listaP3.add(*ListaSinError.getData(2));
    listaP3.add(*ListaSinError.getData(3));
    listaP3.add(*ListaSinError.getData(8));
    listaP3.add(*ListaSinError.getData(9));
    listaP3.add(*ListaSinError.getData(10));
    listaP3.add(*ListaSinError.getData(11));

    suma = 0;
    for(int i = 0; i < listaP3.getLength(); i++){
        if(*listaP3.getData(i) == 1){
            suma++;
        }
    }

    if (paridad == 1){
        if(suma%2 == 0){
            listaP3.addinPos(1, 0);
        }
        else{
            listaP3.addinPos(0,0);
        }
    }
    else{
        if(suma%2 == 0){
            listaP3.addinPos(0, 0);
        }
        else{
            listaP3.addinPos(1,0);
        }
    }

    //Fin paridad 3

    //Crea la cuarta lista con el bit de paridad 4
    listaP4.add(*ListaSinError.getData(8));
    listaP4.add(*ListaSinError.getData(9));
    listaP4.add(*ListaSinError.getData(10));
    listaP4.add(*ListaSinError.getData(11));

    suma = 0;
    for(int i = 0; i < listaP4.getLength(); i++){
        if(*listaP4.getData(i) == 1){
            suma++;
        }
    }

    if (paridad == 1){
        if(suma%2 == 0){
            listaP4.addinPos(1, 0);
        }
        else{
            listaP4.addinPos(0,0);
        }
    }
    else{
        if(suma%2 == 0){
            listaP4.addinPos(0, 0);
        }
        else{
            listaP4.addinPos(1,0);
        }
    }

}

void Algorithm::buscarError()
{
    ListaSimple errores;
    int suma = 0;
    int cont = 2;

    //Revisa si el primer bit de paridad es correcto

    while(cont < ListaConError.getLength()){
        suma += *ListaConError.getData(cont);
        cont += 2;
    }

    if(*listaP1.getData(0) == 1 & suma%2 != 0 | *listaP1.getData(0) == 0 & suma%2 == 0){
        errores.add(1);
    }

    //Revisa si el segundo bit de paridad es correcto
    cont = 5;
    suma = 0;
    suma += *ListaConError.getData(2);
    while(cont < ListaConError.getLength()){
        suma += *ListaConError.getData(cont);
        suma += *ListaConError.getData(cont+1);
        cont += 4;
    }

    if(*listaP2.getData(0) == 1 & suma%2 != 0 | *listaP2.getData(0) == 0 & suma%2 == 0){
        errores.add(2);
    }


    //Revisa si el tercer bit de paridad es correcto
    cont = 11;
    suma = 0;
    suma += *ListaConError.getData(4);
    suma += *ListaConError.getData(5);
    suma += *ListaConError.getData(6);
    while(cont < ListaConError.getLength()){
        suma += *ListaConError.getData(cont);
        suma += *ListaConError.getData(cont+1);
        suma += *ListaConError.getData(cont+2);
        suma += *ListaConError.getData(cont+3);
        cont += 8;
    }

    if(*listaP3.getData(0) == 1 & suma%2 != 0 | *listaP3.getData(0) == 0 & suma%2 == 0){
        errores.add(4);
    }


    //Revisa si el cuarto bit de paridad es correcto
    cont = 9;
    suma = 0;
    while(cont < ListaConError.getLength()){
        suma += *ListaConError.getData(cont);
        cont ++;
    }

    if(*listaP4.getData(0) == 1 & suma%2 != 0 | *listaP4.getData(0) == 0 & suma%2 == 0){
        errores.add(8);
    }

    cout<<"Lista Erronea: ";
    for(int j = 0; j < ListaConError.getLength(); j++){
        cout<<*ListaConError.getData(j);
    }
    cout<<endl;


    ListaCompleta = ListaConError;
    int sumaTotal = 0;

    for(int j = 0; j < errores.getLength(); j++){
        sumaTotal += *errores.getData(j);
    }

    if(*ListaCompleta.getData(sumaTotal-1) == 0){
        ListaCompleta.addinPos(1, sumaTotal-1);
        ListaCompleta.deleteNode(sumaTotal);
    }
    else{
        ListaCompleta.addinPos(0, sumaTotal-1);
        ListaCompleta.deleteNode(sumaTotal);
    }

    cout<<"Lista Erronea: ";
    for(int j = 0; j < ListaConError.getLength(); j++){
        cout<<*ListaConError.getData(j);
    }
    cout<<endl;

    cout<<"Lista Correcta: ";
    for(int j = 0; j < ListaCompleta.getLength(); j++){
        cout<<*ListaCompleta.getData(j);
    }
}


ListaSimple Algorithm::getListaP1(){
    return listaP1;
}

ListaSimple Algorithm::getListaP2(){
    return listaP2;
}

ListaSimple Algorithm::getListaP3(){
    return listaP3;
}

ListaSimple Algorithm::getListaP4()
{
    return listaP4;
}
