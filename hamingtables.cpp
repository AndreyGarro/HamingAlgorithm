#include "hamingtables.h"
#include "ui_hamingtables.h"
#include "addnumber.h"
#include "iostream"
#include <string>
#include <math.h>
#include <cstdlib>

#include "algorithm.h"

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
    int numDEC = BinDEC(listaA);
    ui->numeroDec->setText(QString::number(numDEC));
    BinHex(numDEC);
    BinBCD(numDEC);

///////////////////////////////////////
    Algorithm A;
    A.init(listaA, listaB, 1);

    p1(A.getListaP1());
    p2(A.getListaP2());
    p3(A.getListaP3());
//    p4(A.getListaP4());
///////////////////////////////////////

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
void HamingTables::p1(ListaSimple listaP1)
{
    int b = 0;
    for (int a = 0; a < 16; ++a) {
        QTableWidgetItem *theItem = new QTableWidgetItem();
        int myNumber = *listaP1.getData(b);
        theItem->setData(Qt::EditRole, myNumber);
        ui->tableWidget->setItem(1, a, theItem);
        a += 1;
        b += 1;
    }

}
void HamingTables::p2(ListaSimple listaP2)
{
    int i = 0, contList = 0;
    for (int a = 1; a < 16; ++a) {
        QTableWidgetItem *theItem = new QTableWidgetItem();
        int myNumber = *listaP2.getData(contList);
        theItem->setData(Qt::EditRole, myNumber);
        ui->tableWidget->setItem(2, a, theItem);
        i++;
        contList++;
        if(i == 2){
            a +=i;
            i = 0;
        }
    }
}
void HamingTables::p3(ListaSimple listaP3)
{
    int i = 0, contList = 0;
    for (int a = 3; a < 16; ++a) {
        QTableWidgetItem *theItem = new QTableWidgetItem();
        int myNumber = *listaP3.getData(contList);
        theItem->setData(Qt::EditRole, myNumber);
        ui->tableWidget->setItem(3, a, theItem);
        i++;
        contList++;
        if(i == 4){
            a += i;
            i = 0;
        }
    }
}
void HamingTables::p4(ListaSimple listaP4)
{
    int i = 0, contList = 0;
    for (int a = 7; a < 16; ++a) {
        QTableWidgetItem *theItem = new QTableWidgetItem();
        int myNumber = *listaP4.getData(contList);
        theItem->setData(Qt::EditRole, myNumber);
        ui->tableWidget->setItem(0, a, theItem);
        i++;
        contList++;
        if(i == 8){
            a +=i;
            i = 0;
        }
    }
}

int HamingTables::BinDEC(ListaSimple listNumber)
{
    int a = 1,num = 0;
    for (int i = 0; i < listNumber.getLength(); ++i) {
        num += (*listNumber.getData(i))* pow( 2, listNumber.getLength()-a);
        a++;
    }
    return num;
}
QString BinBCDAux(char a){
    QString res;
    switch(a)
    {
        case '0': res = "0000";
            break;
        case '1': res = "0001";
            break;
        case '2': res = "0010";
            break;
        case '3': res = "0011";
            break;
        case '4': res = "0100";
            break;
        case '5': res = "0101";
            break;
        case '6': res = "0110";
            break;
        case '7': res = "0111";
            break;
        case '8': res = "1000";
            break;
        case '9': res = "1001";
            break;
        default: res = "Error";
            break;
    }
    return res;
}

int HamingTables::BinBCD(int decimal)
{
    string s = std::to_string(decimal);
    ui->BCD1->setText(BinBCDAux(s[0]));
    ui->BCD2->setText(BinBCDAux(s[1]));
    ui->BCD3->setText(BinBCDAux(s[2]));
}

int HamingTables::BinHex(int n)
{
       char hexaDeciNum[20];
       int i = 0;
       while(n!=0)
       {
           int temp  = 0;
           temp = n % 16;
           if(temp < 10)
           {
               hexaDeciNum[i] = temp + 48;
               i++;
           }
           else
           {
               hexaDeciNum[i] = temp + 55;
               i++;
           }
           n = n/16;
       }
       ui->primeroH->setText(QChar(hexaDeciNum[2]));
       ui->segundoH->setText(QChar(hexaDeciNum[1]));
       ui->tercerH->setText(QChar(hexaDeciNum[0]));

}
