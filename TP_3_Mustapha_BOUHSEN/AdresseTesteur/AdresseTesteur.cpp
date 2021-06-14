/**
 * \file AdresseTesteur.cpp
 * \brief Test unitaire de la classe Adresse
 * \author Mustapha Bouhsen
 */
#include<gtest/gtest.h>
#include<iostream>
#include<sstream>
#include"Adresse.h"
#include"ContratException.h"
using namespace std;
using namespace util;

/**
 * \brief Test du constructeur
 * 		  Cas valides: Création d'un objet Adresse et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *		             m_numeroCivic negatif
 *					 m_nomRue non vide
 *					 m_ville non vide
 *					 m_codePostal non vide
 *					 m_province non vide
 */
TEST(Adresse,Constructeur)
{
    Adresse adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC");
	ASSERT_EQ(314, adresse.reqNumeroCivic());
	ASSERT_TRUE("Miron" == adresse.reqNomRue());
	ASSERT_TRUE("Quebec" == adresse.reqVille());
	ASSERT_TRUE("G1V 7A2" == adresse.reqCodePostal());
	ASSERT_TRUE("QC" == adresse.reqProvince());
}

TEST(Adresse,ConstructeurNumeroCivicInvalide)
{
	ASSERT_THROW(Adresse adresse(-314 , "Miron", "Quebec", "G1V 7A2", "QC"),PreconditionException);
}
TEST(Adresse,ConstructeurNomRueInvalide)
{
	ASSERT_THROW(Adresse adresse(314 , "", "Quebec", "G1V 7A2", "QC"),PreconditionException);
}
TEST(Adresse,ConstructeurNomVilleInvalide)
{
	ASSERT_THROW(Adresse adresse(314 , "Miron", "", "G1V 7A2", "QC"),PreconditionException);
}
TEST(Adresse,ConstructeurCodePostaleInvalide)
{
	ASSERT_THROW(Adresse adresse(314 , "Miron", "Quebec", "", "QC"),PreconditionException);
}
TEST(Adresse,ConstructeurProvinceInvalide)
{
	ASSERT_THROW(Adresse adresse(314 , "Miron", "Quebec", "G1V 7A2", ""),PreconditionException);
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UneAdresse: public ::testing::Test
{
public:
	UneAdresse():
		uneAdresse(314 , "Miron", "Quebec", "G1V 7A2", "QC")
	{};

	Adresse uneAdresse;
};

/**
 * \brief Test de la méthode reqNumeroCivic()
 *     Cas valide: vérifier le retour du numero civic
 *     Cas invalide: negatif
 */
TEST_F(UneAdresse, reqNumeroCivic)
{
	ASSERT_EQ(314,uneAdresse.reqNumeroCivic());
}
/**
 * \brief Test de la méthode reqNomRue()
 *     Cas valide: vérifier le retour du nom de la rue
 *     Cas invalide: vide
 */
TEST_F(UneAdresse, reqNomRue)
{
	ASSERT_TRUE("Miron" ==  uneAdresse.reqNomRue());
}
/**
 * \brief Test de la méthode reqVille()
 *     Cas valide: vérifier le retour du nom de la ville
 *     Cas invalide: vide
 */
TEST_F(UneAdresse, reqVille)
{
	ASSERT_TRUE("Quebec" == uneAdresse.reqVille());
}
/**
 * \brief Test de la méthode reqCodePostal()
 *     Cas valide: vérifier le retour du code postale
 *     Cas invalide: vide
 */
TEST_F(UneAdresse, reqCodePostal)
{
	ASSERT_TRUE("G1V 7A2" == uneAdresse.reqCodePostal());
}
/**
 * \brief Test de la méthode reqProvince()
 *     Cas valide: vérifier le retour de la province
 *     Cas invalide: vide
 */
TEST_F(UneAdresse, reqProvince)
{
	ASSERT_TRUE("QC" == uneAdresse.reqProvince());
}
/**
 * \class DeuxAdresse
 * \brief Fixture pour les tests comparaisons de Deux Adresse
 */

/**
 * \brief  Test de la méthode bool Date::operator== (const Adresse & p_adresse)
 *        cas valide:
 *   		OperatorEgalEgalVrai: 	adresse indentique à elle-même.
 *        cas invalide Aucun d'identifié
 */
TEST_F(UneAdresse, OperatorEgalEgalVrai)
{
	ASSERT_TRUE(uneAdresse == uneAdresse);
}

class DeuxAdresse: public ::testing::Test
{
public:
	static const int valeur = 1;
	DeuxAdresse() :
			f_adresse1(314 , "Miron", "Quebec", "G1V 7A2", "QC"),
			f_adresse2(314 , "Miron", "Quebec", "G1V 7A2", "ON")
	{
	}
	;

	Adresse f_adresse1;
	Adresse f_adresse2;
};

TEST_F(DeuxAdresse, OperatorEgalEgalFaux)
{
	ASSERT_FALSE(f_adresse1 == f_adresse2);
}

/**
 * \brief Test de la méthode reqAdresseFormate()
 *     Cas valide: vérifier adresse connue dont on connaît le format
 *     Cas invalide: vide
 */
TEST_F(UneAdresse, AdresseFormatee)
{
	ASSERT_TRUE("314, Miron, Quebec, G1V 7A2, QC" == uneAdresse.reqAdresseFormate());
}


