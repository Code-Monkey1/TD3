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

// M�thode d'acc�s

bool UtilisateurRegulier::estGroupe() const
{
	return estGroupe_;
}

// M�thodes de modification

void UtilisateurRegulier::setEtatGroupe(bool etat)
{
	estGroupe_ = etat;
}

// surcharge de l'op�rateur =. Utilise la surcharge de la classe m�re Utilisateur.
UtilisateurRegulier & UtilisateurRegulier::operator=(Utilisateur* pointeurUtilisateur)
{
	static_cast<Utilisateur>(*pointeurUtilisateur) = *pointeurUtilisateur;
	return *this;
}

// M�thode d'affichage

// surcharge de l'op�rateur <<. Utilise la surcharhe de la classe m�re Utilisateur.
ostream & operator<<(ostream & os, const UtilisateurRegulier & utilisateur)
{
	os << static_cast<Utilisateur>(utilisateur);
	// Si besoin est, les d�penses de groupe sont affich�es par la surcharge << de la classe Utilisateur.
	return os;
}
