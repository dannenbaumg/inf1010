/*
* Titre : Restaurant.cpp - Travail Pratique #1
* Date : 25 Janvier 2019
* Auteurs : Gabriel Dannenbaum Lucas Tassaux
*/
#include "Restaurant.h";
#include "Table.h";
#include "Menu.h";
#include <limits>;
//constructeurs

Restaurant::Restaurant() {
	nom_ = nullptr;
	chiffreAffaire_ = 0;
	momentJournee_ = Matin;
	menuMatin_ = new Menu;
	menuMidi_ = new Menu;
	menuSoir_ = new Menu;
	capaciteTables_ = 0;
	tables_ = new Table*[nbTables_];
	nbTables_ = 0;

}

Restaurant::Restaurant(string& fichier, string& nom, TypeMenu moment) {
	nom_ = &nom;
	chiffreAffaire_ = 0;
	momentJournee_ = moment;
	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_ = new Menu(fichier, Midi);
	menuSoir_ = new Menu (fichier, Soir);

	capaciteTables_ = 0;
	tables_ = new Table*[nbTables_];
	nbTables_ = 0;
}

//setters 
void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment;
};

	//getters 
string Restaurant::getNom() {
	return *nom_;
};
TypeMenu Restaurant::getMoment() {
	return momentJournee_;
};

	//Autres methodes 
void Restaurant::ajouterTable(int id, int nbPlaces) {
	
	tables_[nbTables_ ++] = new Table(id, nbPlaces);
	
}
//Lire l'id et le nombre de place d'une table a partir d'un fichier texte
void Restaurant::lireTable(string& fichier) {
	ifstream fichierO("polyFood.txt");
	string tempString;
	int id;
	int nbPlaces;
	
	while (!fichierO.eof()) {
		getline(fichierO, tempString);
		if (tempString == "-TABLES") {
			while (!fichierO.eof()){
				fichierO >> id >> ws >> nbPlaces >> ws;
				ajouterTable(id, nbPlaces);
				
			}
			

		}
	}
	fichierO.close();
}
	
void Restaurant ::libererTable(int id) {
	
	if (id <= nbTables_) {
		chiffreAffaire_ += tables_[id - 1]->getChiffreAffaire();
		tables_[id - 1]->libererTable();
	}

	
}
//commander un plat en fonction du moment de la journee
void Restaurant::commanderPlat(string& nom, int idTable) {
	
	switch (momentJournee_) {
		case (Matin):
			tables_[idTable-1]->commander(menuMatin_->trouverPlat(nom));
		break;
		case (Midi):
			tables_[idTable - 1]->commander(menuMidi_->trouverPlat(nom));;
		break;
		case (Soir):
			tables_[idTable - 1]->commander(menuSoir_->trouverPlat(nom));
		break;
	}

}
	//Trouver une table la plus petite possible pouvant acceuillir le nombre de clients en parametre
void Restaurant::placerClients(int nbClients) {
	int nbPlacesMin = std::numeric_limits<int>::max();
	
	int id = 0;

	for (int i = 0; i < nbTables_; i++) {
		if (tables_[i]->estOccupee() == false && tables_[i]->getNbPlaces() >= nbClients && tables_[i]->getNbPlaces() < nbPlacesMin) {
			id = tables_[i]->getId();
			nbPlacesMin = tables_[i]->getNbPlaces();
		}
	
	}
	if (id == 0) {
		cout << " Il n'a pas de table disponible!" <<endl;
	}
	else
	{
		tables_[id - 1]->tableOccuper();
	}
}

//affichage 
void Restaurant::afficher() {

	cout << "Chiffres d'affaires : " << chiffreAffaire_ << "$" << endl;;
	cout << "Voici les tables: " << endl;

	for (int i = 0; i < nbTables_; i++) {
		tables_[i]->afficher();
		cout << endl;
	}
	
	cout << "Voici son menu:  " << endl;
	menuMatin_->afficher();
	menuMidi_->afficher();
	menuSoir_->afficher();
}

Restaurant :: ~Restaurant() {
	delete menuMatin_;
	delete menuMidi_;
	delete menuSoir_;
	delete[]tables_;
}
