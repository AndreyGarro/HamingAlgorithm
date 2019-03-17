#include "hamingtables.h"
#include "ui_hamingtables.h"
#include "addnumber.h"
#include "iostream"
#include <string>
#include <sstream>
#include <math.h>

#include <cstdlib>

using namespace std;

HamingTables::HamingTables(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HamingTables)
{
    ui->setupUi(this);
    ///// Tabla 1
    ui->tableWidget->setColumnCount(16);
    ui->tableWidget->setRowCount(6);
    setWindowTitle("Haming Code");
    QStringList titulosH, titulosV;
    titulosH <<"p1"<<"p2"<<"d1"<<"p3"<<"d2"<<"d3"<<"d4"<<"p4"<<"d5"<<"d6"<<"d7"<<"d8"<<"d9"<<"d10"<<"d11"<<"d12";
    titulosV <<"Palabra de Datos"<<"p1"<<"p2"<<"p3"<<"p4"<<"Palabra de Datos";
    ui->tableWidget->setHorizontalHeaderLabels(titulosH);
    ui->tableWidget->setVerticalHeaderLabels(titulosV);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers( QAbstractItemView::NoEditTriggers );
    ///// Tabla 2
    ui->tableWidget_2->setColumnCount(18);
    ui->tableWidget_2->setRowCount(5);
    QStringList titulosH2, titulosV2;
    titulosH2 <<"p1"<<"p2"<<"d1"<<"p3"<<"d2"<<"d3"<<"d4"<<"p4"<<"d5"<<"d6"<<"d7"<<"d8"<<"d9"<<"d10"<<"d11"<<"d12"
            <<"Paridad"<<"Bit";
    titulosV2 <<"Palabra de Datos Recibida"<<"p1"<<"p2"<<"p3"<<"p4";
    ui->tableWidget_2->setHorizontalHeaderLabels(titulosH2);
    ui->tableWidget_2->setVerticalHeaderLabels(titulosV2);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->setEditTriggers( QAbstractItemView::NoEditTriggers);
}

HamingTables::~HamingTables()
{
    delete ui;
}

void HamingTables::on_pushButton_clicked()
{
    int res;
    AddNumber pd(this);
    res = pd.exec();
    if(res == QDialog::Rejected){
        return;
    }
    ListaSimple listaA = pd.takeList1();
    ListaSimple listaB = pd.takeList2();
    palabraDeDatos(listaA);
    ui->numeroDec->setText(QString::number(BinDEC(listaA)));
    ui->numeroBDC->setText(QString::number(BinBCD(listaA)));
//    p1(listaA);
//    p2(listaA);
//    p3(listaA);
//    p4(listaA);


}
void HamingTables::palabraDeDatos(ListaSimple listaA)
{
    int a = 0;
    for (int i = 0; i < 16; ++i) {
        if(i == 0 ||i == 1||i == 3 ||i == 7){

        }else
        {
            QTableWidgetItem *theItem = new QTableWidgetItem();
            int myNumber = *listaA.getData(a);
            theItem->setData(Qt::EditRole, myNumber);
            ui->tableWidget->setItem(0, i, theItem);
            a++;
        }
    }
}
//void HamingTables::p1(ListaSimple listaP1)
//{
//    for (int a = 0; a < 16; ++a) {
//        cout << *listaP1.getData(a);
//        cout << listaP1.getLength();
//        QTableWidgetItem *theItem = new QTableWidgetItem();
//        int myNumber = *listaP1.getData(a);
//        theItem->setData(Qt::EditRole, myNumber);
//        ui->tableWidget->setItem(0, a, theItem);
//        a += 1;
//    }

//}
//void HamingTables::p2(ListaSimple listaP2)
//{
//    int i = 0;
//    for (int a = 1; a < 16; ++a) {
//        cout << *listaP2.getData(a);
//        cout << listaP2.getLength();
//        QTableWidgetItem *theItem = new QTableWidgetItem();
//        int myNumber = *listaP2.getData(a);
//        theItem->setData(Qt::EditRole, myNumber);
//        ui->tableWidget->setItem(0, a, theItem);
//        i++;
//        if(i == 2){
//            a +=i;
//            i = 0;
//        }
//    }
//}
//void HamingTables::p3(ListaSimple listaP3)
//{
//    int i = 0;
//    for (int a = 3; a < 16; ++a) {
//        cout << *listaP3.getData(a);
//        cout << listaP3.getLength();
//        QTableWidgetItem *theItem = new QTableWidgetItem();
//        int myNumber = *listaP3.getData(a);
//        theItem->setData(Qt::EditRole, myNumber);
//        ui->tableWidget->setItem(0, a, theItem);
//        i++;
//        if(i == 4){
//            a +=i;
//            i = 0;
//        }
//    }
//}
//void HamingTables::p4(ListaSimple listaP4)
//{
//    int i = 0;
//    for (int a = 7; a < 16; ++a) {
//        cout << *listaP4.getData(a);
//        cout << listaP4.getLength();
//        QTableWidgetItem *theItem = new QTableWidgetItem();
//        int myNumber = *listaP4.getData(a);
//        theItem->setData(Qt::EditRole, myNumber);
//        ui->tableWidget->setItem(0, a, theItem);
//        i++;
//        if(i == 8){
//            a +=i;
//            i = 0;
//        }
//    }
//}

int HamingTables::BinDEC(ListaSimple listNumber)
{
    int a = 1,num = 0;
    for (int i = 0; i < listNumber.getLength(); ++i) {
        num += (*listNumber.getData(i))* pow( 2, listNumber.getLength()-a);
        a++;
    }
    return num;
}
int HamingTables::BinBCD(ListaSimple listNumber)
{
    return 0;
}
