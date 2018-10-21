#include "depenseGroupe.h"

DepenseGroupe::DepenseGroupe(const string& nom, double montant, const string& lieu) : Depense(), nombreParticipants_(0)
{
	setType(groupe);
}

DepenseGroupe::DepenseGroupe(const DepenseGroupe& depense) : Depense(depense), nombreParticipants_(0)
{
	setType(groupe);
}

unsigned int DepenseGroupe::getNombreParticipants() const
{
	return nombreParticipants_;
}

double DepenseGroupe::getMontantPersonnel() const
{
	double montantPersonnel = 0.0;
	if (nombreParticipants_ != 0)
	{
		montantPersonnel = getMontant() / nombreParticipants_;
	}
	return montantPersonnel;
}

void DepenseGroupe::setNombreParticipants(unsigned int nombreParticipants)
{
	nombreParticipants_ = nombreParticipants;
}

ostream & operator<<(ostream & os, const DepenseGroupe & depenseGroupe)
{
	os << static_cast<Depense>(depenseGroupe) << " Cette depense a ete fait par " << depenseGroupe.getNombreParticipants()
		<< "personne(s), soit " << depenseGroupe.getMontantPersonnel() << " par personne." << endl;
	return os;
}
