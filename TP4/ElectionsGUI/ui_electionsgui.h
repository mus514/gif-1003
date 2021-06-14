/********************************************************************************
** Form generated from reading UI file 'electionsgui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELECTIONSGUI_H
#define UI_ELECTIONSGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ElectionsGUIClass
{
public:
    QAction *Inscription_d_un_candidat;
    QAction *Inscription_d_un_electeur;
    QAction *Desinscription_d_une_personne;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QTextEdit *affichage;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuOperations;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ElectionsGUIClass)
    {
        if (ElectionsGUIClass->objectName().isEmpty())
            ElectionsGUIClass->setObjectName(QString::fromUtf8("ElectionsGUIClass"));
        ElectionsGUIClass->resize(800, 600);
        Inscription_d_un_candidat = new QAction(ElectionsGUIClass);
        Inscription_d_un_candidat->setObjectName(QString::fromUtf8("Inscription_d_un_candidat"));
        Inscription_d_un_electeur = new QAction(ElectionsGUIClass);
        Inscription_d_un_electeur->setObjectName(QString::fromUtf8("Inscription_d_un_electeur"));
        Desinscription_d_une_personne = new QAction(ElectionsGUIClass);
        Desinscription_d_une_personne->setObjectName(QString::fromUtf8("Desinscription_d_une_personne"));
        actionQuitter = new QAction(ElectionsGUIClass);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(ElectionsGUIClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        affichage = new QTextEdit(centralwidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));
        affichage->setGeometry(QRect(80, 70, 621, 431));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 50, 201, 17));
        ElectionsGUIClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ElectionsGUIClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuOperations = new QMenu(menubar);
        menuOperations->setObjectName(QString::fromUtf8("menuOperations"));
        ElectionsGUIClass->setMenuBar(menubar);
        statusbar = new QStatusBar(ElectionsGUIClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ElectionsGUIClass->setStatusBar(statusbar);

        menubar->addAction(menuOperations->menuAction());
        menuOperations->addAction(Inscription_d_un_candidat);
        menuOperations->addAction(Inscription_d_un_electeur);
        menuOperations->addAction(Desinscription_d_une_personne);
        menuOperations->addAction(actionQuitter);

        retranslateUi(ElectionsGUIClass);
        QObject::connect(actionQuitter, SIGNAL(triggered()), ElectionsGUIClass, SLOT(close()));
        QObject::connect(Inscription_d_un_electeur, SIGNAL(triggered()), ElectionsGUIClass, SLOT(dialogElecteur()));
        QObject::connect(Inscription_d_un_candidat, SIGNAL(triggered()), ElectionsGUIClass, SLOT(dialogCandidat()));
        QObject::connect(Desinscription_d_une_personne, SIGNAL(triggered()), ElectionsGUIClass, SLOT(dialogDesinscrire()));

        QMetaObject::connectSlotsByName(ElectionsGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *ElectionsGUIClass)
    {
        ElectionsGUIClass->setWindowTitle(QApplication::translate("ElectionsGUIClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        Inscription_d_un_candidat->setText(QApplication::translate("ElectionsGUIClass", "Inscription d'un candidat", 0, QApplication::UnicodeUTF8));
        Inscription_d_un_electeur->setText(QApplication::translate("ElectionsGUIClass", "Inscription d'un electeur", 0, QApplication::UnicodeUTF8));
        Desinscription_d_une_personne->setText(QApplication::translate("ElectionsGUIClass", "Desinscription d'une personne", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("ElectionsGUIClass", "Quitter", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ElectionsGUIClass", "Console d'inscription", 0, QApplication::UnicodeUTF8));
        menuOperations->setTitle(QApplication::translate("ElectionsGUIClass", "Operations", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ElectionsGUIClass: public Ui_ElectionsGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELECTIONSGUI_H
