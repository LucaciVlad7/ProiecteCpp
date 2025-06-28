/********************************************************************************
** Form generated from reading UI file 'testSesiune.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSESIUNE_H
#define UI_TESTSESIUNE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testSesiuneClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *testSesiuneClass)
    {
        if (testSesiuneClass->objectName().isEmpty())
            testSesiuneClass->setObjectName("testSesiuneClass");
        testSesiuneClass->resize(600, 400);
        menuBar = new QMenuBar(testSesiuneClass);
        menuBar->setObjectName("menuBar");
        testSesiuneClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(testSesiuneClass);
        mainToolBar->setObjectName("mainToolBar");
        testSesiuneClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(testSesiuneClass);
        centralWidget->setObjectName("centralWidget");
        testSesiuneClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(testSesiuneClass);
        statusBar->setObjectName("statusBar");
        testSesiuneClass->setStatusBar(statusBar);

        retranslateUi(testSesiuneClass);

        QMetaObject::connectSlotsByName(testSesiuneClass);
    } // setupUi

    void retranslateUi(QMainWindow *testSesiuneClass)
    {
        testSesiuneClass->setWindowTitle(QCoreApplication::translate("testSesiuneClass", "testSesiune", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testSesiuneClass: public Ui_testSesiuneClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSESIUNE_H
