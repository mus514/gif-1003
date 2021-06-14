#include "candidatinterface.h"
#include <sstream>
#include <QMessageBox>
#include "validationFormat.h"

using namespace util;
using namespace std;

candidatInterface::candidatInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

candidatInterface::~candidatInterface()
{

}


QString candidatInterface::reqNas() const{
	return ui.nas->text();
}
QString candidatInterface::reqNom() const{
	return ui.nom->text();
}

QString candidatInterface::reqPrenom() const{
	return ui.prenom->text();
}

util::Date candidatInterface::reqDate() const
{
	return m_date;
}

int candidatInterface::reqNumeroCivic() const{
	return ui.nocivic->value();
}
QString candidatInterface::reqRue() const{
	return ui.rue->text();
}
QString candidatInterface::reqVille() const{
	return ui.ville->text();
}
QString candidatInterface::reqCodePostal() const{
	return ui.codepostal->text();
}
QString candidatInterface::reqProvince() const{
	return ui.province->text();
}
int candidatInterface::reqParti() const{
	return ui.parti->value()-1;
}

void candidatInterface::validerCandidat(){
if (ui.nom->text().isEmpty()){
	QString message ("Le nom ne doit pas etre vide");
	QMessageBox::information(this, "Erreur", message);
	return;
}
if (ui.prenom->text().isEmpty()){
	QString message ("Le prenom ne doit pas etre vide");
	QMessageBox::information(this, "Erreur", message);
	return;
}
if (!validerNas(ui.nas->text().toStdString())
		// && !personneDejaPresent(ui.nas->text().toStdString())//Besoin de verifier le nas
		){
	QString message ("Le nas ne doit pas etre vide ou invalide");
	QMessageBox::information(this, "Erreur", message);
	return;
}

if (ui.rue->text().isEmpty()){
	QString message ("Le champ rue ne doit pas etre vide");
	QMessageBox::information(this, "Erreur", message);
	return;
}
if (ui.ville->text().isEmpty()){
	QString message ("La ville ne doit pas etre vide");
	QMessageBox::information(this, "Erreur", message);
	return;
}
if (ui.codepostal->text().isEmpty()){
	QString message ("Le code postal ne doit pas etre vide");
	QMessageBox::information(this, "Erreur", message);
	return;
}
if (ui.province->text().isEmpty()){
	QString message ("La province ne doit pas etre vide");
	QMessageBox::information(this, "Erreur", message);
	return;
}


else
{
	m_date.asgDate(ui.dateEdit->date().day(), ui.dateEdit->date().month(),
				ui.dateEdit->date().year());

	accept();
}
}
