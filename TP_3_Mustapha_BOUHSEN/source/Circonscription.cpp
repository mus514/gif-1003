/*
 * \file Circonsription.cpp
 * \brief Implantation de la classe Circonsription
 * \author Mustapha BOUHSEN
 */

#include"Circonscription.h"
#include"Candidat.h"
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
Circonscription::Circonscription(const std::string & p_nomCirconscription, const Candidat & p_candidat)
:m_nomCirconscription(p_nomCirconscription), m_deputeElu(p_candidat), m_vInscrits(0)
{
	PRECONDITION(!p_nomCirconscription.empty());
	POSTCONDITION(m_nomCirconscription == p_nomCirconscription);
	INVARIANTS();
}

/**
 * \brief constructeur avec paramètres
 * 		  On construit une copie d'un objet Candidat
 * \param[in] p_candidat est un objet Candidat
 * \post m_partiPolitique prend la valeur de p_parti
 */
Circonscription::Circonscription(const Circonscription & p_circonscription)
:m_nomCirconscription(p_circonscription.reqNomCirconscription()),m_deputeElu(Candidat(p_circonscription.reqCandidat())),
 m_vInscrits(0)
{

	for(unsigned int i = 0; i < p_circonscription.reqInscrit().size(); i++)
	{
		inscrire(* p_circonscription.reqInscrit()[i]);

	}
	INVARIANTS();
}

/**
 * \brief destructeur
 * 		  On detruit d'un objet Ciconsroption
 */
Circonscription::~Circonscription()
{
	for(unsigned int i = 0;i < m_vInscrits.size();i++)
	{
		delete  m_vInscrits[i];
	}

}

/**
 * \brief surcharge de l'opérateur =
 * \param[in] p_circonscription qui est une Circonscription valide
 * \return une copie de la ciconsription passee en argument
 */
const Circonscription Circonscription::operator= (const Circonscription & p_circonscription)
{
	m_nomCirconscription = p_circonscription.reqNomCirconscription();
	m_deputeElu = p_circonscription.reqCandidat();

	for(unsigned int i = 0;i < m_vInscrits.size();i++)
		{
			delete m_vInscrits[i];
		}

	for(unsigned int i = 0; i < p_circonscription.reqInscrit().size(); i++)
	{
		inscrire(* p_circonscription.reqInscrit()[i]);

	}

	return *this;
}

/**
 * \brief retourne le nom de la ciconscrption
 * \return une chaine de caratere qui représente la ciconsription
 */
const std::string & Circonscription::reqNomCirconscription() const
{
	return m_nomCirconscription;
}

/**
 * \brief retourne le condidat de la ciconsription deja elu
 * \return un objet Candidat
 */
const Candidat & Circonscription::reqCandidat() const
{
	return m_deputeElu;
}

/**
 * \brief retourne un vecteur de pointeur de personne
 * \return un vecteur
 */
const std::vector<Personne*> & Circonscription::reqInscrit() const
{
	return m_vInscrits;
}

/**
 * \brief retourne une ciconsription avec tous ce qui est dedant formatée dans une chaîne de caracères
 * \return une ciconsription formatée dans une chaîne de caractères
 */
const std::string Circonscription::reqCirconscriptionFormate() const
{
	ostringstream os;
	os << "Circonscription : " << m_nomCirconscription << endl;
	os << "Depute sortant :"<< endl;
	os << m_deputeElu.reqPersonneFormate() << endl;
	os << "Liste des inscrits :"<<endl;

	for(unsigned int i = 0; i < m_vInscrits.size(); i++)
	{
		os << m_vInscrits[i] -> reqPersonneFormate();
	}


	return os.str();
}

/**
 * \brief inscrit la personne dans la circonsription en l'ajoutant dans le vecteur
 */
void Circonscription::inscrire(const Personne & p_nouvelInscrit)
{
	bool reponse = false;

	for(unsigned int i = 0; i < m_vInscrits.size(); i++)
	{
		if(m_vInscrits[i]->reqNas() == p_nouvelInscrit.reqNas())
			reponse = true;
	}

	if(!reponse)
		m_vInscrits.push_back(p_nouvelInscrit.clone());

	INVARIANTS();

}

/**
 * \brief Vérifier les invariants de classe
 */
void Circonscription::verifieInvariant() const
{
	INVARIANT(!m_nomCirconscription.empty());

}

}/* namespace elections */

