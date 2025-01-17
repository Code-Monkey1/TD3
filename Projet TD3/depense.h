/********************************************
* Titre: Travail pratique #3 - depense.h
* Date : 22 octobre 2018
* Auteurs: Raphael Geoffrion et Jules Lefebvre
*******************************************/

#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>



using namespace std;

enum TypeDepense {groupe, individuelle};

class Depense {
public:
	// Constructeurs

	Depense(const string& nom = "", double montant = 0 , const string& lieu = "Montreal", TypeDepense typeDepense = individuelle);
	Depense(const Depense& depense);
	
	// Destructeur 
	~Depense();

	// Methodes d'acces
	string getNom() const;
	double getMontant() const;
	string* getLieu() const;
	TypeDepense getType() const; 

	// Methodes de modifications
	void setNom(const string& nom);
	void setMontant(double montant);
	void setLieu(const string& lieu);
	void setType(TypeDepense type); 
	
	//operateurs
	Depense& operator=(const Depense& depense);

	// Affichage
	friend ostream& operator<<(ostream& os, const Depense& depense);
private:
	string nom_;
	double montant_;
	string* lieu_;
	TypeDepense type_; 

};
#endif