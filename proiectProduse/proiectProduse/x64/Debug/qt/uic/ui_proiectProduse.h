/********************************************************************************
** Form generated from reading UI file 'proiectProduse.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROIECTPRODUSE_H
#define UI_PROIECTPRODUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_proiectProduseClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *proiectProduseClass)
    {
        if (proiectProduseClass->objectName().isEmpty())
            proiectProduseClass->setObjectName("proiectProduseClass");
        proiectProduseClass->resize(600, 400);
        menuBar = new QMenuBar(proiectProduseClass);
        menuBar->setObjectName("menuBar");
        proiectProduseClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(proiectProduseClass);
        mainToolBar->setObjectName("mainToolBar");
        proiectProduseClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(proiectProduseClass);
        centralWidget->setObjectName("centralWidget");
        proiectProduseClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(proiectProduseClass);
        statusBar->setObjectName("statusBar");
        proiectProduseClass->setStatusBar(statusBar);

        retranslateUi(proiectProduseClass);

        QMetaObject::connectSlotsByName(proiectProduseClass);
    } // setupUi

    void retranslateUi(QMainWindow *proiectProduseClass)
    {
        proiectProduseClass->setWindowTitle(QCoreApplication::translate("proiectProduseClass", "proiectProduse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class proiectProduseClass: public Ui_proiectProduseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROIECTPRODUSE_H
