/*
 * \file Personne.cpp
 * \brief Implantation de la classe Adresse
 * \author Mustapha BOUHSEN
 */

#include "Personne.h"
#include "Adresse.h"
#include"validationFormat.h"
#include "Date.h"
#include "iostream"
#include<sstream>

using namespace std;
namespace elections
{
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Personne à partir de valeurs passées en paramètres.
 * \param[in] p_nas est une chaine de caratere qui représente le NAS
 * \param[in] p_prenom est une chaine de caratere qui représente le prenom de la personne
 * \param[in] p_nom est une chaine de caratere qui représente le nom de la personne
 * \param[in] p_dateNaissance est un objet Date qui représente la date de naissance de la personne
 * \param[in] p_adresse est un objet Adresse qui représente l'adresse de la personne
 * \pre p_nas non vide
 * \pre p_prenom non vide
 * \pre p_nom non vide
 * \post m_nas prend la valeur de p_nas
 * \post m_prenom prend la valeur de p_prenom
 * \post m_nom prend la valeur de p_nom
 * \post m_dateNaissance prend la valeur de p_dateNaissance
 * \post m_adresse prend la valeur de p_adresse
 */

Personne::Personne(const std::string & p_nas, const std::string & p_prenom, const std::string & p_nom,
		const util::Date & p_dateNaissance, const util::Adresse & p_adresse)

:m_nas(p_nas), m_prenom(p_prenom), m_nom(p_nom), m_dateNaissance(p_dateNaissance), m_adresse(p_adresse)
{
	PRECONDITION(util::validerNas(p_nas));
	PRECONDITION(!p_prenom.empty());
	PRECONDITION(!p_nom.empty());

	POSTCONDITION(m_nas == p_nas);
	POSTCONDITION(m_prenom == p_prenom);
	POSTCONDITION(m_nom == p_nom);
	POSTCONDITION(m_dateNaissance == p_dateNaissance);
	POSTCONDITION(m_adresse == p_adresse);

	INVARIANTS();
}

/**
 * \brief retourne le NAS de la personne
 * \return une chaine de caractere qui représente le NAS
 */
const std::string & Personne::reqNas() const {return m_nas;}

/**
 * \brief retourne le prenom de la personne
 * \return une chaine de caratere qui représente le prenom de la personne
 */
const std::string & Personne::reqPrenom() const{return m_prenom;}

/**
 * \brief retourne le nom de la personne
 * \return une chaine de caratere qui représente le nom de la personne
 */
const std::string & Personne::reqNom() const {return m_nom;}

/**
 * \brief retourne la date de naissance de personne
 * \return un objet Date qui représente le naissance de personne
 */
const util::Date & Personne::reqDateNaissance() const{return m_dateNaissance;}

/**
 * \brief retourne l'adresse de personne
 * \return un objet Adresse qui représente l'adresse de personne
 */
const util::Adresse & Personne::reqAdresse() const {return m_adresse;}

/**
 * \brief surcharge de l'opérateur ==
 * \param[in] p_personne qui est une Personne valide
 * \return un booléen indiquant si les deux personnes sont identiques
 */
bool Personne::operator ==(const Personne & p_personne)
{
	INVARIANTS();
	return ((m_nas == p_personne.reqNas()) && (m_prenom == p_personne.reqPrenom()) &&
			(m_nom == p_personne.reqNom()) && (m_dateNaissance == p_personne.reqDateNaissance())
			&& (m_adresse == p_personne.reqAdresse()));
}

/**
 * \brief retourne un peronne formatée dans une chaîne de caracères
 * \return une personne formatée dans une chaîne de caractères
 */
std::string Personne::reqPersonneFormate() const
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

/**
 * \brief Assigne une nouvelle adresse à l'objet personne courant
 * \param[in] p_numeroCivic est un entier qui représente le numero du domicile
 * \param[in] p_nomRue est une chaine de caratere qui représente le nom de la rue
 * \param[in] p_ville est une chaine de caratere qui représente le nom de la ville
 * \param[in] p_codePostal est une chaine de caratere qui représente le code postal
 * \param[in] p_province est une chaine de caratere qui représente la procince
 * \post m_adresse conrrespond a la nouvelle adresse entree
 */
void Personne::asgNouvelleAdresse(int p_numeroCivic, const std::string & p_nomRue, const std::string & p_ville,
			const std::string & p_codePostal, const std::string & p_province)
{
	m_adresse.asgAdresse(p_numeroCivic, p_nomRue, p_ville, p_codePostal, p_province );

	POSTCONDITION((m_adresse.reqNumeroCivic() == p_numeroCivic) && (m_adresse.reqNomRue() == p_nomRue) &&
			(m_adresse.reqVille() == p_ville) && (m_adresse.reqCodePostal() == p_codePostal) &&
			(m_adresse.reqProvince() == p_province));
	INVARIANTS();
}

/**
 * \brief Vérifier les invariants de classe
 */
void Personne::verifieInvariant() const
{
	INVARIANT(util::validerNas(m_nas));
	INVARIANT(!m_prenom.empty());
	INVARIANT(!m_nom.empty());
}

} /* namespace elections */
