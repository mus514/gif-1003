/*
 * \file Candidat.h
 * \brief Fichier qui contient l'interface de la classe Candidat qui sert au maintien et à la manipulation des candidats
 * \author Mustapha BOUHSEN
 */


#ifndef CANDIDAT_H_
#define CANDIDAT_H_
#include"Personne.h"
#include"Adresse.h"
#include<iostream>

namespace elections
{
/**
 * \class Candidat
 * \brief Cette classe herite de la classe Personne et sert au maintien et à la manipulation des Candidat.
 *
 *       Attributs:
 *                 m_partiPolitique
 *
 */
class Candidat : public elections::Personne
{
public:

	Candidat(const std::string & p_nas, const std::string & p_prenom, const std::string & p_nom,
			const util::Date & p_dateNaissance, const util::Adresse & p_adresse, int p_parti);

	Candidat(const Candidat & p_candidat);

	enum PartisPolitiques {BLOC_QUEBECOIS, CONSERVATEUR, INDEPENDANT, LIBERAL,
	NOUVEAU_PARTI_DEMOCRATIQUE};

	int reqParti() const;

	virtual Personne* clone() const;

	virtual std::string reqPersonneFormate() const;
	//virtual Personne* clone() const;


private:

	int m_partiPolitique;
	void verifieInvariant() const;
};
}/* namespace elections */
#endif /* CANDIDAT_H_ */
