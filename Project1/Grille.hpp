#pragma once
#include <vector>
#include "Case.hpp"

class Grille {
private:
    int Largeur;
    int Longueur;
    std::vector<std::vector<Case>> cases;

public:
    Grille();
    Grille(int, int);

    void setLargeur(int);
    void setLongueur(int);
    int getLargeur() const;
    int getLongueur() const;

    Case& getCase(int x, int y);
    const Case& getCase(int x, int y) const;
    bool estDansGrille(int x, int y) const;
};