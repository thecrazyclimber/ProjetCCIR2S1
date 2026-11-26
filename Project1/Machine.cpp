#include <iostream>
#include "Machine.hpp"
#include <string>
#include <atomic>
#include <thread>
#include "Case.hpp"
#include "Recette.hpp"
#include "ReseauEnergie.hpp"


//===============================
//          Machine
//===============================
Machine::Machine(std::string id, Case* pos, float conso,
    Recette recette, ReseauEnergie* reseau)
    : id(id),
    pos(pos),
    conso(conso),
    recette(recette),
    reseau(reseau),
    actif(false),
    entree(0),
    sortie(0)
{
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

//===============================
//		  Extracteur
//===============================

Extracteur::Extracteur(std::string id, Case* pos, float conso, Recette recette,
    ReseauEnergie* reseau, Ressource ressourceExtraite) : Machine(id, pos, conso, recette, reseau), ressourceExtraite(ressourceExtraite) {}

void Extracteur::produit() {
    // Implémentation spécifique pour l'extracteur
}

//===============================
//          Four
//===============================

Four::Four(std::string id, Case* pos, float conso, Recette recette, ReseauEnergie* reseau) : Machine(id, pos, conso, recette, reseau) {}

void Four::produit() {
    // Implémentation spécifique pour le four
}

//===============================
//          Assembleur
//===============================

Assembleur::Assembleur(std::string id, Case* pos, float conso, Recette recette, ReseauEnergie* reseau) : Machine(id, pos, conso, recette, reseau) {}

void Assembleur::produit() {
    // Implémentation spécifique pour l'assembleur
}