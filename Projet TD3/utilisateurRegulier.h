/********************************************
* Titre: Travail pratique #3 - utilisateurRegulier.h
* Date : 22 octobre 2018
* Auteurs: Raphael Geoffrion et Jules Lefebvre
*******************************************/
#ifndef UTILISATEUR_REGULIER_H
#define UTILISATEUR_REGULIER_H

#include "utilisateur.h"

class UtilisateurRegulier : public Utilisateur {
public : 

	//constructeurs 
	UtilisateurRegulier(const string& nom = "", bool estGroupe = false); 
	UtilisateurRegulier(const Utilisateur& utilisateur); 


	//getters
	bool estGroupe() const; 
	 
	//setters
	void setEtatGroupe(bool etat); 
	

	//surcharge

	// Il est demandé d'utiliser la surcharge = de la classe mère.
	UtilisateurRegulier& operator=(Utilisateur* utilisateur);
	
	friend ostream& operator<< (ostream& os, const UtilisateurRegulier& utilisateur); 
private :
	bool estGroupe_;
};

#endif // !UTILISATEUR_REGULIER_H
