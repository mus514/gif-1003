/*
 * \file Candidat.cpp
 * \brief Implantation de la classe Candidat
 * \author Mustapha BOUHSEN
 */


#include "Candidat.h"
#include"Personne.h"
#include"Adresse.h"
#include"Date.h"
#include<sstream>
#include<iostream>
using namespace std;

namespace elections
{
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Candidat à partir de valeurs passées en paramètres.
 * \param[in] p_nas est une chaine de caratere qui représente le NAS
 * \param[in] p_prenom est une chaine de caratere qui représente le prenom de la personne
 * \param[in] p_nom est une chaine de caratere qui représente le nom de la personne
 * \param[in] p_dateNaissance est un objet Date qui représente la date de naissance de la personne
 * \param[in] p_adresse est un objet Adresse qui représente l'adresse de la personne
 * \param[in] p_parti est un entier qui represente le parti politique
 * \pre p_parti doit etre entre 0 et 4 ce qui correspond a un parti
 * \post m_partiPolitique prend la valeur de p_parti
 */
Candidat::Candidat(const std::string & p_nas, const std::string & p_prenom, const std::string & p_nom,
			const util::Date & p_dateNaissance, const util::Adresse & p_adresse, int p_parti)
:Personne(p_nas, p_prenom, p_nom, p_dateNaissance,p_adresse), m_partiPolitique(p_parti)
{
	PRECONDITION((p_parti == BLOC_QUEBECOIS) || (p_parti == CONSERVATEUR) || (p_parti == INDEPENDANT) ||
			(p_parti == LIBERAL) || (p_parti == NOUVEAU_PARTI_DEMOCRATIQUE));

	POSTCONDITION(m_partiPolitique == p_parti);
	INVARIANTS();

}

/**
 * \brief constructeur avec paramètres
 * 		  On construit une copie d'un objet Candidat
 * \param[in] p_candidat est un objet Candidat
 * \post m_partiPolitique prend la valeur de p_parti
 */
Candidat::Candidat(const Candidat & p_candidat)
:Personne(p_candidat.reqNas(), p_candidat.reqPrenom(), p_candidat.reqNom(), p_candidat.reqDateNaissance(),
		p_candidat.reqAdresse()), m_partiPolitique(p_candidat.reqParti())
{

	POSTCONDITION(m_partiPolitique == p_candidat.reqParti() );
	INVARIANTS();

}

/**
 * \brief retourne un pointeur de l'objet Candidat
 * \return un pointeur qui représente le Candidat
 */
Personne* Candidat::clone() const
{
	return new Candidat(*this);
}

/**
 * \brief retourne le numero du parti
 * \return un entier qui représente le parti
 */
int Candidat::reqParti() const
{
	return m_partiPolitique;
}

/**
 * \brief retourne un candidat formatée dans une chaîne de caracères
 * \return un candidat formatée dans une chaîne de caractères
 */
std::string Candidat::reqPersonneFormate() const
{
	std::ostringstream os;
	os << "Candidat" << endl;
	os << elections::Personne::reqPersonneFormate();
	os << "Parti politique     :";

	switch(m_partiPolitique)
	{
	case(BLOC_QUEBECOIS) : os << " BLOC_QUEBECOIS" << endl; break;
	case(CONSERVATEUR) : os << " CONSERVATEUR" << endl; break;
	case(INDEPENDANT) : os << " INDEPENDANT" << endl; break;
	case(LIBERAL) : os << " LIBERAL" << endl; break;
	case(NOUVEAU_PARTI_DEMOCRATIQUE) : os << " NOUVEAU_PARTI_DEMOCRATIQUE" << endl; break;
	}

	return os.str();
}

/**
 * \brief Vérifier les invariants de classe
 */
void Candidat::verifieInvariant() const
{
	INVARIANT((m_partiPolitique == BLOC_QUEBECOIS) || (m_partiPolitique == CONSERVATEUR) ||
			(m_partiPolitique == INDEPENDANT) || (m_partiPolitique == LIBERAL) ||
			(m_partiPolitique == NOUVEAU_PARTI_DEMOCRATIQUE));

}

}/* namespace elections */


