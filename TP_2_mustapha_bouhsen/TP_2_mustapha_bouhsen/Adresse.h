/*
 * \file Adresse.h
 * \brief Fichier qui contient l'interface de la classe Adresse qui sert au maintien et à la manipulation des Adresse
 * \author Mustapha BOUHSEN
 */

#ifndef ADRESSE_H_
#define ADRESSE_H_
#include<iostream>

namespace util
{
/**
 * \class Adresse
 * \brief Cette classe sert au maintien et à la manipulation des adresses.
 *
 *             Attributs:
 *                          m_numeroCivic
 *							m_nomRue:
 *							m_ville
 *							m_codePostal
 *						    m_province
 */

class Adresse
{

public:

	Adresse(int p_numeroCivic, const std::string & p_nomRue, const std::string & p_ville,
			const std::string & p_codePostal, const std::string & p_province);

	void asgAdresse(int p_numeroCivic, const std::string & p_nomRue, const std::string & p_ville,
			const std::string & p_codePostal, const std::string & p_province);

	int reqNumeroCivic() const ;
	const std::string & reqNomRue() const;
	const std::string & reqVille() const;
	const std::string & reqCodePostal() const;
	const std::string & reqProvince() const;
	bool operator ==(const Adresse & p_adresse);
	const std::string reqAdresseFormate() const;


private:

	int m_numeroCivic;
	std::string m_nomRue;
	std::string m_ville;
	std::string m_codePostal;
	std::string m_province;

};
}
/* namespace util */
#endif /* ADRESSE_H_ */
