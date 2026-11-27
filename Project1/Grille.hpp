#pragma once
#include "Case.hpp"

#define LARGEUR 50
#define LONGUEUR 30

class Grille {
private:
    Case cases[LARGEUR][LONGUEUR];

public:
    Grille();

    void setCase(Case&, int, int);

    int getLongueur() const;
    int getLargeur() const;
    Case& getCase(int x, int y);
    const Case& getCase(int x, int y) const;

    void print();
};