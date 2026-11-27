#pragma once
#include "Case.hpp"


class Grille {
private:
    static const int LARGEUR = 200;
    static const int LONGUEUR = 150;
    Case cases[LARGEUR][LONGUEUR];

public:
    Grille();

    void setLongueur(int);
    void setLargeur(int);
    void setCase(Case&, int, int);

    int getLongueur() const;
    int getLargeur() const;
    const Case& getCase(int x, int y) const;

    void print();
};