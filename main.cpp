#include "algorithm.h"
#include "hamingtables.h"
#include "listasimple.h"
#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HamingTables w;
    w.show();
    return a.exec();

    ListaSimple lista;
    ListaSimple lista1;
    Algorithm A;

    lista.add(1);
    lista.add(0);
    lista.add(1);
    lista.add(1);
    lista.add(0);
    lista.add(1);
    lista.add(0);
    lista.add(1);
    lista.add(1);
    lista.add(1);
    lista.add(0);
    lista.add(1);

    lista1.add(1);
    lista1.add(0);
    lista1.add(1);
    lista1.add(1);
    lista1.add(0);
    lista1.add(1);
    lista1.add(0);
    lista1.add(1);
    lista1.add(1);
    lista1.add(1);
    lista1.add(0);
    lista1.add(1);

    A.init(lista, lista1, 1);
    A.insertarError();
    A.buscarError();

}
