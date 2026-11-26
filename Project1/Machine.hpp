#pragma once
#include <string>
#include <atomic>
#include <thread>
#include "Case.hpp"
#include "Recette.hpp"
#include "ReseauEnergie.hpp"

class Machine : public ElementGrille {
protected:
    std::string id;
    Case* pos;
    float conso;
    Recette recette;
    ReseauEnergie* reseau;
    std::atomic<bool> actif;
    std::thread worker;

    int entree;
    int sortie;

public:
    Machine(std::string id, Case* pos, float conso, Recette recette, ReseauEnergie* reseau);
    ~Machine() override;

    Elem getTypeElem() const override;
    const std::string& getId() const;
    Case* getPos() const;

    virtual bool peutProd() const;
    virtual void consomme();
    virtual void produit(); // Peut lever ProductionImpossibleException
    virtual void boucleProduction();

    void demarrer();
    void arreter();
};

class Extracteur : public Machine {
private:
    Ressource ressourceExtraite; // Ressource naturelle infinie

public:
    Extracteur(std::string id, Case* pos, float conso, Recette recette,
        ReseauEnergie* reseau, Ressource ressourceExtraite);
    void produit() override;
};

class Four : public Machine {
public:
    Four(std::string id, Case* pos, float conso, Recette recette, ReseauEnergie* reseau);
    void produit() override;
};

class Assembleur : public Machine {
public:
    Assembleur(std::string id, Case* pos, float conso, Recette recette, ReseauEnergie* reseau);
    void produit() override;
};