#pragma once
#include <QWidget>
#include <QLabel>
#include <QTableView>
#include <QPushButton>
#include <QVBoxLayout>
#include "Service.h"
#include "mytablemodel.h"

class GUI : public QWidget {
    Q_OBJECT
private:
    Service& service;
    MyTableModel* model;
    QTableView* table;

    QLineEdit* txtId;
    QLineEdit* txtNume;
    QLineEdit* txtTip;
    QLineEdit* txtPret;
    QPushButton* btnAdauga;

    QSlider* sliderFiltru;
    QLabel* lblSliderVal;

    void initGUI();
    void loadData();
    void initConnect();
public:
    GUI(Service& srv);
};
