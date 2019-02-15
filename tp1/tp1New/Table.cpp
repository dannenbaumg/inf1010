/*
* Titre : Table.cpp - Travail Pratique #1
* Date : 25 Janvier 2019
* Auteurs : Gabriel Dannenbaum Lucas Tassaux
*/
#include "Table.h";
#include "Plat.h"
// constructeurs

Table::Table() {
	capacite_ = MAXCAP;
	id_ = -1;
	nbPlaces_ = 1;
	occupee_ = false;
	commande_ = new Plat*[MAXCAP];
}

Table::Table(int id, int nbPlaces) {
	capacite_ = MAXCAP;
	id_ = id;
	nbPlaces_ = nbPlaces;
	occupee_ = false;
	commande_ = new Plat*[MAXCAP];

}

//getters 
int Table::getId() {
	return id_;
}
int  Table:: getNbPlaces() {
	return nbPlaces_;
}
bool  Table::estOccupee() {
	return occupee_;
}

//setters 
void  Table::setId(int id) {
	id_ = id;
}

void  Table::libererTable() {
	occupee_ = false;
	if (nbPlats_ > 0) {
		delete[] commande_;
	}
	commande_ = nullptr;
	nbPlats_ = 0;
}

void Table::tableOccuper() {
	occupee_ = true;
}


//autres methodes 
//ajouter un plat a une commande
void Table ::commander(Plat* plat) {
	if(nbPlats_ <= capacite_ && estOccupee())
		commande_[nbPlats_++] = plat;
}
//Calculer le chiffre d'affaire d'une table
double Table::getChiffreAffaire() {
	double profit = 0;

	for (int i = 0; i < nbPlats_; i++) {

		profit += (commande_[i]->getPrix() - commande_[i]->getCout());

	}
	return profit;
}



//affichage
void Table::afficher() {
	cout << "La table numero " << getId() << "est : ";
	if (estOccupee()) {
		cout << "occuper.  Voici la commande passer par les clients: " << endl;
	}
	else {
		cout << "est libre. " << endl;
	}

	for (int i = 0; i < nbPlats_; i++) {

		commande_[i]->afficher(); 
	}
	
}

Table :: ~Table() {
	delete[] commande_;
}