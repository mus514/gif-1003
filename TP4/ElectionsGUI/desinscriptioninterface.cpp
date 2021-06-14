#include "desinscriptioninterface.h"
#include <QMessageBox>
#include "validationFormat.h"
#include "electionsgui.h"
#include"Circonscription.h"

using namespace util;
using namespace std;


desinscriptionInterface::desinscriptionInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

desinscriptionInterface::~desinscriptionInterface()
{}


QString desinscriptionInterface::reqNas() const
{
	return ui.nas->text();
}

void desinscriptionInterface::validerDesinscription(){
	if (!validerNas(ui.nas->text().toStdString()))
	{
		QString message ("Le nas ne doit pas etre vide ou non-inscrit");
		QMessageBox::information(this, "Erreur", message);

		return;
	}
	else
	{
		accept();
	}
}
