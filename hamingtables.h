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
    int BinBCD(ListaSimple);
    char* Binario(ListaSimple);

};

#endif // HAMINGTABLES_H
