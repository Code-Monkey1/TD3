/********************************************
* Titre: Travail pratique #3 - utilisateurPremium.cpp
* Date : 22 octobre 2018
* Auteurs: Raphael Geoffrion et Jules Lefebvre
*******************************************/

#include "utilisateurPremium.h"

UtilisateurPremium::UtilisateurPremium(const string & nom, unsigned int joursRestants, double taux):Utilisateur(nom,Premium,taux)
{
	joursRestants_ = joursRestants;
	taux_ = taux;
}

UtilisateurPremium::UtilisateurPremium(const Utilisateur & utilisateur):Utilisateur(utilisateur)
{
	// Doit-on initialiser joursRestants_ et taux_ ?
}

// Méthodes d'accès

unsigned int UtilisateurPremium::getJoursRestants() const
{
	return joursRestants_;
}

double UtilisateurPremium::getTaux() const
{
	return taux_;
}

// Méthode de modification

void UtilisateurPremium::setJoursRestants(unsigned int joursRestants)
{
	joursRestants_ = joursRestants;
}

// Méthode de calcul

void UtilisateurPremium::calculerTaux()
{
	int nombreDepense = getNombreDepenses();
	int decroissanceTaux = nombreDepense / 2; // Nombre de fois qu'on doit soustraire 1% d'intérêt au taux en fonction du nombre de dépenses effectuées.
	taux_ = TAUX_INITIAL_PREMIUM - (decroissanceTaux*0.01);
}

// Surcharges d'opérateurs

UtilisateurPremium & UtilisateurPremium::operator=(Utilisateur * utilisateur)
{
	// 
}

ostream & operator<<(ostream & os, const UtilisateurPremium & utilisateur)
{
	// TODO: insérer une instruction return ici
}
