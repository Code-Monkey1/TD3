/********************************************
* Titre: Travail pratique #3 - utilisateurRegulier.cpp
* Date : 22 octobre 2018
* Auteurs: Raphael Geoffrion et Jules Lefebvre
*******************************************/

#include "utilisateurRegulier.h"

// Constructeurs

UtilisateurRegulier::UtilisateurRegulier(const string & nom, bool estGroupe):Utilisateur(nom, Regulier), estGroupe_(estGroupe)
{
}

UtilisateurRegulier::UtilisateurRegulier(const Utilisateur & utilisateur):Utilisateur(utilisateur)
{
	setEtatGroupe(false);
}

// Méthode d'accès

bool UtilisateurRegulier::estGroupe() const
{
	return estGroupe_;
}

// Méthodes de modification

void UtilisateurRegulier::setEtatGroupe(bool etat)
{
	estGroupe_ = etat;
}

// surcharge de l'opérateur =. Utilise la surcharge de la classe mère Utilisateur.
UtilisateurRegulier & UtilisateurRegulier::operator=(Utilisateur* pointeurUtilisateur)
{
	static_cast<Utilisateur>(*pointeurUtilisateur) = *pointeurUtilisateur;
	return *this;
}

// Méthode d'affichage

// surcharge de l'opérateur <<. Utilise la surcharhe de la classe mère Utilisateur.
ostream & operator<<(ostream & os, const UtilisateurRegulier & utilisateur)
{
	os << static_cast<Utilisateur>(utilisateur);
	// Si besoin est, les dépenses de groupe sont affichées par la surcharge << de la classe Utilisateur.
	return os;
}
