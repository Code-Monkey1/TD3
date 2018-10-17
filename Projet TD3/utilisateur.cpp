/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa 
*******************************************/

#include "utilisateur.h"

// Constructeurs

Utilisateur::Utilisateur()
{
}

Utilisateur::Utilisateur(const string& nom, TypeUtilisateur type, double interet)
{
	nom_ = nom;
	type_ = type;
	interet_ = interet;
}

Utilisateur::Utilisateur(const Utilisateur& utilisateur) 
{
	nom_ = utilisateur.getNom();
	type_ = utilisateur.getType();
	interet_ = utilisateur.getInteret();
	depenses_ = utilisateur.getDepenses();
	totalDepense_ = utilisateur.getTotalDepenses();
}

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
	double total = 0;
	for (int i = 0; i < depenses_.size(); i++) {
		total += depenses_[i]->getMontant();
	}
	totalDepense_ = total;
}

Utilisateur& Utilisateur::operator+=(Depense* pointeurDepense) {
	depenses_.push_back(pointeurDepense);
	return *this;
}

Utilisateur& Utilisateur::operator=(Utilisateur* pointeurUtilisateur) {
	if (this != pointeurUtilisateur) {
		nom_ = pointeurUtilisateur->getNom();
		interet_ = pointeurUtilisateur->getInteret();
		type_ = pointeurUtilisateur->getType();
		/*for (int i = 0; i < depenses_.size(); i++) {
			delete depenses_[i];
			depenses_[i] = nullptr;
		}*/
		depenses_ = pointeurUtilisateur->getDepenses();
	}
	return *this;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur)
{
	os << "Utilisateur : " << utilisateur.getNom() << " (" << utilisateur.getType() << ") a depense pour un total de : " << utilisateur.getTotalDepenses()
		<< ", PolyCount prend en interet : " << utilisateur.getInteret() << ", voici les depenses :" << endl;
	for (unsigned int i = 0; i < utilisateur.getNombreDepenses(); i++) {
		cout << "\t\t" << (*utilisateur.depenses_[i]);
	}
	return os;
}
