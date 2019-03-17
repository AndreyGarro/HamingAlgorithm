#ifndef ADDNUMBER_H
#define ADDNUMBER_H

#include <QDialog>
#include "listasimple.h"

namespace Ui {
class AddNumber;
}

class AddNumber : public QDialog
{
    Q_OBJECT

public:
    explicit AddNumber(QWidget *parent = 0);
    ~AddNumber();
    ListaSimple takeList1();
    ListaSimple takeList2();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void takeNumber();

    void on_par_clicked();

    void on_impar_clicked();

private:
    Ui::AddNumber *ui;
    ListaSimple lista1, lista2;
    int paridad = 2;
};

#endif // ADDNUMBER_H
