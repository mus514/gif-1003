/**
 * \file principale.cpp
 * \brief Utilisation de notre classes Personne et Adresse pour créer des objets
 * \author Mustapha BOUHSEN
 */
#include<iostream>
#include"Adresse.h"
#include"Date.h"
#include"validationFormat.h"
#include"Personne.h"

using namespace std;
using namespace util;
using namespace elections;

int main()
{
    // declaration des parametres qui vont etres affecter au constructeur de la classe Personne et Adresse
	string nas;
	string prenom;
	string nom;

	int numeroCivic;
	string nomRue;
	string ville;
	string codePostal;
	string province;

	int jour;
	int mois;
	int annee;

	cout<<"Bienvenue a l'outil d'ajout d'une personne"<<endl;
	cout<<"------------------------------------------"<<endl;

	do{
		cout<<"Entrez son numéro d’assurance sociale"<<endl;
		char buffer[256];
		cin.getline(buffer, 256);
		nas = buffer;
		if(validerNas(nas) == 0)
			cout<<"NAS invalide,"<<endl;

	}while(validerNas(nas) == 0);

	do{
		cout<<"Entrez le premom :"<<endl;
		char buffer[256];
		cin.getline(buffer, 256);
		prenom = buffer;

		if(validerPrenom(prenom))
			cout<<"Le prénom est vide"<<endl;

	}while(validerPrenom(prenom));

	do{
		cout<<"Entrez le nom :"<<endl;
		char buffer[256];
		cin.getline(buffer, 256);
		nom = buffer;

		if(validerNom(nom))
			cout<<"Le nom est vide"<<endl;

	}while(validerNom(nom));


	do{
		cout<<endl;
		cout << "Veuillez entrer sa date de naissance"<<endl;
		cout << "Le jour [1..31]:"<<endl;
		cin >> jour;
		cout << "Le mois [1..12]:"<<endl;
		cin >> mois;
		cout << "L'annee [1970..2037]:"<<endl;
		cin >> annee;

		if(Date::validerDate(jour, mois, annee) == 0)
			cout<<"La date de naissance n'est pas valide"<<endl;

	}while(Date::validerDate(jour, mois, annee) == 0);

	Date dateNaissance(jour, mois, annee);

	do{
		cout<<endl;
		cout << "Entrez l'adresse"<<endl;
		cout << "Numéro de rue"<<endl;
		cin >> numeroCivic;

		cout << "Rue:"<<endl;
		char buffer[256];
		cin.ignore();
		cin.getline(buffer, 256);
		nomRue = buffer;

		cout<<"Ville"<<endl;
		cin.getline(buffer, 256);
		ville = buffer;

		cout<<"Code postal"<<endl;
		cin.getline(buffer, 256);
		codePostal = buffer;

		cout<<"Province"<<endl;
		cin.getline(buffer, 256);
		province = buffer;

		if(validerAdresse(numeroCivic, nomRue, ville, codePostal, province) == 0)
			cout<<"L'adresse n'est pas valide !"<<endl;

	}while(validerAdresse(numeroCivic, nomRue, ville, codePostal, province) == 0);

	// Une fois les parametres sont verifiers, on peut consruire nos objets
	Adresse adresse(numeroCivic, nomRue, ville, codePostal, province);
	Personne personne(nas, prenom, nom, dateNaissance, adresse);

	//Affichage des informations
	cout<<personne.reqPersonneFormate()<<endl;

	// Demander a l'utilisateur de modifier l'adresse de la personne construite
	cout<<"Saisir la nouvelle adresse"<<endl;
	do{
		cout<<endl;
		cout << "Entrez l'adresse"<<endl;
		cout << "Numéro de rue"<<endl;
		cin >> numeroCivic;
		cin.ignore();

		char buffer[256];
		cout << "Rue:"<<endl;
		cin.getline(buffer, 256);
		nomRue = buffer;

		cout<<"Ville:"<<endl;
		cin.getline(buffer, 256);
		ville = buffer;

		cout<<"Code postal"<<endl;
		cin.getline(buffer, 256);
		codePostal = buffer;

		cout<<"Province"<<endl;
		cin.getline(buffer, 256);
		province = buffer;

		if(validerAdresse(numeroCivic, nomRue, ville, codePostal, province) == 0)
			cout<<"L'adresse n'est pas valide !"<<endl;

	}while(validerAdresse(numeroCivic, nomRue, ville, codePostal, province) == 0);

	//Une fois les parametres verifiers, on change l'adresse
	personne.asgNouvelleAdresse(numeroCivic, nomRue, ville, codePostal, province);

	//Affichage des informations
	cout<<personne.reqPersonneFormate();

	return 0;
}


