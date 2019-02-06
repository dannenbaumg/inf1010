/*
* Titre : Plat.h - Travail Pratique #1
* Date : 09 Janvier 2019
* Auteur : David Dratwa
*/

#ifndef PLAT_H
#define PLAT_H

#include <string>
#include <iostream>

using namespace std; 

class Plat {
public: 
	// constructeurs
	Plat(); 
	Plat(string nom, double prix, double cout);

	//getters 
	string getNom(); 
	double getPrix(); 
	double getCout(); 

	//setters 
	void setNom(string nom); 
	void setPrix(double prix); 
	void setCout(double cout);
	
	//affichage
	void afficher(); 

private: 
	string nom_; 
	double prix_; 
	double cout_; 

};

#endif // !PLAT_H
