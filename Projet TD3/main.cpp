/********************************************
* Titre: Travail pratique #3 - main.cpp
* Date: 16 septembre 2018
* Auteur: David Dratwa
* R�ponses aux questions :
*
*1. Il est tout � fait logique de d�river une classe UtilisateurPremium 
*	et une classe UtilisaterRegulier d'une classe utilisateur, car on peut
*	affirmer qu'un utilisateur Premium (ou Regulier) est un utilisateur.
*	Cela respecte donc le concept de l'h�ritage.  Aussi, dans notre cas,
*	l'utilisation de la classe parent utilisateur nous permet d'�viter de
*	r��crire du code qui se trouverait dans utilisateur premium et utilisateur
*	r�gulier. L'usage des classes d�riv�es est donc justifi�.
*
*2.	1. La fonction static_cast permet de transformer le type d'un pointeur.
*	Dans le	cas de la surcharge de << de la classe groupe, static_cast permet
*	l'acc�s aux m�thodes des affichages des diff�rentes classes.
*	
*	2. Si on omet la fonction static_cast dans la m�thode d'affichage de la
*	classe groupe (surcharge <<) on n'aura pas acc�s aux m�thodes d'affichages
*	des diff�rentes classes.
*******************************************/

#include <iostream>
#include "depense.h";
#include "utilisateur.h"
#include "transfert.h"
#include "groupe.h"

using namespace std;

int main() {

	//initialisation des utilisateurs et des comptes utilisateurs: 
	UtilisateurPremium* alex = new UtilisateurPremium("alex");
	UtilisateurPremium* max = new UtilisateurPremium("Max");
	UtilisateurPremium* henri = new UtilisateurPremium("Henri");
	UtilisateurPremium* louis = new UtilisateurPremium("Louis"); 

	UtilisateurRegulier* albert = new UtilisateurRegulier("albert");
	UtilisateurRegulier* charles = new UtilisateurRegulier("Charles");
	UtilisateurRegulier* allan = new UtilisateurRegulier("Allan");
	UtilisateurRegulier* clemence = new UtilisateurRegulier("Clemence");

	// Initialisation des depenses 
	Depense* d1 = new Depense("d1", 10, "Bruxelles");
	Depense* d2 = new Depense("d2", 30, "Bruxelles");
	Depense* d3 = new Depense("d3", 15, "Bruxelles");
	Depense* d4 = new Depense("d4", 100, "Bruxelles");
	Depense* d5 = new Depense("d5", 120, "Bruxelles");

	DepenseGroupe* d6 = new DepenseGroupe("d6", 1000, "Montreal");
	DepenseGroupe* d7 = new DepenseGroupe( "d7", 430, "Montreal");
	DepenseGroupe* d8 = new DepenseGroupe( "d8", 50, "Montreal");
	DepenseGroupe* d9 = new DepenseGroupe("d9", 330, "Montreal");

	//Initialisation des groupes
	Groupe vacances("Madrid");
	Groupe collocation("Coollocation");

	//Changement nombre de jours pour l'abonnement premium de Louis
	louis->setJoursRestants(0); 

	//Ajouts Utilistaeurs dans les groupes
	(((((((vacances += alex) += max) += henri) += albert) += charles) += allan) += clemence)+=louis; 

	//ajout des depenses indiviuelles 
	*henri += d1; 
	*henri += d2; 
	*henri += d3; 
	*henri += d4;
	*henri += d5; 

	//ajout des depenses groupe

	//vecteur pour le partage de la depense
	vector<Utilisateur*> payePour1;
	payePour1.push_back(alex);
	payePour1.push_back(max);
	payePour1.push_back(charles);
	payePour1.push_back(allan);

	vacances.ajouterDepense(d1, clemence, payePour1); 
	vacances.ajouterDepense(d6, clemence, payePour1); 

	//vecteur pour le partage de la depense
	vector<Utilisateur*> payePour2;
	payePour2.push_back(charles);
	payePour2.push_back(henri);
	payePour2.push_back(max);
	payePour2.push_back(allan);
	vacances.ajouterDepense(d7, albert, payePour2);


	vector<Utilisateur*> payePour3;
	payePour3.push_back(alex);
	payePour3.push_back(max);
	vacances.ajouterDepense(d8, louis, payePour3); 

	
	vacances.calculerTotalDepense();
	vacances.equilibrerComptes(); 

	//ajout d'un utilisateur regulier deja groupe au groupe collocation
	collocation += clemence; 


	//affichage du groupe vacances 
	cout << vacances; 


	//fin du programme 
	delete d1; 
	d1 = nullptr; 
	delete d2;
	d2 = nullptr;
	delete d3;
	d3 = nullptr;
	delete d4;
	d4 = nullptr;
	delete d5;
	d5 = nullptr;
	delete d6;
	d6 = nullptr;
	delete d7;
	d7 = nullptr;
	delete d8;
	d8 = nullptr;
	delete d9;
	d9 = nullptr;
	
	delete alex; 
	delete charles; 
 	delete henri; 
	delete louis; 

	delete albert; 
	delete max; 
	delete allan;
	delete clemence; 

	system("pause");
	return 0;
}
