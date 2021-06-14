/**
 * \file PersonneTesteur.cpp
 * \brief Test unitaire de la classe Personne
 * \author Mustapha Bouhsen
 */
#include<gtest/gtest.h>
#include<iostream>
#include<sstream>
#include"Adresse.h"
#include"Date.h"
#include"Personne.h"
#include"ContratException.h"
using namespace std;
using namespace util;
using namespace elections;

class PersonneTest : public Personne
{
public:

	PersonneTest(const std::string & p_nas, const std::string & p_prenom, const std::string & p_nom,
			const util::Date & p_dateNaissance, const util::Adresse & p_adresse):
		Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse)
	{}

   virtual ~PersonneTest(){};

   virtual std::string reqPersonneFormate() const
   {
	   	ostringstream os;

	   	os<<"-----------------------------------------------------------------"<<endl;
	   	os <<"NAS                 : "<< reqNas()<<endl;
	   	os <<"Prenom              : "<< reqPrenom()<<endl;
	   	os <<"Nom                 : "<< reqNom()<<endl;
	   	os <<"Date de naissance   : "<< reqDateNaissance().reqDateFormatee()<<endl;
	   	os <<"Adresse             : "<< reqAdresse().reqAdresseFormate()<<endl;

	   	return os.str();
   }

   virtual PersonneTest* clone() const
   {
	   return new PersonneTest(*this);
   }
};

/**
 * \brief Test du constructeur
 * 		  Cas valides: Création d'un objet Personne et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *		  			m_nas valide
 *		  			m_prenom non vide
 *		  			m_nom non vide
 *
 */
TEST(Personne,Constructeur)
{
    PersonneTest personne("046 454 286", "Mustapha", "BOUHSEN",
    		Date(5,6,1991),Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"));

	ASSERT_TRUE("046 454 286" == personne.reqNas());
	ASSERT_TRUE("Mustapha" == personne.reqPrenom());
	ASSERT_TRUE("BOUHSEN" == personne.reqNom());
	ASSERT_TRUE(Date(5,6,1991) == personne.reqDateNaissance());
	ASSERT_TRUE(Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC") == personne.reqAdresse());
}

TEST(Personne,ConstructeurNasInvalide)
{
	ASSERT_THROW(PersonneTest personne("046454286", "Mustapha", "BOUHSEN", Date(5,6,1991),
			Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC")), PreconditionException);
}

TEST(Personne,ConstructeurPrenomInvalide)
{
	ASSERT_THROW(PersonneTest personne("046-454-286", "", "BOUHSEN", Date(5,6,1991),
				Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC")), PreconditionException);
}

TEST(Personne,ConstructeurNomInvalide)
{
	ASSERT_THROW(PersonneTest personne("046-454-286", "Mustapha", "", Date(5,6,1991),
					Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC")), PreconditionException);
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnePersonne: public ::testing::Test
{
public:
	UnePersonne():
		unePersonne("046 454 286", "Mustapha", "BOUHSEN",
	    		Date(5,6,1991),Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"))
	{};

	PersonneTest unePersonne;
};

/**
 * \brief Test de la méthode reqNas()
 *     Cas valide: vérifier le retour du nas
 *     Cas invalide: vide
 */
TEST_F(UnePersonne, reqNas)
{
	ASSERT_TRUE("046 454 286" == unePersonne.reqNas());
}
/**
 * \brief Test de la méthode reqPrenom()
 *     Cas valide: vérifier le retour du prenom
 *     Cas invalide: vide
 */

TEST_F(UnePersonne, reqreqPrenom)
{
	ASSERT_TRUE("Mustapha" == unePersonne.reqPrenom());
}
/**
 * \brief Test de la méthode reqNom()
 *     Cas valide: vérifier le retour du nom
 *     Cas invalide: vide
 */

TEST_F(UnePersonne,reqNom)
{
	ASSERT_TRUE("BOUHSEN" == unePersonne.reqNom());
}

/**
 * \brief Test de la méthode reqAdresse()
 *     Cas valide: vérifier le retour de l'adresse
 *     Cas invalide: vide
 */
TEST_F(UnePersonne, reqAdresse)
{
	ASSERT_TRUE(Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC") == unePersonne.reqAdresse());
}

/**
 * \brief Test de la méthode reqDateNaissance()
 *     Cas valide: vérifier le retour de la date de naissance
 *     Cas invalide: vide
 */

TEST_F(UnePersonne, reqDateNaissance)
{
	ASSERT_TRUE(Date(5,6,1991) == unePersonne.reqDateNaissance());
}

/**
 * \brief  Test de la méthode bool Personne::operator ==(const Personne & p_personne)
 *        cas valide:
 *   		OperatorEgalEgalVrai: 	Personne indentique à elle-même.
 *        cas invalide Aucun d'identifié
 */
TEST_F(UnePersonne, OperatorEgalEgalVrai)
{
	ASSERT_TRUE(unePersonne == unePersonne);
}

/**
 * \class DeuxAdresse
 * \brief Fixture pour les tests comparaisons de Deux Adresse
*/

class DeuxPersonne: public ::testing::Test
{
public:
	static const int valeur = 1;
	DeuxPersonne() :
			f_personne1("046 454 286", "Mustapha", "BOUHSEN", Date(5,6,1991),
					Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC")),

			f_personne2("046 454 286", "Mustapha", "MOUHAFIDI", Date(5,6,1991),
					Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"))
	{
	}
	;

	PersonneTest f_personne1;
	PersonneTest f_personne2;
};

/**
 * \brief  Test de la méthode bool Personne::operator ==(const Personne & p_personne)
 *        cas valide:
 *  		OperatorEgalEgalFaux: 	Personne différentes
 *        cas invalide Aucun d'identifié
 */
TEST_F(DeuxPersonne, OperatorEgalEgalFaux)
{
	ASSERT_FALSE(f_personne1 == f_personne2);
}


/**
 * \brief Test de la méthode reqPersonneFormate()
 *    vérifier adresse connue dont on connaît le format
 *     Cas invalide: vide
 */

TEST_F(UnePersonne, PersonneFormatee)
{
	ostringstream os;

	os<<"-----------------------------------------------------------------"<<endl;
	os <<"NAS                 : 046 454 286"<< endl;
	os <<"Prenom              : Mustapha"<< endl;
	os <<"Nom                 : BOUHSEN"<< endl;
	os <<"Date de naissance   : Mercredi le 05 juin 1991"<<endl;
	os <<"Adresse             : 314, Miron, Quebec, G1V 7A2, QC"<<endl;

	ASSERT_TRUE(os.str() == unePersonne.reqPersonneFormate());
}

/**
 * \brief Test de la méthode asgNouvelleAdresse()
 *     Cas valide: vérifier adresse connue dont on connaît le format
 *     Cas invalide: vide
 */
TEST_F(UnePersonne, asgNouvelleAdresse)
{
	unePersonne.asgNouvelleAdresse(314, "Miron", "Quebec", "G1V 7A2", "ON");
	ASSERT_TRUE(Adresse(314, "Miron", "Quebec", "G1V 7A2", "ON") == unePersonne.reqAdresse());

}
