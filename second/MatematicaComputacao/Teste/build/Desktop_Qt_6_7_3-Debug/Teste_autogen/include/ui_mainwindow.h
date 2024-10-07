/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEditUsername;
    QComboBox *comboBoxDiscipline;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_7;
    QLineEdit *lineEdit_n2Second;
    QLabel *label_6;
    QLabel *label_5;
    QLineEdit *lineEdit_n1Second;
    QLineEdit *lineEdit_n1First;
    QLineEdit *lineEdit_n2First;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButtonPrint;
    QPushButton *pushButtonAddStudent;
    QLabel *label_4;
    QPushButton *pushButtonCheckTest;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEditUsername = new QLineEdit(centralwidget);
        lineEditUsername->setObjectName("lineEditUsername");
        lineEditUsername->setGeometry(QRect(320, 60, 201, 30));
        comboBoxDiscipline = new QComboBox(centralwidget);
        comboBoxDiscipline->addItem(QString());
        comboBoxDiscipline->addItem(QString());
        comboBoxDiscipline->addItem(QString());
        comboBoxDiscipline->setObjectName("comboBoxDiscipline");
        comboBoxDiscipline->setGeometry(QRect(320, 110, 200, 40));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 180, 71, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(240, 70, 54, 14));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(240, 120, 54, 14));
        lineEdit_n2Second = new QLineEdit(centralwidget);
        lineEdit_n2Second->setObjectName("lineEdit_n2Second");
        lineEdit_n2Second->setGeometry(QRect(470, 267, 100, 30));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(400, 277, 53, 14));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(400, 227, 53, 14));
        lineEdit_n1Second = new QLineEdit(centralwidget);
        lineEdit_n1Second->setObjectName("lineEdit_n1Second");
        lineEdit_n1Second->setGeometry(QRect(470, 219, 100, 30));
        lineEdit_n1First = new QLineEdit(centralwidget);
        lineEdit_n1First->setObjectName("lineEdit_n1First");
        lineEdit_n1First->setGeometry(QRect(230, 220, 100, 30));
        lineEdit_n2First = new QLineEdit(centralwidget);
        lineEdit_n2First->setObjectName("lineEdit_n2First");
        lineEdit_n2First->setGeometry(QRect(230, 270, 100, 30));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 227, 53, 14));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(480, 178, 71, 16));
        pushButtonPrint = new QPushButton(centralwidget);
        pushButtonPrint->setObjectName("pushButtonPrint");
        pushButtonPrint->setGeometry(QRect(500, 350, 150, 40));
        pushButtonAddStudent = new QPushButton(centralwidget);
        pushButtonAddStudent->setObjectName("pushButtonAddStudent");
        pushButtonAddStudent->setGeometry(QRect(310, 350, 150, 40));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 277, 53, 14));
        pushButtonCheckTest = new QPushButton(centralwidget);
        pushButtonCheckTest->setObjectName("pushButtonCheckTest");
        pushButtonCheckTest->setGeometry(QRect(110, 350, 150, 40));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEditUsername->setPlaceholderText(QString());
        comboBoxDiscipline->setItemText(0, QCoreApplication::translate("MainWindow", "Bioqu\303\255mica", nullptr));
        comboBoxDiscipline->setItemText(1, QCoreApplication::translate("MainWindow", "F\303\255sico-qu\303\255mica", nullptr));
        comboBoxDiscipline->setItemText(2, QCoreApplication::translate("MainWindow", "Qu\303\255mica Geral", nullptr));

        comboBoxDiscipline->setCurrentText(QCoreApplication::translate("MainWindow", "Bioqu\303\255mica", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "1\302\272 Bimestre", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Nome", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Disciplina", nullptr));
        lineEdit_n2Second->setPlaceholderText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Nota 2", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Nota 1", nullptr));
        lineEdit_n1Second->setPlaceholderText(QString());
        lineEdit_n1First->setPlaceholderText(QString());
        lineEdit_n2First->setPlaceholderText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Nota 1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "2\302\272 Bimestre", nullptr));
        pushButtonPrint->setText(QCoreApplication::translate("MainWindow", "Imprimir Notas", nullptr));
        pushButtonAddStudent->setText(QCoreApplication::translate("MainWindow", "Cadastrar  Aluno", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Nota 2", nullptr));
        pushButtonCheckTest->setText(QCoreApplication::translate("MainWindow", "Inserir  Substutiva", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
