/********************************************************************************
** Form generated from reading UI file 'desinscriptioninterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESINSCRIPTIONINTERFACE_H
#define UI_DESINSCRIPTIONINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_desinscriptionInterfaceClass
{
public:
    QLabel *label_10;
    QLabel *label_2;
    QLineEdit *nas;
    QPushButton *desinscrire;
    QLabel *label;

    void setupUi(QDialog *desinscriptionInterfaceClass)
    {
        if (desinscriptionInterfaceClass->objectName().isEmpty())
            desinscriptionInterfaceClass->setObjectName(QString::fromUtf8("desinscriptionInterfaceClass"));
        desinscriptionInterfaceClass->resize(400, 153);
        label_10 = new QLabel(desinscriptionInterfaceClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(50, 20, 121, 17));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_10->setFont(font);
        label_2 = new QLabel(desinscriptionInterfaceClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 80, 53, 17));
        nas = new QLineEdit(desinscriptionInterfaceClass);
        nas->setObjectName(QString::fromUtf8("nas"));
        nas->setGeometry(QRect(170, 70, 111, 27));
        nas->setInputMethodHints(Qt::ImhNone);
        nas->setMaxLength(11);
        desinscrire = new QPushButton(desinscriptionInterfaceClass);
        desinscrire->setObjectName(QString::fromUtf8("desinscrire"));
        desinscrire->setGeometry(QRect(130, 110, 131, 28));
        label = new QLabel(desinscriptionInterfaceClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 40, 251, 17));

        retranslateUi(desinscriptionInterfaceClass);
        QObject::connect(desinscrire, SIGNAL(clicked()), desinscriptionInterfaceClass, SLOT(validerDesinscription()));

        QMetaObject::connectSlotsByName(desinscriptionInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *desinscriptionInterfaceClass)
    {
        desinscriptionInterfaceClass->setWindowTitle(QApplication::translate("desinscriptionInterfaceClass", "desinscriptionInterface", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("desinscriptionInterfaceClass", "Desinscription", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("desinscriptionInterfaceClass", "NAS", 0, QApplication::UnicodeUTF8));
        nas->setInputMask(QString());
        nas->setText(QString());
        desinscrire->setText(QApplication::translate("desinscriptionInterfaceClass", "Desinscrire", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("desinscriptionInterfaceClass", "Entrez le NAS de la personne a desinscrire.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class desinscriptionInterfaceClass: public Ui_desinscriptionInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESINSCRIPTIONINTERFACE_H
