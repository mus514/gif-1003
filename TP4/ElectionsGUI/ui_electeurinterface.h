/********************************************************************************
** Form generated from reading UI file 'electeurinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELECTEURINTERFACE_H
#define UI_ELECTEURINTERFACE_H

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

class Ui_electeurInterfaceClass
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label;
    QLabel *label_11;
    QLineEdit *nas;
    QLineEdit *nom;
    QLineEdit *prenom;
    QLineEdit *rue;
    QLineEdit *ville;
    QLineEdit *codepostal;
    QPushButton *confirmer;
    QLabel *label125;
    QLineEdit *province;
    QSpinBox *nocivic;
    QDateEdit *dateEdit;

    void setupUi(QDialog *electeurInterfaceClass)
    {
        if (electeurInterfaceClass->objectName().isEmpty())
            electeurInterfaceClass->setObjectName(QString::fromUtf8("electeurInterfaceClass"));
        electeurInterfaceClass->resize(377, 361);
        label_2 = new QLabel(electeurInterfaceClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 70, 53, 17));
        label_3 = new QLabel(electeurInterfaceClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 191, 17));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_4 = new QLabel(electeurInterfaceClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 190, 71, 17));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_4->setFont(font1);
        label_5 = new QLabel(electeurInterfaceClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 160, 111, 17));
        label_6 = new QLabel(electeurInterfaceClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 100, 53, 17));
        label_7 = new QLabel(electeurInterfaceClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 130, 53, 17));
        label_8 = new QLabel(electeurInterfaceClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(180, 220, 31, 17));
        label_9 = new QLabel(electeurInterfaceClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(210, 250, 71, 17));
        label_10 = new QLabel(electeurInterfaceClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 40, 121, 17));
        label_10->setFont(font1);
        label = new QLabel(electeurInterfaceClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 220, 53, 17));
        label_11 = new QLabel(electeurInterfaceClass);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(40, 250, 53, 17));
        nas = new QLineEdit(electeurInterfaceClass);
        nas->setObjectName(QString::fromUtf8("nas"));
        nas->setGeometry(QRect(130, 60, 111, 27));
        nas->setInputMethodHints(Qt::ImhNone);
        nas->setMaxLength(11);
        nom = new QLineEdit(electeurInterfaceClass);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(110, 90, 151, 27));
        prenom = new QLineEdit(electeurInterfaceClass);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(110, 120, 151, 27));
        rue = new QLineEdit(electeurInterfaceClass);
        rue->setObjectName(QString::fromUtf8("rue"));
        rue->setGeometry(QRect(210, 210, 151, 27));
        rue->setInputMethodHints(Qt::ImhDigitsOnly);
        ville = new QLineEdit(electeurInterfaceClass);
        ville->setObjectName(QString::fromUtf8("ville"));
        ville->setGeometry(QRect(100, 240, 101, 27));
        codepostal = new QLineEdit(electeurInterfaceClass);
        codepostal->setObjectName(QString::fromUtf8("codepostal"));
        codepostal->setGeometry(QRect(290, 240, 71, 27));
        confirmer = new QPushButton(electeurInterfaceClass);
        confirmer->setObjectName(QString::fromUtf8("confirmer"));
        confirmer->setGeometry(QRect(120, 320, 131, 28));
        label125 = new QLabel(electeurInterfaceClass);
        label125->setObjectName(QString::fromUtf8("label125"));
        label125->setGeometry(QRect(40, 280, 53, 17));
        province = new QLineEdit(electeurInterfaceClass);
        province->setObjectName(QString::fromUtf8("province"));
        province->setGeometry(QRect(100, 270, 113, 27));
        nocivic = new QSpinBox(electeurInterfaceClass);
        nocivic->setObjectName(QString::fromUtf8("nocivic"));
        nocivic->setGeometry(QRect(100, 210, 71, 27));
        nocivic->setMinimum(1);
        nocivic->setMaximum(100000);
        dateEdit = new QDateEdit(electeurInterfaceClass);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(170, 160, 110, 27));
        dateEdit->setMinimumDateTime(QDateTime(QDate(1770, 1, 1), QTime(0, 0, 0)));
        dateEdit->setMaximumDate(QDate(7937, 12, 31));
        dateEdit->setMinimumDate(QDate(1770, 1, 1));
        dateEdit->setCalendarPopup(true);

        retranslateUi(electeurInterfaceClass);
        QObject::connect(confirmer, SIGNAL(clicked()), electeurInterfaceClass, SLOT(validerElecteur()));

        QMetaObject::connectSlotsByName(electeurInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *electeurInterfaceClass)
    {
        electeurInterfaceClass->setWindowTitle(QApplication::translate("electeurInterfaceClass", "electeurInterface", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("electeurInterfaceClass", "NAS", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("electeurInterfaceClass", "Ajout d'un electeur", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("electeurInterfaceClass", "Adresse", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("electeurInterfaceClass", "Date de naissance", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("electeurInterfaceClass", "Nom", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("electeurInterfaceClass", "Prenom", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("electeurInterfaceClass", "Rue", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("electeurInterfaceClass", "Code Postal", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("electeurInterfaceClass", "Identification", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("electeurInterfaceClass", "No Civic", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("electeurInterfaceClass", "Ville", 0, QApplication::UnicodeUTF8));
        nas->setInputMask(QString());
        nas->setText(QString());
        confirmer->setText(QApplication::translate("electeurInterfaceClass", "Confirmer", 0, QApplication::UnicodeUTF8));
        label125->setText(QApplication::translate("electeurInterfaceClass", "Province", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("electeurInterfaceClass", "dd-MM-yyyy", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class electeurInterfaceClass: public Ui_electeurInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELECTEURINTERFACE_H
