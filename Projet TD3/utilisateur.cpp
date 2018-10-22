/********************************************
* Titre: Travail pratique #3 - utilisateur.cpp
* Date: 22 octobre 2018
* Auteur: Jules Lefebvre et Raphael Geoffrion 
*******************************************/

#include "utilisateur.h"

// Constructeurs

Utilisateur::Utilisateur(const string& nom, TypeUtilisateur type)
{
	nom_ = nom;
	type_ = type;
	interet_ = 0;
	double totalDepense_ = 0;
}

Utilisateur::Utilisateur(const Utilisateur& utilisateur) 
{
	nom_ = utilisateur.getNom();
	type_ = utilisateur.getType();
	interet_ = utilisateur.getInteret();
	depenses_ = utilisateur.getDepenses();
	totalDepense_ = utilisateur.getTotalDepenses();
}

// destructeur
Utilisateur::~Utilisateur()
{
}

// Methodes d'acces

string Utilisateur::getNom() const {
	return nom_;
}

double Utilisateur::getTotalDepenses() const {
	return totalDepense_;
}

TypeUtilisateur Utilisateur::getType() const {
	return type_; 
}

double Utilisateur::getInteret() const {
	return interet_; 
}

unsigned int Utilisateur::getNombreDepenses() const {
	return depenses_.size();
}

vector <Depense*> Utilisateur::getDepenses() const {
	return depenses_; 
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

void Utilisateur::ajouterInteret(double montant) {
	interet_ += montant;
}

void Utilisateur::calculerTotalDepenses() {
	double totalDepenses = 0;
	double montantInteret = 0;
	for (int i = 0; i < depenses_.size(); i++) {
		// Calcul du total de depense de l'utilisateur.
		totalDepenses += depenses_[i]->getMontant();
		// Calcul de l'interet retenu par Polycount pour cet utilisateur.
		montantInteret = depenses_[i]->getMontant() * interet_;
		ajouterInteret(montantInteret);
	}
	totalDepense_ = totalDepenses;
}

// surcharge de l'opérateur += pour ajouter une depense (ptr depense) à un utilisateur.
Utilisateur& Utilisateur::operator+=(Depense* pointeurDepense) {
	depenses_.push_back(pointeurDepense);
	return *this;
}

// surcharge de l'opérateur = pour copier les attributs d'un autre utilisateur à la façon du constructeur par copie.
Utilisateur& Utilisateur::operator=(Utilisateur* pointeurUtilisateur) {
	if (this != pointeurUtilisateur) {
		nom_ = pointeurUtilisateur->getNom();
		interet_ = pointeurUtilisateur->getInteret();
		type_ = pointeurUtilisateur->getType();
		// Correction du TD2: "Dans l'operator =, il ne faut pas détruire toutes les dépenses."
		/*for (int i = 0; i < depenses_.size(); i++) {
			delete depenses_[i];
			depenses_[i] = nullptr;
		}*/
		depenses_ = pointeurUtilisateur->getDepenses();
		totalDepense_ = pointeurUtilisateur->getTotalDepenses();
	}
	return *this;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur)
{
	os << "Utilisateur : " << utilisateur.getNom() << " (" << utilisateur.getType() << ") a depense pour un total de : " << utilisateur.getTotalDepenses()
		<< ", PolyCount prend en interet : " << utilisateur.getInteret() << ", voici les depenses :" << endl;
	// Dépenses individuelles
	for (unsigned int i = 0; i < utilisateur.getNombreDepenses(); i++) {
		if(utilisateur.depenses_[i]->getType() == individuelle){
			cout << "\t\t" << (*utilisateur.depenses_[i]) << endl;
		}
	}
	// Dépenses de groupe
	for (unsigned int i = 0; i < utilisateur.getNombreDepenses(); i++) {
		if (utilisateur.depenses_[i]->getType() == groupe) {
			cout << "\t\t" << "Depense de groupe :\t" << (*utilisateur.depenses_[i]) << endl;
		}
	}
	return os;
}
