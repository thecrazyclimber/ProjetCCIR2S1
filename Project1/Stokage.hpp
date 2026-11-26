#pragma once
#include "Case.hpp"

class Stockage : public ElementGrille {
private:
    Ressource typeRessource;
    int taille;
    int stockage;

public:
    Stockage(Ressource type, int capaciteMax, int initial = 0);

    Elem getTypeElem() const override;
    Ressource getTypeRessource() const;
    int getTaille() const;
    int getStockage() const;

    bool ajouter(Ressource res, int quantite);
    bool retirer(Ressource res, int quantite);
};
