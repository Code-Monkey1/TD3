/********************************************
* Titre: Travail pratique #3 - utilisateurRegulier.cpp
* Date : 22 octobre 2018
* Auteurs: Raphael Geoffrion et Jules Lefebvre
*******************************************/

#include "utilisateurRegulier.h"

// Constructeurs

UtilisateurRegulier::UtilisateurRegulier(const string & nom, bool estGroupe):Utilisateur(nom, Regulier, TAUX_REGULIER)
{
	estGroupe_ = estGroupe;
}

UtilisateurRegulier::UtilisateurRegulier(const Utilisateur & utilisateur):Utilisateur(utilisateur)
{
	// Doit-on initialiser estGroupe_ ?
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
UtilisateurRegulier & UtilisateurRegulier::operator=(Utilisateur * utilisateur)
{
	// Comment utiliser = de la classe m�re?
}

// M�thode d'affichage

// surcharge de l'op�rateur <<. Utilise la surcharhe de la classe m�re Utilisateur.
ostream & operator<<(ostream & os, const UtilisateurRegulier & utilisateur)
{
	// Utilisation de << de la classe Utilisateur
	
	if (utilisateur.estGroupe() == true) {
		// utilisateur fait partie du groupe...
	}
	else {
		// utilisateur est non-group�...
	}
}
