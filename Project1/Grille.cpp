#include <iostream>
#include "Grille.hpp"


using namespace std;



//========================================
//    Grille
//========================================


Grille::Grille() {
	for (int i = 0; i < LONGUEUR; i++) {
		for (int j = 0; j < LARGEUR; j++) {
			cases[i][j].setX(i);
			cases[i][j].setY(j);
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
const Case& Grille::getCase(int x, int y) const {
	return cases[x][y];
}

void Grille::print() {
	for (int i = 0; i < LONGUEUR; i++) {
		for (int j = 0; j < LARGEUR; j++) {
			cases[i][j].print();
		}
		cout << endl;
	}
}