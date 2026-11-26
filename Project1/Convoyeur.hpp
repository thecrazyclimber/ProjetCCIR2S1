#pragma once
#include "Case.hpp"

enum class Direction {
    DROITE,
    BAS,
    GAUCHE,
    HAUT
};

class Convoyeur : public ElementGrille {
private:
    Case* entree;
    Case* sortie;
    Direction direction;
    Ressource ressourceEnTransit;
    bool occupe;

public:
    Convoyeur();
    Convoyeur(Case* entree, Case* sortie, Direction direction);

    Elem getTypeElem() const override;
    Case* getEntree() const;
    Case* getSortie() const;
    Direction getDirection() const;

    void setEntree(Case*);
    void setSortie(Case*);
    void setDirection(Direction);

    bool transferer();
};