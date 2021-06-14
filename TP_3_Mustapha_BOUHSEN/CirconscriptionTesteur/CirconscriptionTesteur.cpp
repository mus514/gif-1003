/**
 * \file CirconsriptionTesteur.cpp
 * \brief Test unitaire de la classe Circonscription
 * \author Mustapha Bouhsen
 */
#include<gtest/gtest.h>
#include<iostream>
#include<sstream>
#include"Adresse.h"
#include"Date.h"
#include"Personne.h"
#include"Candidat.h"
#include"Electeur.h"
#include"Circonscription.h"
#include"ContratException.h"
#include <vector>
using namespace std;
using namespace util;
using namespace elections;

/**
 * \brief Test du constructeur
 * 		  Cas valides: Création d'un objet Ciconsription et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *                       m_nomCirconscription non vide
 * 						 m_deputeElu valide
 *				         m_vInscrits vecteur
 *
 */
TEST(Circonscription, Constructeur)
{
    Circonscription circonsription("01", Candidat("046 454 286", "Mustapha", "BOUHSEN",
    		       Date(5,6,1991),Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"), 3));

	ASSERT_TRUE("01" == circonsription.reqNomCirconscription());
	ASSERT_TRUE("046 454 286" == circonsription.reqCandidat().reqNas());
	ASSERT_TRUE("Mustapha" == circonsription.reqCandidat().reqPrenom());
	ASSERT_TRUE("BOUHSEN" == circonsription.reqCandidat().reqNom());
	ASSERT_TRUE(Date(5,6,1991) == circonsription.reqCandidat().reqDateNaissance());
	ASSERT_TRUE(Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC") ==
			circonsription.reqCandidat().reqAdresse());
}

TEST(Circonsription, ConstructeurPartiInvalide)
{
	ASSERT_THROW(Circonscription circonsription( "", Candidat("046 454 286", "Mustapha", "BOUHSEN",
		       Date(5,6,1991),Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"), 3)),
			   PreconditionException);
}

TEST(Circonsription, ConstructeurCopie)
{
	Circonscription circonsription( "01", Candidat("046 454 286", "Mustapha", "BOUHSEN",
	    		       Date(5,6,1991),Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"), 3));

	Circonscription circonsription1(circonsription);

	ASSERT_TRUE("01" == circonsription1.reqNomCirconscription());
	ASSERT_TRUE("046 454 286" == circonsription1.reqCandidat().reqNas());
	ASSERT_TRUE("Mustapha" == circonsription1.reqCandidat().reqPrenom());
	ASSERT_TRUE("BOUHSEN" == circonsription1.reqCandidat().reqNom());
	ASSERT_TRUE(Date(5,6,1991) == circonsription1.reqCandidat().reqDateNaissance());
	ASSERT_TRUE(Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC") ==
			circonsription1.reqCandidat().reqAdresse());
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UneCirconscription: public ::testing::Test
{
public:
	UneCirconscription():
	     uneCirconscription("01", Candidat("046 454 286", "Mustapha", "BOUHSEN",
  		       Date(5,6,1991),Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"), 3))
	{};

	Circonscription uneCirconscription;
};


/**
 * \brief Test de la méthode reqNomCirconscription()
 *     Cas valide: vérifier le retour du nom circonscription
 *     Cas invalide: vide
 */
TEST_F(UneCirconscription, reqNomCirconscription)
{
	ASSERT_TRUE("01" == uneCirconscription.reqNomCirconscription());
}


/**
 * \brief Test de la méthode reqCandidat()
 *     Cas valide: vérifier le retour du candidat
 *     Cas invalide: vide
 */
TEST_F(UneCirconscription, reqCandidat)
{
	ASSERT_TRUE("046 454 286" == uneCirconscription.reqCandidat().reqNas());
	ASSERT_TRUE("Mustapha" == uneCirconscription.reqCandidat().reqPrenom());
	ASSERT_TRUE("BOUHSEN" == uneCirconscription.reqCandidat().reqNom());
	ASSERT_TRUE(Date(5,6,1991) == uneCirconscription.reqCandidat().reqDateNaissance());
	ASSERT_TRUE(Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC") ==
			uneCirconscription.reqCandidat().reqAdresse());

}

/**
 * \brief Test de la méthode reqPersonneFormate()
 *     vérifier  connue dont on connaît le format
 *     Cas invalide: vide
 */
TEST_F(UneCirconscription, CiconsriptionFormatee)
{

	ostringstream os;
	os << "Circonscription : 01"<< endl;
	os << "Depute sortant :"<< endl;
	os << "Candidat" << endl;
	os<<"-----------------------------------------------------------------"<<endl;
	os <<"NAS                 : 046 454 286"<< endl;
	os <<"Prenom              : Mustapha"<< endl;
	os <<"Nom                 : BOUHSEN"<< endl;
	os <<"Date de naissance   : Mercredi le 05 juin 1991"<<endl;
	os <<"Adresse             : 314, Miron, Quebec, G1V 7A2, QC"<<endl;
	os <<"Parti politique     : LIBERAL"<< endl;
	os<<endl;
	os << "Liste des inscrits :"<<endl;

	ASSERT_TRUE(os.str() == uneCirconscription.reqCirconscriptionFormate());
}

/**
 * \brief Test de la méthode inscrire()
 *     vérifier  connue dont on connaît le format
 *     Cas invalide: vide
 */

TEST_F(UneCirconscription, inscrire)
{
	Electeur electeur("046 454 286", "Mustapha", "BOUHSEN",
	    		Date(5,6,1991),Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"));

	uneCirconscription.inscrire(electeur);

	ostringstream os;
	os << "Circonscription : 01"<< endl;
	os << "Depute sortant :"<< endl;
	os << "Candidat" << endl;
	os<<"-----------------------------------------------------------------"<<endl;
	os <<"NAS                 : 046 454 286"<< endl;
	os <<"Prenom              : Mustapha"<< endl;
	os <<"Nom                 : BOUHSEN"<< endl;
	os <<"Date de naissance   : Mercredi le 05 juin 1991"<<endl;
	os <<"Adresse             : 314, Miron, Quebec, G1V 7A2, QC"<<endl;
	os <<"Parti politique     : LIBERAL"<< endl;
	os<<endl;
	os << "Liste des inscrits :"<<endl;
	os << "Electeur" << endl;
	os<<"-----------------------------------------------------------------"<<endl;
	os <<"NAS                 : 046 454 286"<< endl;
	os <<"Prenom              : Mustapha"<< endl;
	os <<"Nom                 : BOUHSEN"<< endl;
	os <<"Date de naissance   : Mercredi le 05 juin 1991"<<endl;
	os <<"Adresse             : 314, Miron, Quebec, G1V 7A2, QC"<<endl;
	os << endl;

	ASSERT_TRUE(os.str() == uneCirconscription.reqCirconscriptionFormate());
}

/**
 * \brief Test de la méthode reqInscrit()
 *     vérifier connue dont on connaît le format
 *     Cas invalide: vide
 */
TEST_F(UneCirconscription, reqInscrit)
{

	Electeur electeur("046 454 286", "Mustapha", "BOUHSEN",
		    		Date(5,6,1991),Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"));

	uneCirconscription.inscrire(electeur);

	Personne *ptr = uneCirconscription.reqInscrit()[0];

	ostringstream os;
	os << "Electeur" << endl;
	os<<"-----------------------------------------------------------------"<<endl;
	os <<"NAS                 : 046 454 286"<< endl;
	os <<"Prenom              : Mustapha"<< endl;
	os <<"Nom                 : BOUHSEN"<< endl;
	os <<"Date de naissance   : Mercredi le 05 juin 1991"<<endl;
	os <<"Adresse             : 314, Miron, Quebec, G1V 7A2, QC"<<endl;
	os << endl;

	ASSERT_TRUE(os.str() == ptr->reqPersonneFormate());
}


/**
 * \brief Test de la méthode reqInscrit()
 *     vérifier connue dont on connaît le format
 *     Cas invalide: vide
 */

TEST_F(UneCirconscription, OperateurEgal)
{
	Circonscription test("02", Candidat("046 454 286", "Momo", "BOUHSEN",
    		       Date(5,6,1991),Adresse(314 , "Miron", "Toronto", "G1V 7A2", "ON"), 3));

	test = uneCirconscription;

	ASSERT_TRUE(test.reqCirconscriptionFormate() == uneCirconscription.reqCirconscriptionFormate());
}
