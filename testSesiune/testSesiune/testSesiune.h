#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_testSesiune.h"

class testSesiune : public QMainWindow
{
    Q_OBJECT

public:
    testSesiune(QWidget *parent = nullptr);
    ~testSesiune();

private:
    Ui::testSesiuneClass ui;
};
