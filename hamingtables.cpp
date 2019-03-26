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
    printBin(listaA);

///////////////////////////////////////
    Algorithm A;
    int aux = pd.getParidad();


        A.init(listaA, listaB, aux);

        p1(A.getListaP1());
        p2(A.getListaP2());
        p3(A.getListaP3());
        p4(A.getListaP4());
        palabraDeDatosPar(listaA,*A.getListaP1().getData(0),*A.getListaP2().getData(0),*A.getListaP3().getData(0),*A.getListaP4().getData(0));

        A.insertarError();

        this->paridad = A.getParidad();
        palabraDeDatos2(A.getListaConError());
        p12(A.getListaP1E());
        p22(A.getListaP2E());
        p32(A.getListaP3E());
        p42(A.getListaP4E());
        cout<<"pos error: "<<A.getPosError()<<endl;
        int posError = A.getPosError();
        if(posError != -1){
              ui->tableWidget_2->item(0, posError)->setBackgroundColor(Qt::red);
        }


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
        ui->tableWidget->setItem(4, a, theItem);
        i++;
        contList++;
        if(i == 8){
            a +=i;
            i = 0;
        }
    }
    QTableWidgetItem *theItem = new QTableWidgetItem();
    int myNumber = *listaP4.getData(8);
    theItem->setData(Qt::EditRole, myNumber);
    ui->tableWidget->setItem(4, 15, theItem);
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
    QString aux;
    for (int i = 0; i < s.length(); ++i) {
        aux.append(BinBCDAux(s[i]));
    }
    ui->BCD1->setText(aux);
}

int HamingTables::BinHex(int n)
{
    char hexaDeciNum[3];
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
       QString aux(hexaDeciNum);
       QString str;
       for (int i = 0; i < aux.length(); ++i) {
            str.insert(aux.length()-i,aux[i]);
       }
       ui->primeroH->setText(str);

}

void HamingTables::printBin(ListaSimple listaA)
{
    QString str;
    for (int i = 0; i < listaA.getLength(); ++i) {
        str.append(QString::number(*listaA.getData(i)));
    }
    ui->numeroBin->setText(str);
}


void HamingTables::palabraDeDatos2(ListaSimple listaA)
{
    int a = 0;
    for (int i = 0; i < 17; ++i) {
        QTableWidgetItem *theItem = new QTableWidgetItem();
        int myNumber = *listaA.getData(a);
        theItem->setData(Qt::EditRole, myNumber);
        ui->tableWidget_2->setItem(0, i, theItem);
        a++;
    }
}
void HamingTables::p12(ListaSimple listaP1)
{
    int b = 0;
    for (int a = 0; a < 16; ++a) {
        QTableWidgetItem *theItem = new QTableWidgetItem();
        int myNumber = *listaP1.getData(b);
        theItem->setData(Qt::EditRole, myNumber);
        ui->tableWidget_2->setItem(1, a, theItem);
        a += 1;
        b += 1;
    }
    QTableWidgetItem *theItem = new QTableWidgetItem();
    int x = *listaP1.getData(0);
    int y = !*listaP1.getData(0);
    if(this->paridad == 1 ){
        if(*listaP1.getData(listaP1.getLength()-1) == 1){
           ui->tableWidget_2->setItem(1, 16,  new QTableWidgetItem("Correcto"));
           theItem->setData(Qt::EditRole, x);
           ui->tableWidget_2->setItem(1, 17, theItem);
        }else{
           ui->tableWidget_2->setItem(1, 16, new QTableWidgetItem("Error"));
           theItem->setData(Qt::EditRole, y);
           ui->tableWidget_2->setItem(1, 17, theItem);
        }
    }else{
        if(*listaP1.getData(listaP1.getLength()-1) == 0){
           ui->tableWidget_2->setItem(1, 16, new QTableWidgetItem("Correcto"));
           theItem->setData(Qt::EditRole, x);
           ui->tableWidget_2->setItem(1, 17, theItem);
        }else{
           ui->tableWidget_2->setItem(1, 16, new QTableWidgetItem("Error"));
           theItem->setData(Qt::EditRole, y);
           ui->tableWidget_2->setItem(1, 17, theItem);
        }
    }
}
void HamingTables::p22(ListaSimple listaP2)
{
    int i = 0, contList = 0;
    for (int a = 1; a < 17; ++a) {
        QTableWidgetItem *theItem = new QTableWidgetItem();
        int myNumber = *listaP2.getData(contList);
        theItem->setData(Qt::EditRole, myNumber);
        ui->tableWidget_2->setItem(2, a, theItem);
        i++;
        contList++;
        if(i == 2){
            a +=i;
            i = 0;
        }
    }
    QTableWidgetItem *theItem = new QTableWidgetItem();
    int x = *listaP2.getData(0);
    int y = !*listaP2.getData(0);
    if(this->paridad == 1 ){
        if(*listaP2.getData(listaP2.getLength()-1) == 1){
           ui->tableWidget_2->setItem(2, 16, new QTableWidgetItem("Correcto"));
           theItem->setData(Qt::EditRole, x);
           ui->tableWidget_2->setItem(2, 17, theItem);
        }else{
           ui->tableWidget_2->setItem(2, 16, new QTableWidgetItem("Error"));
           theItem->setData(Qt::EditRole, y);
           ui->tableWidget_2->setItem(2, 17, theItem);
        }
    }else{
        if(*listaP2.getData(listaP2.getLength()-1) == 0){
           ui->tableWidget_2->setItem(2, 16, new QTableWidgetItem("Correcto"));
           theItem->setData(Qt::EditRole, x);
           ui->tableWidget_2->setItem(2, 17, theItem);
        }else{
           ui->tableWidget_2->setItem(2, 16, new QTableWidgetItem("Error"));
           theItem->setData(Qt::EditRole, y);
           ui->tableWidget_2->setItem(2, 17, theItem);
        }
    }
}
void HamingTables::p32(ListaSimple listaP3)
{
    int i = 0, contList = 0;
    for (int a = 3; a < 17; ++a) {
        QTableWidgetItem *theItem = new QTableWidgetItem();
        int myNumber = *listaP3.getData(contList);
        theItem->setData(Qt::EditRole, myNumber);
        ui->tableWidget_2->setItem(3, a, theItem);
        i++;
        contList++;
        if(i == 4){
            a += i;
            i = 0;
        }
    }
    QTableWidgetItem *theItem = new QTableWidgetItem();
    int x = *listaP3.getData(0);
    int y = !*listaP3.getData(0);
    if(this->paridad == 1 ){
        if(*listaP3.getData(listaP3.getLength()-1) == 1){
           ui->tableWidget_2->setItem(3, 16, new QTableWidgetItem("Correcto"));
           theItem->setData(Qt::EditRole, x);
           ui->tableWidget_2->setItem(3, 17, theItem);
        }else{
           ui->tableWidget_2->setItem(3, 16, new QTableWidgetItem("Error"));
           theItem->setData(Qt::EditRole, y);
           ui->tableWidget_2->setItem(3, 17, theItem);
        }
    }else{
        if(*listaP3.getData(listaP3.getLength()-1) == 0){
           ui->tableWidget_2->setItem(3, 16, new QTableWidgetItem("Correcto"));
           theItem->setData(Qt::EditRole, x);
           ui->tableWidget_2->setItem(3, 17, theItem);
        }else{
           ui->tableWidget_2->setItem(3, 16, new QTableWidgetItem("Error"));
           theItem->setData(Qt::EditRole, y);
           ui->tableWidget_2->setItem(3, 17, theItem);
        }
    }
}
void HamingTables::p42(ListaSimple listaP4)
{
    cout << listaP4.getLength();
    int i = 0, contList = 0;
    for (int a = 7; a < 17; ++a) {
        QTableWidgetItem *theItem = new QTableWidgetItem();
        int myNumber = *listaP4.getData(contList);
        theItem->setData(Qt::EditRole, myNumber);
        ui->tableWidget_2->setItem(4, a, theItem);
        i++;
        contList++;
        if(i == 9){
            a +=i;
            i = 0;
        }
    }
    QTableWidgetItem *theItem = new QTableWidgetItem();
    int x = *listaP4.getData(0);
    int y = !*listaP4.getData(0);
    if(this->paridad == 1 ){
        if(*listaP4.getData(listaP4.getLength()-1) == 1){
           ui->tableWidget_2->setItem(4, 16, new QTableWidgetItem("Correcto"));
           theItem->setData(Qt::EditRole, x);
           ui->tableWidget_2->setItem(4, 17, theItem);
        }else{
           ui->tableWidget_2->setItem(4, 16, new QTableWidgetItem("Error"));
           theItem->setData(Qt::EditRole, y);
           ui->tableWidget_2->setItem(4, 17, theItem);
        }
    }else{
        if(*listaP4.getData(listaP4.getLength()-1) == 0){
           ui->tableWidget_2->setItem(4, 16, new QTableWidgetItem("Correcto"));
           theItem->setData(Qt::EditRole, x);
           ui->tableWidget_2->setItem(4, 17, theItem);
        }else{
           ui->tableWidget_2->setItem(4, 16, new QTableWidgetItem("Error"));
           theItem->setData(Qt::EditRole, y);
           ui->tableWidget_2->setItem(4, 17, theItem);
        }
    }
}

void HamingTables::palabraDeDatosPar(ListaSimple listaP, int P1, int P2, int P3, int P4)
{
    int contList = 0 ;
    for (int i = 0; i < 16; ++i) {
        QTableWidgetItem *theItem = new QTableWidgetItem();
        int myNumber;
        if(i == 0){
            myNumber = P1;

        }else if(i == 1){
            myNumber = P2;

        }else if(i == 3){
            myNumber = P3;

        }else if(i == 7){
            myNumber = P4;

        }else{
            myNumber = *listaP.getData(contList);
            contList++;
        }
        theItem->setData(Qt::EditRole, myNumber);
        ui->tableWidget->setItem(5, i, theItem);
    }
}
