/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *boton_start;
    QPushButton *boton_reiniciar;
    QLabel *nivel;
    QLabel *puntaje;
    QLabel *puntos_valor;
    QPushButton *instrucciones_boton;
    QLabel *nivel_valor;
    QPushButton *boton_aceptar;
    QPushButton *boton_denegar;
    QPlainTextEdit *datoInmigrante;
    QPlainTextEdit *reglas;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(710, 820);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(195, 195, 195)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        boton_start = new QPushButton(centralwidget);
        boton_start->setObjectName("boton_start");
        boton_start->setGeometry(QRect(210, 20, 281, 31));
        boton_start->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: green;\n"
"selection-color: green;\n"
"selection-background-color: black;"));
        boton_reiniciar = new QPushButton(centralwidget);
        boton_reiniciar->setObjectName("boton_reiniciar");
        boton_reiniciar->setGeometry(QRect(190, 710, 281, 31));
        boton_reiniciar->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: grey;\n"
"selection-color: grey;\n"
"selection-background-color: black;"));
        nivel = new QLabel(centralwidget);
        nivel->setObjectName("nivel");
        nivel->setGeometry(QRect(50, 60, 71, 31));
        QFont font;
        font.setPointSize(20);
        nivel->setFont(font);
        puntaje = new QLabel(centralwidget);
        puntaje->setObjectName("puntaje");
        puntaje->setGeometry(QRect(360, 60, 131, 41));
        puntaje->setFont(font);
        puntos_valor = new QLabel(centralwidget);
        puntos_valor->setObjectName("puntos_valor");
        puntos_valor->setGeometry(QRect(510, 70, 61, 31));
        puntos_valor->setFont(font);
        instrucciones_boton = new QPushButton(centralwidget);
        instrucciones_boton->setObjectName("instrucciones_boton");
        instrucciones_boton->setGeometry(QRect(600, 60, 41, 41));
        QFont font1;
        font1.setPointSize(16);
        instrucciones_boton->setFont(font1);
        nivel_valor = new QLabel(centralwidget);
        nivel_valor->setObjectName("nivel_valor");
        nivel_valor->setGeometry(QRect(130, 60, 49, 31));
        nivel_valor->setFont(font);
        boton_aceptar = new QPushButton(centralwidget);
        boton_aceptar->setObjectName("boton_aceptar");
        boton_aceptar->setGeometry(QRect(380, 550, 241, 101));
        boton_aceptar->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: green;\n"
"selection-color: green;\n"
"selection-background-color: black;"));
        boton_denegar = new QPushButton(centralwidget);
        boton_denegar->setObjectName("boton_denegar");
        boton_denegar->setGeometry(QRect(60, 550, 251, 101));
        boton_denegar->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: rgb(244, 67, 54);\n"
"selection-color: rgb(244, 67, 54);\n"
"selection-background-color: black;"));
        datoInmigrante = new QPlainTextEdit(centralwidget);
        datoInmigrante->setObjectName("datoInmigrante");
        datoInmigrante->setGeometry(QRect(360, 140, 301, 361));
        datoInmigrante->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";"));
        reglas = new QPlainTextEdit(centralwidget);
        reglas->setObjectName("reglas");
        reglas->setGeometry(QRect(30, 140, 291, 361));
        reglas->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 710, 25));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        boton_start->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        boton_reiniciar->setText(QCoreApplication::translate("MainWindow", "Reiniciar", nullptr));
        nivel->setText(QCoreApplication::translate("MainWindow", "nivel:", nullptr));
        puntaje->setText(QCoreApplication::translate("MainWindow", "puntaje:", nullptr));
        puntos_valor->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        instrucciones_boton->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        nivel_valor->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        boton_aceptar->setText(QCoreApplication::translate("MainWindow", "Aceptar", nullptr));
        boton_denegar->setText(QCoreApplication::translate("MainWindow", "Denegar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
