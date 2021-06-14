/********************************************************************************
** Form generated from reading UI file 'candidatinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANDIDATINTERFACE_H
#define UI_CANDIDATINTERFACE_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_candidatInterfaceClass
{
public:
    QLineEdit *nom;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *prenom;
    QLineEdit *ville;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *nas;
    QLineEdit *province;
    QLineEdit *rue;
    QSpinBox *nocivic;
    QPushButton *confirmer;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label125;
    QLineEdit *codepostal;
    QLabel *label_12;
    QSpinBox *parti;
    QLabel *label_13;
    QDateEdit *dateEdit;

    void setupUi(QDialog *candidatInterfaceClass)
    {
        if (candidatInterfaceClass->objectName().isEmpty())
            candidatInterfaceClass->setObjectName(QString::fromUtf8("candidatInterfaceClass"));
        candidatInterfaceClass->resize(381, 473);
        nom = new QLineEdit(candidatInterfaceClass);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(120, 100, 151, 27));
        label_3 = new QLabel(candidatInterfaceClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 20, 201, 17));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_7 = new QLabel(candidatInterfaceClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 140, 53, 17));
        label = new QLabel(candidatInterfaceClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 230, 53, 17));
        label_4 = new QLabel(candidatInterfaceClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 200, 71, 17));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_4->setFont(font1);
        prenom = new QLineEdit(candidatInterfaceClass);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(120, 130, 151, 27));
        ville = new QLineEdit(candidatInterfaceClass);
        ville->setObjectName(QString::fromUtf8("ville"));
        ville->setGeometry(QRect(110, 250, 101, 27));
        label_2 = new QLabel(candidatInterfaceClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 80, 53, 17));
        label_6 = new QLabel(candidatInterfaceClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 110, 53, 17));
        label_10 = new QLabel(candidatInterfaceClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 50, 121, 17));
        label_10->setFont(font1);
        label_11 = new QLabel(candidatInterfaceClass);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(50, 260, 53, 17));
        nas = new QLineEdit(candidatInterfaceClass);
        nas->setObjectName(QString::fromUtf8("nas"));
        nas->setGeometry(QRect(140, 70, 111, 27));
        nas->setInputMethodHints(Qt::ImhNone);
        nas->setMaxLength(11);
        province = new QLineEdit(candidatInterfaceClass);
        province->setObjectName(QString::fromUtf8("province"));
        province->setGeometry(QRect(110, 280, 113, 27));
        rue = new QLineEdit(candidatInterfaceClass);
        rue->setObjectName(QString::fromUtf8("rue"));
        rue->setGeometry(QRect(220, 220, 151, 27));
        rue->setInputMethodHints(Qt::ImhDigitsOnly);
        nocivic = new QSpinBox(candidatInterfaceClass);
        nocivic->setObjectName(QString::fromUtf8("nocivic"));
        nocivic->setGeometry(QRect(110, 220, 71, 27));
        nocivic->setMinimum(1);
        nocivic->setMaximum(100000);
        confirmer = new QPushButton(candidatInterfaceClass);
        confirmer->setObjectName(QString::fromUtf8("confirmer"));
        confirmer->setGeometry(QRect(130, 430, 131, 28));
        label_8 = new QLabel(candidatInterfaceClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(190, 230, 31, 17));
        label_5 = new QLabel(candidatInterfaceClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 170, 111, 17));
        label_9 = new QLabel(candidatInterfaceClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(220, 260, 71, 17));
        label125 = new QLabel(candidatInterfaceClass);
        label125->setObjectName(QString::fromUtf8("label125"));
        label125->setGeometry(QRect(50, 290, 53, 17));
        codepostal = new QLineEdit(candidatInterfaceClass);
        codepostal->setObjectName(QString::fromUtf8("codepostal"));
        codepostal->setGeometry(QRect(300, 250, 71, 27));
        label_12 = new QLabel(candidatInterfaceClass);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 320, 121, 17));
        label_12->setFont(font1);
        parti = new QSpinBox(candidatInterfaceClass);
        parti->setObjectName(QString::fromUtf8("parti"));
        parti->setGeometry(QRect(40, 340, 51, 27));
        parti->setMinimum(1);
        parti->setMaximum(5);
        label_13 = new QLabel(candidatInterfaceClass);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(150, 320, 211, 111));
        dateEdit = new QDateEdit(candidatInterfaceClass);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(160, 170, 110, 27));
        dateEdit->setMaximumDateTime(QDateTime(QDate(7921, 1, 1), QTime(23, 59, 59)));
        dateEdit->setMinimumDate(QDate(1770, 1, 1));
        dateEdit->setCalendarPopup(true);

        retranslateUi(candidatInterfaceClass);
        QObject::connect(confirmer, SIGNAL(clicked()), candidatInterfaceClass, SLOT(validerCandidat()));

        QMetaObject::connectSlotsByName(candidatInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *candidatInterfaceClass)
    {
        candidatInterfaceClass->setWindowTitle(QApplication::translate("candidatInterfaceClass", "candidatInterface", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("candidatInterfaceClass", "Ajout d'un candidat", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("candidatInterfaceClass", "Prenom", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("candidatInterfaceClass", "No Civic", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("candidatInterfaceClass", "Adresse", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("candidatInterfaceClass", "NAS", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("candidatInterfaceClass", "Nom", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("candidatInterfaceClass", "Identification", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("candidatInterfaceClass", "Ville", 0, QApplication::UnicodeUTF8));
        nas->setInputMask(QString());
        nas->setText(QString());
        confirmer->setText(QApplication::translate("candidatInterfaceClass", "Confirmer", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("candidatInterfaceClass", "Rue", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("candidatInterfaceClass", "Date de naissance", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("candidatInterfaceClass", "Code Postal", 0, QApplication::UnicodeUTF8));
        label125->setText(QApplication::translate("candidatInterfaceClass", "Province", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("candidatInterfaceClass", "Parti Politique", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("candidatInterfaceClass", "1-BLOC QUEBECOIS\n"
"2-CONSERVATEUR,\n"
"3-INDEPENDANT\n"
"4-LIBERAL\n"
"5-NOUVEAU PARTI DEMOCRATIQUE", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("candidatInterfaceClass", "dd-MM-yyyy", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class candidatInterfaceClass: public Ui_candidatInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANDIDATINTERFACE_H
