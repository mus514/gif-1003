/*
 * \file validationFormat.cpp
 * \brief Fichier qui contient les fonctions de validations
 * \author Mustapha BOUHSEN
 */

#include<iostream>
#include"validationFormat.h"
#include"string.h"
#include<fstream>
#include <sstream>
#include<algorithm>

using namespace std;
namespace util
{
/**
 * \brief Fonction valide le format du numéro d’assurance sociale
 * \param[in] p_nas une chaîne de caractères qui représente le nas
 * \return bool qui valide le nas
 */
bool validerNas(const std::string& p_nas)
{

	bool reponse = true; // initialiser une reponse
	int longeur = p_nas.length(); //longeur du string

	bool validation_1;
	validation_1 = (p_nas[3]== ' ') && (p_nas[7] == ' ');

	bool validation_2;
	validation_2 = (p_nas[3] == '-') && (p_nas[7] == '-');


	if(longeur != 11)
		reponse = false;
	else // si la longeur est bonne
		{
			if(validation_1 || validation_2)
			{
				string nas_fictif = "121 212 121";
				int resultat = 0;

				for(int i = 0; i < 11; i++)
				{
					int temporaire = 0;

					if((p_nas[i] != ' ') && (p_nas[i] != '-'))
					{
						temporaire = (nas_fictif[i] - '0') * (p_nas[i] - '0'); // conversitre en int

						if(temporaire < 10)
							resultat = resultat + temporaire;

						else // cas ou la multiplication > 10
						{
							string temp = to_string(temporaire);
							resultat = resultat + ((temp[0] - '0') + (temp[1] - '0'));
						}

					 }
				}

			if(resultat % 10 != 0) // pour verifier si devisable par 10
				reponse = false;

			}

			else
			{
				reponse = false;
			}

		}

	return reponse;
}

/**
 * \brief Fonction valide ldu fichier
 * \param[in] p_is est un flux d’entrée passé
 * \return bool qui valide le fichier
 */
bool validerFormatFichier(std::istream& p_is)
{
	bool reponse = true;

	int compteur = 0;
	string tableau[50];

	while(getline(p_is,tableau[compteur]))  // creation du tableau qui va contenir les donnees,
	{
		compteur++;

	}

	if(tableau[0]== "" || validerNas(tableau[0]) == 1 || tableau[0] == "BLOC_QUEBECOIS" || tableau[0] == "CONSERVATEUR"
                                   ||tableau[0] == "INDEPENDANT" || tableau[0] == "LIBERAL" ||
                         tableau[0] == "NOUVEAU_PARTI_DEMOCRATIQUE")
		reponse = false;

	else
	{
		int nb = 0;
		for(int i = 1; i < compteur; i+=nb)
		{
			if(tableau[i] == "BLOC_QUEBECOIS" || tableau[i] == "CONSERVATEUR"
                                   ||tableau[i] == "INDEPENDANT" || tableau[i] == "LIBERAL" ||
	                                                   tableau[0] == "NOUVEAU_PARTI_DEMOCRATIQUE")
			{
				nb = 6;
				for(int j = 1;j < 6 ; j++)
				{
					if(tableau[i+j] == "BLOC_QUEBECOIS" || tableau[i + j] == "CONSERVATEUR"
                                   ||tableau[i + j] == "INDEPENDANT" || tableau[i + j] == "LIBERAL" ||
                         tableau[i + j] == "NOUVEAU_PARTI_DEMOCRATIQUE" || tableau[i + j] ==  "")

						reponse = false;
				}
			}
			else if(validerNas(tableau[i]) == 1)
			{
				nb = 5;
				for(int j = 1;j < 5 ; j++)
				{
					if(tableau[i+j] == "BLOC_QUEBECOIS" || tableau[i + j] == "CONSERVATEUR"
					                                   ||tableau[i + j] == "INDEPENDANT" || tableau[i + j] == "LIBERAL" ||
					                         tableau[i + j] == "NOUVEAU_PARTI_DEMOCRATIQUE" || tableau[i + j] ==  "")
						reponse = false;
				}
			}

			else
				reponse = false;
		}
	}
	return reponse;
}


/**
 * \brief Fonction valide si tous les parametres passes au constructeur Adresse sont correctes
 * \param[in] p_numeroCivic est un entier qui représente le numero du domicile
 * \param[in] p_nomRue est une chaine de caratere qui représente le nom de la rue
 * \param[in] p_ville est une chaine de caratere qui représente le nom de la ville
 * \param[in] p_codePostal est une chaine de caratere qui représente le code postal
 * \param[in] p_province est une chaine de caratere qui représente la procince
 * \return bool qui valide l'adresse
 */
bool validerAdresse(int p_numeroCivic, const std::string & p_nomRue, const std::string & p_ville,
		const std::string & p_codePostal, const std::string & p_province)
{
	return ((p_numeroCivic > 0) && (p_nomRue != "") && (p_ville != "") && (p_codePostal != "")
			&& (p_province != ""));
}

/**
 * \brief Fonction valide le paramtere prenom
 * \param[in] p_prenom une chaîne de caractères qui représente le prenom
 * \return bool qui valide le prenom
 */
bool validerPrenom(std::string& p_prenom) {return(p_prenom == "");}

/**
 * \brief Fonction valide le paramtere nom
 * \param[in] p_nom une chaîne de caractères qui représente le nom
 * \return bool qui valide le nom
 */
bool validerNom(std::string& p_nom) {return(p_nom == "");}


}




