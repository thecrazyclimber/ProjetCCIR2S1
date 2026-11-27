#include <iostream>
#include "Grille.hpp"


using namespace std;



//========================================
//    Grille
//========================================


Grille::Grille() {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cases[i][j]();
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

void Grille::print() {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {

			if (cases[i][j].getType() == RESS_NAT) {
				cout << "*" << ;
			}
			else if (cases[i][j].getType() == MACHINE) {
				cout << "M" << ;
			}
			else if (cases[i][j].getType() == GENERATEUR) {
				cout << "G" << ;
			}
			else if (cases[i][j].getType() == CONVOYEUR) {
				cout << "=" << ;
			}
			else if (cases[i][j].getType() == CONTENEUR) {
				cout << "#" << ;
			}
			else if (cases[i][j].getType() == VIDE) {
				cout << " " << ;
			}
			else {
				cout << "?" << ;
			}
		}
		cout << endl;
	}
}