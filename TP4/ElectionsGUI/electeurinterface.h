#ifndef ELECTEURINTERFACE_H
#define ELECTEURINTERFACE_H

#include <QtGui/QDialog>
#include "ui_electeurinterface.h"
#include"Date.h"

class electeurInterface : public QDialog
{
    Q_OBJECT

public:
    electeurInterface(QWidget *parent = 0);
    ~electeurInterface();

    QString reqNas() const;
    QString reqNom() const;
    QString reqPrenom() const;
    util::Date reqDate() const;
    int reqNumeroCivic() const;
    QString reqRue() const;
    QString reqVille() const;
    QString reqCodePostal() const;
    QString reqProvince() const;

private slots:
	void validerElecteur();

private:
    Ui::electeurInterfaceClass ui;
    util::Date m_date;
};

#endif // ELECTEURINTERFACE_H
