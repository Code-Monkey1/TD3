/********************************************
* Titre: Travail pratique #3 - groupe.cpp
* Date: 22 octobre 2018
* Auteur: Jules Lefebvre et Raphael Geoffrion
*******************************************/

#include "groupe.h"

// Constructeurs

Groupe::Groupe() {
	nom_ = ""; 
}
Groupe::Groupe(const string& nom) : nom_(nom) {
}

//Destructeur
Groupe::~Groupe() {
	for (unsigned int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
	}
	for (unsigned int i = 0; i < depenses_.size(); i++)
	{
		delete depenses_[i];
		depenses_[i] = nullptr;
	}
}

// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

vector<DepenseGroupe*> Groupe::getDepenses() const
{
	return depenses_;
}

vector<Utilisateur*> Groupe::getUtilisateurs() const
{
	return utilisateurs_;
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}


double Groupe::getTotalDepenses() const {

	return totalDepenses_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour)
{
	//Variable pour savoir si tous les utilisateurs sont dans le bon groupe
	bool tousBonsUtilisateursSontLa = true;

	//Verifier que le payeur est dans le groupe
	bool payeurEstDansGroupe = false;
	for (unsigned int i = 0; i < utilisateurs_.size() && !payeurEstDansGroupe; i++)
	{
		if (utilisateurs_[i]->getNom() == payePar->getNom())
		{
			payeurEstDansGroupe = true;
		}
	}

	//Si le payeur est dans le groupe, vérifier que les utilisateurs dans payePour sont dans ce même groupe
	if (!payeurEstDansGroupe)
	{
		tousBonsUtilisateursSontLa = false;
	}
	else
	{
		bool utilisateurTrouveDansGroupe = false;
		for (unsigned int i = 0; i < payePour.size() && tousBonsUtilisateursSontLa; i++)
		{
			utilisateurTrouveDansGroupe = false;
			for (unsigned int j = 0; j < utilisateurs_.size() && !utilisateurTrouveDansGroupe; j++)
			{
				if (payePour[i]->getNom() == utilisateurs_[j]->getNom()) {
					utilisateurTrouveDansGroupe = true;
				}
			}
			if (!utilisateurTrouveDansGroupe) {
				tousBonsUtilisateursSontLa = false;
			}
		}
	}
	if (!tousBonsUtilisateursSontLa) {
		cout << "ERREUR: Les personnes impliquees dans la depense groupe ne sont pas dans le groupe." << endl;
	}
	//Vérifier que la dépense est une dépense pour le groupe
	bool estDepenseGroupe = false;
	if (depense->getType() == groupe) {
		estDepenseGroupe = true;
	}
	else
	{
		cout << "ERREUR: Une depense individuelle ne peut pas etre ajouter aux depenses du groupe." << endl;
	}
	if (tousBonsUtilisateursSontLa && estDepenseGroupe) {

		//Faire une depenseGroupe dynamiquement puisque les conditions sont satisfaites
		DepenseGroupe* ptrDepenseGroupe = new DepenseGroupe (*depense);


		//Mettre le nombre de participants. Le +1 est là à cause qu'il y a aussi un payeur.
		ptrDepenseGroupe->setNombreParticipants(payePour.size() + 1);

		//Ajoute la dépense aux utilisateurs concernés
		*payePar += depense;
		for (unsigned int i = 0; i < payePour.size(); i++)
		{
			*payePour[i] += depense;
		}

		//Mets à jour les comptes des utilisateurs concernés
		comptes_.resize(utilisateurs_.size());		//Faire de l'espace dans le vecteur
		for (unsigned int i = 0; i < utilisateurs_.size(); i++)
		{
			if (payePar->getNom() == utilisateurs_[i]->getNom()) {

				comptes_[i] = comptes_[i] + ptrDepenseGroupe->getMontant() - ptrDepenseGroupe->getMontantPersonnel();
			}
			for (unsigned int j = 0; j < payePour.size(); j++)
			{
				if (payePour[j]->getNom() == utilisateurs_[i]->getNom()) {
					comptes_[i] -= ptrDepenseGroupe->getMontantPersonnel();
				}
			}
		}

		//Ajoute la dépense au groupe
		depenses_.push_back(ptrDepenseGroupe);
	}
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	bool peutAjouterUtilisateur = false;
	//Verifier que si l'utilisateur est regulier, qu'il ne soit pas déjà dans un groupe
	if (utilisateur->getType() == Regulier)
	{
		if (static_cast<UtilisateurRegulier>(*utilisateur).estGroupe() == false) {
			peutAjouterUtilisateur == true;
		}
	}
	else
	{
		if (static_cast<UtilisateurPremium>(*utilisateur).getJoursRestants() > 0){
			peutAjouterUtilisateur = true;
		}
	}

	//Verifier que l'utilisateur n'est pas déjà dans ce groupe
	for (unsigned i = 0; i < utilisateurs_.size(); i++)
	{
		if (utilisateurs_[i]->getNom() == utilisateur->getNom()) {
			peutAjouterUtilisateur = false;
			cout << "ERREUR: Cet utilisateur est deja dans ce groupe." << endl;
		}
	}

	if (peutAjouterUtilisateur == false) {
		cout << "ERREUR: L'utilisateur " << utilisateur->getNom()
			<< " n'est pas souscrit a un abonnement Premium et il est deja dans un groupe." << endl;
	}
	else
	{
		utilisateurs_.push_back(utilisateur);
	}
	return *this;
}

void Groupe::calculerTotalDepense() {

	for (unsigned int i = 0; i < utilisateurs_.size(); i++)
	{
		utilisateurs_[i]->calculerTotalDepenses();
	}
	double total = 0;
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		total += depenses_[i]->getMontant();
	}
	totalDepenses_ = total;

}

void Groupe::equilibrerComptes() {
	
	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (int i = 0; i < utilisateurs_.size(); i++) {
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}

		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
	
		}
		else if (-min > max  && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
			

		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= utilisateurs_.size() - 1) {
			calcul = false;
		}
	}
	
}



// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	for (unsigned int i = 0; i < groupe.utilisateurs_.size(); i++)
	{
		groupe.utilisateurs_[i]->calculerTotalDepenses();
		os << *groupe.utilisateurs_[i] << endl;
	}
	os << endl << "Les transferts suivant ont ete fait pour equilibrer les comptes:" << endl;
	for (unsigned int i = 0; i < groupe.transferts_.size(); i++)
	{
		os << "    " << *groupe.transferts_[i] << endl;
	}
	os << endl << "Merci d'avoir utilise PolyCount!" << endl;
	return os;
}
