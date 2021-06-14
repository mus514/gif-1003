#include "electionsgui.h"
#include "Candidat.h"
#include "Electeur.h"
#include "electeurinterface.h"
#include "candidatinterface.h"
#include "desinscriptioninterface.h"
#include "PersonneException.h"
#include <sstream>
#include <QMessageBox>

using namespace elections;
using namespace std;
using namespace util;


ElectionsGUI::ElectionsGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

ElectionsGUI::~ElectionsGUI()
{

}

void ElectionsGUI::AjouterCandidat(const std::string & p_nas, const std::string & p_prenom, const std::string & p_nom,
						const util::Date & p_dateNaissance, const util::Adresse & p_adresse, int p_parti)
{

	Candidat nouveauCandidat(p_nas,p_prenom, p_nom, p_dateNaissance,  p_adresse,  p_parti);

	if(!verifierPresence(p_nas))
		m_circonscription.inscrire(nouveauCandidat);

	else
	{
		QString message = ("Ce candidat existe deja");
		QMessageBox::information(this, "ERREUR", message);
	}


}

void ElectionsGUI::AjouterElecteur(const std::string & p_nas, const std::string & p_prenom, const std::string & p_nom,
									const util::Date & p_dateNaissance, const util::Adresse & p_adresse)
{
		    Electeur nouvelElecteur(p_nas,p_prenom, p_nom, p_dateNaissance,  p_adresse);
			if(!verifierPresence(p_nas))
				m_circonscription.inscrire(nouvelElecteur);

			else
			{
				QString message = ("Cet electeur existe deja");
				QMessageBox::information(this, "ERREUR", message);
			}

}

void ElectionsGUI::desinscrirePersonne(const std::string& p_nas)
{
	if(verifierPresence(p_nas))
			m_circonscription.desinscrire(p_nas);

	else
		{
			QString message = ("Cette personne n'existe pas");
			QMessageBox::information(this, "ERREUR", message);
		}

}

std::string ElectionsGUI::reqListeFormate() const
{
	return m_circonscription.reqCirconscriptionFormate();
}

void ElectionsGUI::dialogElecteur()
{
	electeurInterface saisieElecteur(this);
	if (saisieElecteur.exec())
	{
		Adresse adresse(saisieElecteur.reqNumeroCivic(), saisieElecteur.reqRue().toStdString(),
						saisieElecteur.reqVille().toStdString(), saisieElecteur.reqCodePostal().toStdString(),
						saisieElecteur.reqProvince().toStdString());
		AjouterElecteur(saisieElecteur.reqNas().toStdString(), saisieElecteur.reqNom().toStdString(),
						saisieElecteur.reqPrenom().toStdString(), saisieElecteur.reqDate(), adresse);
		ui.affichage->setText(this->reqListeFormate().c_str());
	}
}

void ElectionsGUI::dialogCandidat()
{
	candidatInterface saisieCandidat(this);
	if (saisieCandidat.exec())
	{
		Adresse adresse(saisieCandidat.reqNumeroCivic(), saisieCandidat.reqRue().toStdString(),
						saisieCandidat.reqVille().toStdString(), saisieCandidat.reqCodePostal().toStdString(),
						saisieCandidat.reqProvince().toStdString());
		AjouterCandidat(saisieCandidat.reqNas().toStdString(), saisieCandidat.reqNom().toStdString(),
						saisieCandidat.reqPrenom().toStdString(), saisieCandidat.reqDate(), adresse, saisieCandidat.reqParti());
		ui.affichage->setText(this->reqListeFormate().c_str());
	}
}

void ElectionsGUI::dialogDesinscrire()
{
	desinscriptionInterface saisieDesinscrire(this);

	if (saisieDesinscrire.exec())
	{
		desinscrirePersonne(saisieDesinscrire.reqNas().toStdString());
		ui.affichage->setText(this->reqListeFormate().c_str());
	}
}

bool ElectionsGUI::verifierPresence(const std::string& p_nas)
{
	bool reponse = false;

	vector<Personne*>::const_iterator iter;

	for(iter = m_circonscription.reqInscrit().begin(); iter < m_circonscription.reqInscrit().end(); iter++)
	{
		if((*iter)->reqNas() == p_nas)
		{
			reponse = true;
		}
	}

	return reponse;

}


