#ifndef CANDIDATINTERFACE_H
#define CANDIDATINTERFACE_H

#include <QtGui/QDialog>
#include "ui_candidatinterface.h"
#include"Date.h"

class candidatInterface : public QDialog
{
    Q_OBJECT

public:
    candidatInterface(QWidget *parent = 0);
    ~candidatInterface();

    QString reqNas() const;
    QString reqNom() const;
    QString reqPrenom() const;
    util::Date reqDate() const;
    int reqNumeroCivic() const;
    QString reqRue() const;
    QString reqVille() const;
    QString reqCodePostal() const;
    QString reqProvince() const;
    int reqParti() const;

    private slots:
    	void validerCandidat();

private:
    Ui::candidatInterfaceClass ui;
    util::Date m_date;
};

#endif // CANDIDATINTERFACE_H
