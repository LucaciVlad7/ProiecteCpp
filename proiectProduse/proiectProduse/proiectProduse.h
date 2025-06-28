#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_proiectProduse.h"

class proiectProduse : public QMainWindow
{
    Q_OBJECT

public:
    proiectProduse(QWidget *parent = nullptr);
    ~proiectProduse();

private:
    Ui::proiectProduseClass ui;
};
