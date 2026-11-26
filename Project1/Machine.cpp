#include <iostream>
#include "Machine.hpp"
#include <string>
#include <atomic>
#include <thread>
#include "Case.hpp"
#include "Recette.hpp"
#include "ReseauEnergie.hpp"



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


Machine::Machine(std::string id, Case* pos, float conso, Recette recette, ReseauEnergie* reseau) {

}
Machine::~Machine() {}

Elem Machine::getTypeElem() const {
    return Elem::MACHINE;
}
const std::string& Machine::getId() const {
    return id;
}
Case* Machine::getPos() const {
    return pos;
}

bool Machine::peutProd() const {
    return true;

}
void Machine::consomme() {

}
void Machine::produit() { // Peut lever ProductionImpossibleException

}
void Machine::boucleProduction() {

}
void Machine::demarrer() {
}
void Machine::arreter() {
}