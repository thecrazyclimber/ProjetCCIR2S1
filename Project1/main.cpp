#include <iostream>
#include "Grille.hpp"

using namespace std;

int main() {
    Grille grille;
    for (int x = 0; x < LARGEUR; x++) {
        for (int y = 0; y < LONGUEUR; y++) {
            grille.getCase(x, y).setType(Elem::CONTENEUR);
        }
    }
    grille.print();
}