/*
 * \file Adresse.cpp
 * \brief Implantation de la classe Adresse
 * \author Mustapha BOUHSEN
 */

#include "Adresse.h"
#include<iostream>
#include<sstream>

using namespace std;

namespace util
{
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Adresse à partir de valeurs passées en paramètres.
 * \param[in] p_numeroCivic est un entier qui représente le numero du domicile
 * \param[in] p_nomRue est une chaine de caratere qui représente le nom de la rue
 * \param[in] p_ville est une chaine de caratere qui représente le nom de la ville
 * \param[in] p_codePostal est une chaine de caratere qui représente le code postal
 * \param[in] p_province est une chaine de caratere qui représente la procince
 */
Adresse::Adresse(int p_numeroCivic, const std::string & p_nomRue, const std::string & p_ville,
			const std::string & p_codePostal, const std::string & p_province)

: m_numeroCivic(p_numeroCivic),m_nomRue(p_nomRue), m_ville(p_ville), m_codePostal(p_codePostal), m_province(p_province){}

/**
 * \brief Assigne une adresse à l'objet courant
 * \param[in] p_numeroCivic est un entier qui représente le numero du domicile
 * \param[in] p_nomRue est une chaine de caratere qui représente le nom de la rue
 * \param[in] p_ville est une chaine de caratere qui représente le nom de la ville
 * \param[in] p_codePostal est une chaine de caratere qui représente le code postal
 * \param[in] p_province est une chaine de caratere qui représente la procince
 */
void Adresse::asgAdresse(int p_numeroCivic, const std::string & p_nomRue, const std::string & p_ville,
			const std::string & p_codePostal, const std::string & p_province)
{
	m_numeroCivic = p_numeroCivic;
	m_nomRue = p_nomRue;
	m_ville = p_ville;
	m_codePostal = p_codePostal;
	m_province = p_province;

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


}

