#include "Plat.h";

//constructeurs

Plat ::Plat () {
	nom_ = nullptr;
	prix_ = 0;
	cout_ = 0;
}

Plat::Plat(string nom, double prix, double cout) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}

string Plat::getNom() {
	return nom_;
}

double Plat::getPrix() {
	return prix_;
}

double Plat::getCout() {
	return cout_;
}


//setters 
void Plat::setNom(string nom) {
	nom_ = nom;
}

void Plat :: setPrix(double prix) {
	prix_ = prix;
}
void Plat::setCout(double cout) {
	cout_ = cout;
}

//affichage
void Plat::afficher() {
	cout << getNom() << "-" << getPrix() << "$" << "(" << getCout() << "$ pour le restaurant)" << endl;
}
