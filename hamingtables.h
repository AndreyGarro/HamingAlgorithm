#ifndef HAMINGTABLES_H
#define HAMINGTABLES_H

#include <QMainWindow>
#include "listasimple.h"

namespace Ui {
class HamingTables;
}

class HamingTables : public QMainWindow
{
    Q_OBJECT

public:
    explicit HamingTables(QWidget *parent = 0);
    ~HamingTables();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HamingTables *ui;
    void palabraDeDatos(ListaSimple listaA);
    void p1(ListaSimple);
    void p2(ListaSimple);
    void p3(ListaSimple);
    void p4(ListaSimple);
    int BinDEC(ListaSimple);
    int BinBCD(int decimal);
    int BinHex(int);
    void printBin(ListaSimple listaA);
    void palabraDeDatos2(ListaSimple listaA);
    void p12(ListaSimple);
    void p22(ListaSimple);
    void p32(ListaSimple);
    void p42(ListaSimple);
    void palabraDeDatosPar(ListaSimple listaP, int P1, int P2, int P3, int P4);
    int paridad;
    int posError;

};

#endif // HAMINGTABLES_H
