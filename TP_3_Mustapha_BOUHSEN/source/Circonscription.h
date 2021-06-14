/*
 * \file ciconsription.h
 * \brief Fichier qui contient l'interface de la classe Ciconsription qui sert au maintien et à la manipulation des ciconsriptions
 * \author Mustapha BOUHSEN
 */

#ifndef CIRCONSCRIPTION_H_
#define CIRCONSCRIPTION_H_
#include"Candidat.h"
#include"Personne.h"
#include<iostream>
#include <vector>

namespace elections
{
/**
 * \class Circonscription
 * \brief Cette classe sert au maintien et à la manipulation des circonsription.
 *
 *          Attributs:
 *                       m_nomCirconscription;
 * 						 m_deputeElu;
 *				         m_vInscrits;
 *
 *
 *
 *
 */
class Circonscription
{
public:

	Circonscription(const std::string & p_nomCirconscription, const Candidat & p_candidat);
	Circonscription(const Circonscription & p_circonscription);
	~Circonscription();


	const std::string & reqNomCirconscription() const;
	const Candidat & reqCandidat() const;
	const std::string reqCirconscriptionFormate() const;
	void inscrire(const Personne & p_nouvelInscrit);
	const std::vector<Personne*> & reqInscrit() const;
	const Circonscription operator= (const Circonscription & p_circonscription);

private:

	std::string m_nomCirconscription;
	Candidat m_deputeElu;
	std::vector<Personne*> m_vInscrits;
	void verifieInvariant() const;
};
}/* namespace elections */
#endif /* CIRCONSCRIPTION_H_ */
