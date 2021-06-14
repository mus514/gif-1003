/*
 * \file validationFormat.h
 * \brief Fichier qui contient les declarations des fonctions de validations
 * \author Mustapha BOUHSEN
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_
#include<iostream>
#include<string>

namespace util
{
bool validerNas(const std::string& p_nas);
bool validerFormatFichier(std::istream& p_is);
bool validerPrenom(std::string& p_prenom);
bool validerNom(std::string& p_nom);
bool validerAdresse(int p_numeroCivic, const std::string & p_nomRue, const std::string & p_ville,
		const std::string & p_codePostal, const std::string & p_province);

}



#endif /* VALIDATIONFORMAT_H_ */
