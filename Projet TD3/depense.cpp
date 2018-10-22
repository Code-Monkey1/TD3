/********************************************
* Titre: Travail pratique #3 - depense.cpp
* Date: 22 octobre 2018
* Auteur: Jules Lefebvre et Raphael Geoffrion
*******************************************/

#include "depense.h"

// Constucteurs

Depense::Depense(const string & nom, double montant, const string & lieu, TypeDepense type)
{
	nom_ = nom;
	montant_ = montant;
	setLieu(lieu);
	type_ = type;
}

Depense::Depense(const Depense & depense) : nom_(depense.getNom()), montant_(depense.getMontant()), lieu_(nullptr), type_(depense.getType())
{
	lieu_ = new string(*depense.getLieu());
}

//Destructeur

Depense::~Depense()
{	
	if (lieu_ != nullptr) {
	delete lieu_;
	lieu_ = nullptr;
	}
}

// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}

string* Depense::getLieu() const
{
	return lieu_;
}

TypeDepense Depense::getType() const
{
	return type_;
}

// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

void Depense::setLieu(const string& nom)
{
	delete lieu_;
	lieu_ = new string(nom);
}

void Depense::setType(TypeDepense type) {
	type_ = type; 
}

Depense& Depense::operator=(const Depense & depense)
{
	if (this != &depense) {

		setNom(depense.getNom());
		setMontant(depense.getMontant());
		lieu_ = new string(*depense.getLieu());
		setType(depense.getType());
	}
	return *this;
}

ostream & operator<<(ostream & os, const Depense & depense)
{
	os << "L'achat fait a " << *depense.getLieu() << " qui se nomme: " << depense.getNom() << " a coute un montant de " << depense.getMontant() << ".";
	return os;
}
