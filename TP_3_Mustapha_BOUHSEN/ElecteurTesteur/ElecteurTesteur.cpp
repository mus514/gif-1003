/**
 * \file ElecteurTesteur.cpp
 * \brief Test unitaire de la classe Circonscription
 * \author Mustapha Bouhsen
 */
#include<gtest/gtest.h>
#include<iostream>
#include<sstream>
#include"Adresse.h"
#include"Date.h"
#include"Personne.h"
#include"Electeur.h"
#include"ContratException.h"
using namespace std;
using namespace util;
using namespace elections;

/**
 * \brief Test du constructeur
 * 		  Cas valides: Création d'un objet Electeur et vérification de l'assignation de tous les attributs
 *
 */
TEST(Electeur,Constructeur)
{
    Electeur electeur("046 454 286", "Mustapha", "BOUHSEN",
    		Date(5,6,1991),Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"));

	ASSERT_TRUE("046 454 286" == electeur.reqNas());
	ASSERT_TRUE("Mustapha" == electeur.reqPrenom());
	ASSERT_TRUE("BOUHSEN" == electeur.reqNom());
	ASSERT_TRUE(Date(5,6,1991) == electeur.reqDateNaissance());
	ASSERT_TRUE(Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC") == electeur.reqAdresse());
}

TEST(Electeur,ConstructeurPartiInvalide)
{
	ASSERT_THROW(Electeur electeur("046454286", "Mustapha", "BOUHSEN", Date(5,6,1991),
			Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC")), PreconditionException);
}

TEST(Electeur, ConstructeurCopie)
{
	Electeur electeur("046 454 286", "Mustapha", "BOUHSEN",
	    		Date(5,6,1991),Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"));

	Electeur electeur1(electeur);

	ASSERT_TRUE("046 454 286" == electeur1.reqNas());
	ASSERT_TRUE("Mustapha" == electeur1.reqPrenom());
	ASSERT_TRUE("BOUHSEN" == electeur1.reqNom());
	ASSERT_TRUE(Date(5,6,1991) == electeur1.reqDateNaissance());
	ASSERT_TRUE(Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC") == electeur1.reqAdresse());

}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnElecteur: public ::testing::Test
{
public:
	UnElecteur():
		unElecteur("046 454 286", "Mustapha", "BOUHSEN",
	    		Date(5,6,1991),Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"))
	{};

	Electeur unElecteur;
};

/**
 * \brief Test de la méthode reqPersonneFormate()
 *     vérifier  connue dont on connaît le format
 *     Cas invalide: vide
 */

TEST_F(UnElecteur,ElecteurFormatee)
{
	ostringstream os;
	os << "Electeur" << endl;
	os<<"-----------------------------------------------------------------"<<endl;
	os <<"NAS                 : 046 454 286"<< endl;
	os <<"Prenom              : Mustapha"<< endl;
	os <<"Nom                 : BOUHSEN"<< endl;
	os <<"Date de naissance   : Mercredi le 05 juin 1991"<<endl;
	os <<"Adresse             : 314, Miron, Quebec, G1V 7A2, QC"<<endl;
	os << endl;

	ASSERT_TRUE(os.str() == unElecteur.reqPersonneFormate());
}

/**
 * \brief Test de la méthode clone()
 *     vérifier  connue dont on connaît le format
 *     Cas invalide: vide
 */
TEST_F(UnElecteur, clone)
{
	Personne *ptr = unElecteur.clone();

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
