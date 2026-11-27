#include <iostream>
#include "Grille.hpp"


using namespace std;



//========================================
//    Grille
//========================================


Grille::Grille() {
	for (int x = 0; x < LARGEUR; x++) {
		for (int y = 0; y < LONGUEUR; y++) {
			cases[x][y].setX(x);
			cases[x][y].setY(y);
		}
	}
}

void Grille::setCase(Case& c, int x, int y) {
	cases[x][y] = c;
}

int Grille::getLongueur() const {
	return LONGUEUR;
}
int Grille::getLargeur() const {
	return LARGEUR;
}
Case& Grille::getCase(int x, int y) {
	return cases[x][y];
}

void Grille::print() {
	for (int y = 0; y < LONGUEUR; y++) {        // une ligne de l'écran = un y
		for (int x = 0; x < LARGEUR; x++) {
			cases[x][y].print();
		}
		cout << endl;
	}
}