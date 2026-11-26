#pragma once
#include "Case.hpp"
#include "ReseauEnergie.hpp"
#include <string>

// Classe mère abstraite de tous les moyens de production d'énergie
class Generateur : public ElementGrille {
protected:
    std::string id;
    Case* pos;
    ReseauEnergie* reseau;
    float productionNominale;

public:
    Generateur(std::string id, Case* pos, ReseauEnergie* reseau, float productionNominale);

    Elem getTypeElem() const override; // Renvoie Elem::GENERATEUR
    const std::string& getId() const;
    Case* getPos() const;

    virtual float calculerProduction() const = 0;
    void produire(); // Ajoute calculerProduction() au ReseauEnergie
};




class Solaire : public Generateur {
private:
    float rendementMeteo; // Ex. : météo ou moment de la journée

public:
    Solaire(std::string id, Case* pos, ReseauEnergie* reseau,
        float productionNominale, float rendementMeteo = 1.0f);

    void setRendementMeteo(float rendement);
    float calculerProduction() const override; // productionNominale * rendementMeteo
};




class Eolienne : public Generateur {
private:
    float rendementMeteo; // Ex. : météo ou moment de la journée

public:
    Eolienne(std::string id, Case* pos, ReseauEnergie* reseau,
        float productionNominale, float rendementMeteo = 1.0f);

    void setRendementMeteo(float rendement);
    float calculerProduction() const override; // productionNominale * rendementMeteo
};