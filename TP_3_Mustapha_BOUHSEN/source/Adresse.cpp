/*
 * \file Adresse.cpp
 * \brief Implantation de la classe Adresse
 * \author Mustapha BOUHSEN
 */

#include "Adresse.h"
#include<iostream>
#include<sstream>
#include"ContratException.h"

using namespace std;

namespace util
{
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Personne à partir de valeurs passées en paramètres.
 * \param[in] p_numeroCivic est un entier qui représente le numero du domicile
 * \param[in] p_nomRue est une chaine de caratere qui représente le nom de la rue
 * \param[in] p_ville est une chaine de caratere qui représente le nom de la ville
 * \param[in] p_codePostal est une chaine de caratere qui représente le code postal
 * \param[in] p_province est une chaine de caratere qui représente la procince
 * \pre p_numeroCivic positif
 * \pre p_nomRue non vide
 * \pre p_ville non vide
 * \pre p_codePostal non vide
 * \pre p_province non vide
 * \post m_numeroCivic prend la valeur de p_numeroCivic
 * \post m_nomRue prend la valeur de p_nomRue
 * \post m_ville prend la valeur de p_ville
 * \post m_codePostal prend la valeur de p_codePostal
 * \post m_province prend la valeur de p_province
 */
Adresse::Adresse(int p_numeroCivic, const std::string & p_nomRue, const std::string & p_ville,
			const std::string & p_codePostal, const std::string & p_province)

: m_numeroCivic(p_numeroCivic),m_nomRue(p_nomRue), m_ville(p_ville), m_codePostal(p_codePostal), m_province(p_province)
{
	PRECONDITION(p_numeroCivic >= 0);
	PRECONDITION(!p_nomRue.empty());
	PRECONDITION(!p_ville.empty());
	PRECONDITION(!p_codePostal.empty());
	PRECONDITION(!p_province.empty());

	POSTCONDITION(m_numeroCivic == p_numeroCivic);
	POSTCONDITION(m_nomRue == p_nomRue);
	POSTCONDITION(m_ville == p_ville);
	POSTCONDITION(m_codePostal == p_codePostal);
	POSTCONDITION(m_province == p_province);

	INVARIANTS();
}

/**
 * \brief Assigne une adresse à l'objet courant
 * \param[in] p_numeroCivic est un entier qui représente le numero du domicile
 * \param[in] p_nomRue est une chaine de caratere qui représente le nom de la rue
 * \param[in] p_ville est une chaine de caratere qui représente le nom de la ville
 * \param[in] p_codePostal est une chaine de caratere qui représente le code postal
 * \param[in] p_province est une chaine de caratere qui représente la procince
 * \pre p_numeroCivic positif
 * \pre p_nomRue non vide
 * \pre p_ville non vide
 * \pre p_codePostal non vide
 * \pre p_province non vide
 * \post m_numeroCivic prend la valeur de p_numeroCivic
 * \post m_nomRue prend la valeur de p_nomRue
 * \post m_ville prend la valeur de p_ville
 * \post m_codePostal prend la valeur de p_codePostal
 * \post m_province prend la valeur de p_province
 */
void Adresse::asgAdresse(int p_numeroCivic, const std::string & p_nomRue, const std::string & p_ville,
			const std::string & p_codePostal, const std::string & p_province)
{
	PRECONDITION(p_numeroCivic > 0);
	PRECONDITION(!p_nomRue.empty());
	PRECONDITION(!p_ville.empty());
	PRECONDITION(!p_codePostal.empty());
	PRECONDITION(!p_province.empty());

	m_numeroCivic = p_numeroCivic;
	m_nomRue = p_nomRue;
	m_ville = p_ville;
	m_codePostal = p_codePostal;
	m_province = p_province;

	POSTCONDITION(m_numeroCivic == p_numeroCivic);
	POSTCONDITION(m_nomRue == p_nomRue);
	POSTCONDITION(m_ville == p_ville);
	POSTCONDITION(m_codePostal == p_codePostal);
	POSTCONDITION(m_province == p_province);

	INVARIANTS();

}

/**
 * \brief retourne le numero du domicile
 * \return un entier qui représente le numero du domicile
 */
int Adresse::reqNumeroCivic() const {return m_numeroCivic;}

/**
 * \brief retourne le nom de la rue
 * \return une chaine de caratere qui représente le nom de la rue
 */
const std::string & Adresse::reqNomRue() const {return m_nomRue;}

/**
 * \brief retourne le nom de la ville
 * \return une chaine de caratere qui représente le nom de la ville
 */
const std::string & Adresse::reqVille() const {return m_ville;}

/**
 * \brief retourne le code postal
 * \return une chaine de caratere qui représente le code postal
 */
const std::string & Adresse::reqCodePostal() const {return m_codePostal;}

/**
 * \brief retourne le jour de la province
 * \return une chaine de caratere qui représente la province
 */
const std::string & Adresse::reqProvince() const {return m_province;}

/**
 * \brief surcharge de l'opérateur ==
 * \param[in] p_adresse qui est une Adresse valide
 * \return un booléen indiquant si les deux adresse sont identiques
 */
bool Adresse::operator ==(const Adresse & p_adresse)
{
	INVARIANTS();
	return (m_numeroCivic == p_adresse.reqNumeroCivic()) && (m_nomRue == p_adresse.reqNomRue()) &&
			(m_ville == p_adresse.reqVille()) && (m_codePostal == p_adresse.reqCodePostal()) &&
			(m_province == p_adresse.reqProvince());
}

/**
 * \brief retourne une adresse formatée dans une chaîne de caracères
 * \return une adresse formatée dans une chaîne de caractères
 */
const std::string Adresse::reqAdresseFormate() const
{
	std::ostringstream os;
	os << reqNumeroCivic() << ", " << reqNomRue() << ", " << reqVille() << ", " << reqCodePostal()
			<< ", " << reqProvince();

	return os.str();

}
/**
 * \brief Vérifier les invariants de classe
 */
void Adresse::verifieInvariant() const
{
	INVARIANT(m_numeroCivic >= 0);
	INVARIANT(!m_nomRue.empty());
	INVARIANT(!m_ville.empty());
	INVARIANT(!m_codePostal.empty());
	INVARIANT(!m_province.empty());

}
/* namespace util */
}

