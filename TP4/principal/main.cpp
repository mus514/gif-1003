/**
 * \file principale.cpp
 * \brief Utilisation de notre classes Personne, Adresse, Candidat, Electeur, Circonscription pour
 * \créer des objets
 * \author Mustapha BOUHSEN
 */

#include<iostream>
#include"Adresse.h"
#include "Candidat.h"
#include"Personne.h"
#include"Date.h"
#include"Electeur.h"
#include"Circonscription.h"
#include"validationFormat.h"
#include<vector>
using namespace elections;
using namespace util;
using namespace std;

int main()
{
	// Creation de circonscription
	Circonscription circonsription("01", Candidat("046 454 286", "Mustapha", "BOUHSEN",
		       Date(5,6,1991),Adresse(314 , "Miron", "Quebec", "G1V 7A2", "QC"), 3));

   // declaration des parametres qui vont etres affecter au constructeur des classe
	int parti;
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

	cout<<"-----------------------------------------------------"<<endl;
	cout<<"Bienvenue a l'outil de gestion des listes électorales "<<endl;
	cout<<"-----------------------------------------------------"<<endl;

	//Creation du Candidat
	cout<<endl;
	cout<<"Inscription d'un candidat"<<endl;
	cout<<"Choisissez un parti:"<<endl;
	do{
		cout<<"0:BLOC_QUEBECOIS, 1:CONSERVATEUR,2:INDEPENDANT,3:LIBERAL,4:NOUVEAU_PARTI_DEMOCRATIQUE"<<endl;
		cin >> parti;

		if(parti > 4 || parti < 0)
			cout<<"Parti Invalide"<<endl;

		}while(parti > 4 || parti < 0);


	do{
		cout<<"Entrez son numéro d’assurance sociale"<<endl;
		char buffer[256];
		cin.ignore();
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

	// Une fois les parametres sont verifiers, on peut consruire nos objets
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

	// Une fois les parametres sont verifiers, on peut consruire nos objets
	Candidat candidat(nas, prenom, nom, dateNaissance, adresse, parti);

	// Insrire le candidat dans la circonscription
	circonsription.inscrire(candidat);

	//Inscription de l'electeur

	cout<<endl;
	cout<<"Inscription d'un Electeur"<<endl;
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

	// Une fois les parametres sont verifiers, on peut consruire nos objets
	Date dateNaissance1(jour, mois, annee);

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
	Adresse adresse1(numeroCivic, nomRue, ville, codePostal, province);

	//Electeur
	Electeur electeur(nas, prenom, nom, dateNaissance1, adresse1);

	//Inscription de l'electeur
	circonsription.inscrire(electeur);

	cout<<circonsription.reqCirconscriptionFormate() << endl;

	cout<<"fin du programme"<<endl;

	return 0;
}


