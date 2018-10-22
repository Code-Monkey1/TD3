/********************************************
* Titre: Travail pratique #3 - depenseGroupe.cpp
* Date : 22 octobre 2018
* Auteurs: Raphael Geoffrion et Jules Lefebvre
*******************************************/

#include "depenseGroupe.h"

//constructeurs
DepenseGroupe::DepenseGroupe(const string& nom, double montant, const string& lieu) : Depense(), nombreParticipants_(0)
{
	setType(groupe);
}

DepenseGroupe::DepenseGroupe(const DepenseGroupe& depense) : Depense(depense), nombreParticipants_(0)
{
	setType(groupe);
}

DepenseGroupe::DepenseGroupe(const Depense& depense) : Depense(depense), nombreParticipants_(0)
{
	setType(groupe);
}

//getters
unsigned int DepenseGroupe::getNombreParticipants() const
{
	return nombreParticipants_;
}

double DepenseGroupe::getMontantPersonnel() const
{
	double montantPersonnel = 0.0;
	if (nombreParticipants_ != 0)	//Retourne 0 si il n y a pas de participants de le groupe
	{
		montantPersonnel = getMontant() / nombreParticipants_;
	}
	return montantPersonnel;
}

//setters
void DepenseGroupe::setNombreParticipants(unsigned int nombreParticipants)
{
	nombreParticipants_ = nombreParticipants;
}

//affichage par surcharge
ostream & operator<<(ostream & os, const DepenseGroupe & depenseGroupe)	
{
	os << static_cast<Depense>(depenseGroupe) << " Cette depense a ete fait par " << depenseGroupe.getNombreParticipants()
		<< "personne(s), soit " << depenseGroupe.getMontantPersonnel() << " par personne." << endl;
	return os;
}
