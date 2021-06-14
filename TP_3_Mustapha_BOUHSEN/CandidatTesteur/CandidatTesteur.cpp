/**
 * \file CandidatTesteur.cpp
 * \brief Test unitaire de la classe Candidat
 * \author Mustapha Bouhsen
 */
#include<gtest/gtest.h>
#include<iostream>
#include<sstream>
#include"Adresse.h"
#include"Date.h"
#include"Personne.h"
#include"Candidat.h"
#include"ContratException.h"
using namespace std;
using namespace util;
using namespace elections;

/**
 * \brief Test du constructeur
 * 		  Cas valides: Création d'un objet Candidat et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *		  			m_partiPolitique entier entre 0 et 4
 *
 */
TEST(Candidat,Constructeur)
{
    Candidat candidat("046 454 286", "Mustapha", "BOUHSEN",
    		Date(5,6,1991),Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"), 3);

	ASSERT_TRUE("046 454 286" == candidat.reqNas());
	ASSERT_TRUE("Mustapha" == candidat.reqPrenom());
	ASSERT_TRUE("BOUHSEN" == candidat.reqNom());
	ASSERT_TRUE(Date(5,6,1991) == candidat.reqDateNaissance());
	ASSERT_TRUE(Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC") == candidat.reqAdresse());
}

TEST(Candidat,ConstructeurPartiInvalide)
{
	ASSERT_THROW(Candidat candidat("046454286", "Mustapha", "BOUHSEN", Date(5,6,1991),
			Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"), 9), PreconditionException);
}


TEST(Candidat, ConstructeurCopie)
{
	Candidat candidat("046 454 286", "Mustapha", "BOUHSEN",
	    		Date(5,6,1991),Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"), 3);

	Candidat candidat1(candidat);

	ASSERT_TRUE(3 == candidat1.reqParti());
	ASSERT_TRUE("046 454 286" == candidat1.reqNas());
	ASSERT_TRUE("Mustapha" ==candidat1.reqPrenom());
	ASSERT_TRUE("BOUHSEN" == candidat1.reqNom());
	ASSERT_TRUE(Date(5,6,1991) == candidat1.reqDateNaissance());
	ASSERT_TRUE(Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC") == candidat1.reqAdresse());

}
/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnCandidat: public ::testing::Test
{
public:
	UnCandidat():
		unCandidat("046 454 286", "Mustapha", "BOUHSEN",
	    		Date(5,6,1991),Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"), 3)

	{};

	Candidat unCandidat;

};

/**
 * \brief Test de la méthode reqParti()
 *     Cas valide: vérifier le retour du parti
 *     Cas invalide: vide
 */
TEST_F(UnCandidat, reqNas)
{
	ASSERT_TRUE(3 == unCandidat.reqParti());
}

/**
 * \brief Test de la méthode reqPersonneFormate()
 *     vérifier  connue dont on connaît le format
 *     Cas invalide: vide
 */

TEST_F(UnCandidat, CandidatFormatee)
{
	ostringstream os;
	os << "Candidat" << endl;
	os<<"-----------------------------------------------------------------"<<endl;
	os <<"NAS                 : 046 454 286"<< endl;
	os <<"Prenom              : Mustapha"<< endl;
	os <<"Nom                 : BOUHSEN"<< endl;
	os <<"Date de naissance   : Mercredi le 05 juin 1991"<<endl;
	os <<"Adresse             : 314, Miron, Quebec, G1V 7A2, QC"<<endl;
	os <<"Parti politique     : LIBERAL"<< endl;

	ASSERT_TRUE(os.str() == unCandidat.reqPersonneFormate());
}

/**
 * \brief Test de la méthode clone()
 *     vérifier  connue dont on connaît le format
 *     Cas invalide: vide
 */
TEST_F(UnCandidat, clone)
{

	Personne *ptr = unCandidat.clone();

	ostringstream os;
	os << "Candidat" << endl;
	os<<"-----------------------------------------------------------------"<<endl;
	os <<"NAS                 : 046 454 286"<< endl;
	os <<"Prenom              : Mustapha"<< endl;
	os <<"Nom                 : BOUHSEN"<< endl;
	os <<"Date de naissance   : Mercredi le 05 juin 1991"<<endl;
	os <<"Adresse             : 314, Miron, Quebec, G1V 7A2, QC"<<endl;
	os <<"Parti politique     : LIBERAL"<< endl;

	ASSERT_TRUE(os.str() == ptr->reqPersonneFormate());

}

