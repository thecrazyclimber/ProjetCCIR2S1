#pragma once
#include <vector>
#include "Case.hpp"

class Grille {
private:
    std::vector<std::vector<Case>> cases;

public:
    Grille();
    Grille(int, int);

    Case& getCase(int x, int y);
    const Case& getCase(int x, int y) const;
    bool estDansGrille(int x, int y) const;
};