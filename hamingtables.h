#ifndef HAMINGTABLES_H
#define HAMINGTABLES_H

#include <QMainWindow>

namespace Ui {
class HamingTables;
}

class HamingTables : public QMainWindow
{
    Q_OBJECT

public:
    explicit HamingTables(QWidget *parent = 0);
    ~HamingTables();

private:
    Ui::HamingTables *ui;
};

#endif // HAMINGTABLES_H
