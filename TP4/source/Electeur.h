/*
 * \file Electeur.h
 * \brief Fichier qui contient l'interface de la classe Electeur qui sert au maintien et à la manipulation des electeurs
 * \author Mustapha BOUHSEN
 */

#ifndef ELECTEUR_H_
#define ELECTEUR_H_

#include"Personne.h"
#include"Adresse.h"
#include"Date.h"
#include<iostream>

namespace elections
{
/**
 * \class Electeur
 * \brief Cette classe herite de la classe Personne et sert au maintien et à la manipulation des Electeurs
 *
 */
class Electeur : public elections::Personne
{
public:
	Electeur(const std::string & p_nas, const std::string & p_prenom, const std::string & p_nom,
			const util::Date & p_dateNaissance, const util::Adresse & p_adresse);

	Electeur(const Electeur & p_electeur);

	virtual Personne* clone() const;
	virtual std::string reqPersonneFormate() const;

};
}/* namespace elections */
#endif /* ELECTEUR_H_ */
