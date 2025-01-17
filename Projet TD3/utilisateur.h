/********************************************
* Titre: Travail pratique #3 - utilisateur.h
* Date: 22 octobre 2018
* Auteur: Jules Lefebvre et Raphael Geoffrion
*******************************************/

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>
#include <vector>
#include"depenseGroupe.h"
#include"depense.h"

const double TAUX_REGULIER = 0.05;
const double TAUX_INITIAL_PREMIUM = 0.05;
const unsigned int JOURS_RESTANTS_INITIAL = 30;

enum TypeUtilisateur{Regulier, Premium};

using namespace std;

class Utilisateur {
public:
	// Constructeurs
	Utilisateur(const string& nom = "", TypeUtilisateur type = Regulier);
	Utilisateur(const Utilisateur& utilisateur);

	//destructeur 
	~Utilisateur(); 

	// Methodes d'acc�s
	string getNom() const;
	double getInteret() const; 
	double getTotalDepenses() const;
	TypeUtilisateur getType() const; 
	vector<Depense*> getDepenses() const; 
	unsigned int getNombreDepenses() const; 

	// Methodes de modification
	void setNom(const string& nom);
	void ajouterInteret(double montant);
	void calculerTotalDepenses(); 

	Utilisateur& operator+=(Depense* depense);
	Utilisateur& operator=(Utilisateur* utilisateur);
	
	// Methode d'affichage
	friend ostream& operator<<(ostream& os, const Utilisateur& user);


private:
	double interet_;
	string nom_;
	TypeUtilisateur type_; 
	vector <Depense*> depenses_;
	double totalDepense_; 
};
#endif