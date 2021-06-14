#ifndef ELECTIONSGUI_H
#define ELECTIONSGUI_H

#include <QtGui/QMainWindow>
#include "ui_electionsgui.h"
#include <vector>
#include "Circonscription.h"

using namespace elections;
using namespace std;
using namespace util;

class ElectionsGUI : public QMainWindow
{
    Q_OBJECT

public:
    ElectionsGUI(QWidget *parent = 0);
    ~ElectionsGUI();
    void AjouterCandidat(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
							const util::Date& p_dateNaissance, const util::Adresse & p_adresse, int p_parti);

    void AjouterElecteur(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
							const util::Date& p_dateNaissance, const util::Adresse& p_adresse);

    void desinscrirePersonne(const std::string& p_nas);

    std::string reqListeFormate() const;

    bool verifierPresence(const std::string& p_nas);


private slots:
	void dialogElecteur();
	void dialogCandidat();
	void dialogDesinscrire();

private:
    Ui::ElectionsGUIClass ui;
    Circonscription m_circonscription = Circonscription("01", Candidat("046 454 286", "Mustapha", "BOUHSEN",
		       Date(5,6,1991),Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"), 3));


};

#endif // ELECTIONSGUI_H
