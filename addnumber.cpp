#include "addnumber.h"
#include "ui_addnumber.h"
#include <QMessageBox>

AddNumber::AddNumber(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNumber)
{
    ui->setupUi(this);
}

AddNumber::~AddNumber()
{
    delete ui;
}

void AddNumber::on_buttonBox_accepted()
{

    if(paridad == 2){
        QMessageBox msgBox;
         msgBox.setText("Error"
                        "Debe seleccionar un tipo de paridad");
         msgBox.exec();
         reject();
    }else{
        accept();
        takeNumber();
    }

}
void AddNumber::on_buttonBox_rejected()
{
    reject();
}
ListaSimple AddNumber::takeList1()
{
    return lista1;
}
ListaSimple AddNumber::takeList2()
{
    return lista2;
}
void AddNumber::takeNumber()
{
    lista1.add((int)ui->C0->value());
    lista1.add((int)ui->C1->value());
    lista1.add((int)ui->C2->value());
    lista1.add((int)ui->C3->value());
    lista1.add((int)ui->C4->value());
    lista1.add((int)ui->C5->value());
    lista1.add((int)ui->C6->value());
    lista1.add((int)ui->C7->value());
    lista1.add((int)ui->C8->value());
    lista1.add((int)ui->C9->value());
    lista1.add((int)ui->C10->value());
    lista1.add((int)ui->C11->value());
    lista2.add((int)ui->E0->value());
    lista2.add((int)ui->E1->value());
    lista2.add((int)ui->E2->value());
    lista2.add((int)ui->E3->value());
    lista2.add((int)ui->E4->value());
    lista2.add((int)ui->E5->value());
    lista2.add((int)ui->E6->value());
    lista2.add((int)ui->E7->value());
    lista2.add((int)ui->E8->value());
    lista2.add((int)ui->E9->value());
    lista2.add((int)ui->E10->value());
    lista2.add((int)ui->E11->value());
}

int AddNumber::getParidad()
{
    return paridad;
}

void AddNumber::on_par_clicked()
{
    paridad = 1;
}

void AddNumber::on_impar_clicked()
{
    paridad = 0;
}
