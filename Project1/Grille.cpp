#include <iostream>
#include "Grille.hpp"


using namespace std;



//========================================
//    Grille
//========================================


Grille::Grille() {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cases[x][y]();
		}
	}
}



void Grille::setLongueur(int x) {
	longueur = x;
}
void Grille::setLargeur(int y) {
	largeur = y;
}
void Grille::setCase(Case& c, int x, int y) {
	cases[x][y] = c;
}

int Grille::getLongueur() const {
	return longueur;
}
int Grille::getLargeur() const {
	return largeur;
}
const Case& Grille::getCase(int x, int y) const {
	return cases[x][y];
}