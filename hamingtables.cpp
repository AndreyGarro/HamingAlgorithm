#include "hamingtables.h"
#include "ui_hamingtables.h"

HamingTables::HamingTables(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HamingTables)
{
    ui->setupUi(this);
}

HamingTables::~HamingTables()
{
    delete ui;
}
