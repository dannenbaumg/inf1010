/*
* Titre : main.cpp - Travail Pratique #1
* Date : 09 Janvier 2019 
* Auteur : Gabriel Dannenbaum Lucas Tassaux
*/

#include "Restaurant.h"

using namespace std; 

int main() {

	//creation du restaurant - avec le fichier donne - le nom : PolyFood - moment de la journee : soir. 
	string fichier = "polyFood.txt";
	string nom = "poly";
	Restaurant poly(fichier,nom,Soir);

	//creer plusieurs clients -- des entiers 

	int client1 = 1; 
	int client2 = 5; 
	int client3 = 15; 
	int client4 = 3; 
	int client5 = 2; 

	poly.lireTable(fichier);

	//placer les clients 
	poly.placerClients(client1);
	poly.placerClients(client2);
	poly.placerClients(client3);
	poly.placerClients(client4);
	poly.placerClients(client5);

	// commander des plats
	string Poisson = "Poisson";
	string Poulet = "Poulet";
	string Pizza = "Pizza";
	string Muffin = "Muffin";
	string Oeuf = "Oeuf";

	//Poisson - Table 1
	poly.commanderPlat(Poisson, 1);
	//Poulet - Table 2 
	poly.commanderPlat(Poulet, 2);
	//Pizza - Table 2 
	poly.commanderPlat(Pizza, 2);
	//Poulet - Table 4
	poly.commanderPlat(Poulet, 4);
	//Muffin - Table 4 
	poly.commanderPlat(Muffin, 4);
	//Oeuf - Table 4 
	//poly.commanderPlat(Oeuf, 4);
	

	//afficher le restaurant
	poly.afficher(); 

	cout << "-------------------------------------------------" << endl; 

	//liberer les tables 
	poly.libererTable(1);
	poly.libererTable(2);
	poly.libererTable(3);
	poly.libererTable(4);
	poly.libererTable(5);

	//afficher le restaurant 
	poly.afficher(); 
	system("pause");
	return 0;

}