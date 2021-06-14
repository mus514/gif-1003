/*
 * \file Personne.h
 * \brief Fichier qui contient l'interface de la classe Personne qui sert au maintien et à la manipulation des personnes
 * \author Mustapha BOUHSEN
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_
#include<iostream>
#include "Adresse.h"
#include "Date.h"

namespace elections
{
/**
 * \class Personne
 * \brief Cette classe sert au maintien et à la manipulation des personnes.
 *
 *          Attributs:
 *                       m_nas;
 *						 m_prenom;
 *						 m_nom;
 *						 m_dateNaissance;
 *						 m_adresse;
 */
class Personne
{
public:
	Personne(const std::string & p_nas, const std::string & p_prenom, const std::string & p_nom,
			const util::Date & p_dateNaissance, const util::Adresse & p_adresse);

	const std::string & reqNas() const;
	const std::string & reqPrenom() const;
	const std::string & reqNom() const;
	const util::Date & reqDateNaissance() const;
	const util::Adresse & reqAdresse() const;

	bool operator ==(const Personne & p_personne);
	const std::string reqPersonneFormate() const;
	void asgNouvelleAdresse(int p_numeroCivic, const std::string & p_nomRue, const std::string & p_ville,
			const std::string & p_codePostal, const std::string & p_province);


private:
	std::string m_nas;
	std::string m_prenom;
	std::string	m_nom;
	util::Date m_dateNaissance;
	util::Adresse m_adresse;



};

} /* namespace util */

#endif /* PERSONNE_H_ */
