/*
 * \file Electeur.cpp
 * \brief Implantation de la classe Electeur
 * \author Mustapha BOUHSEN
 */

#include"Electeur.h"
#include"Personne.h"
#include"Adresse.h"
#include<sstream>
#include<iostream>
using namespace std;


namespace elections
{
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Electeur à partir de valeurs passées en paramètres.
 * \param[in] p_nas est une chaine de caratere qui représente le NAS
 * \param[in] p_prenom est une chaine de caratere qui représente le prenom de la personne
 * \param[in] p_nom est une chaine de caratere qui représente le nom de la personne
 * \param[in] p_dateNaissance est un objet Date qui représente la date de naissance de la personne
 * \param[in] p_adresse est un objet Adresse qui représente l'adresse de la personne
 */
Electeur::Electeur(const std::string & p_nas, const std::string & p_prenom, const std::string & p_nom,
		const util::Date & p_dateNaissance, const util::Adresse & p_adresse)
        :Personne(p_nas, p_prenom, p_nom, p_dateNaissance,p_adresse)
{}

/**
 * \brief constructeur avec paramètres
 * 		  On construit une copie d'un objet ELcteur
 * \param[in] p_electeur est un objet Candidat
 */
Electeur::Electeur(const Electeur & p_electeur)
:Personne(p_electeur.reqNas(), p_electeur.reqPrenom(), p_electeur.reqNom(), p_electeur.reqDateNaissance(),
		p_electeur.reqAdresse())
{}

/**
 * \brief retourne un pointeur de l'objet Electeur
 * \return un pointeur qui représente l'Electeur
 */
Personne* Electeur::clone() const
{
	return new Electeur(*this);
}

/**
 * \brief retourne un Electeur formatée dans une chaîne de caracères
 * \return un Electeur formatée dans une chaîne de caractères
 */
std::string Electeur::reqPersonneFormate() const
{
	std::ostringstream os;
	os << "Electeur" << endl;
	os << elections::Personne::reqPersonneFormate()<<endl;
	return os.str();
}
}

