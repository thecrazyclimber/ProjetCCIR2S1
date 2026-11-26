#pragma once
#include <string>
#include <map>
#include "Case.hpp"

class Recette {
private:
    std::string id;
    std::string nom;
    std::map<Ressource, int> entrees;
    Ressource sortie;
    int quantiteSortie;
    float energieRequise;

public:
    Recette() = default;
    Recette(std::string id, std::string nom,
        std::map<Ressource, int> entrees,
        Ressource sortie, int quantiteSortie,
        float energieRequise = 0.0f);

    const std::string& getId() const;
    const std::string& getNom() const;
    const std::map<Ressource, int>& getEntrees() const;
    Ressource getSortie() const;
    int getQuantiteSortie() const;
    float getEnergieRequise() const;
};