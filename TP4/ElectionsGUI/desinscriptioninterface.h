#ifndef DESINSCRIPTIONINTERFACE_H
#define DESINSCRIPTIONINTERFACE_H

#include <QtGui/QDialog>
#include "ui_desinscriptioninterface.h"

class desinscriptionInterface : public QDialog
{
    Q_OBJECT

public:
    desinscriptionInterface(QWidget *parent = 0);
    ~desinscriptionInterface();

    QString reqNas() const;

private slots:
	void validerDesinscription();
private:
    Ui::desinscriptionInterfaceClass ui;
};

#endif // DESINSCRIPTIONINTERFACE_H
