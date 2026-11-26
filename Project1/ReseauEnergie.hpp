#pragma once


class ReseauEnergie {
private:
    float productionDisponible;
    float consommationActuelle;

public:
    ReseauEnergie();

    void ajouterProduction(float quantite);
    bool consommer(float quantite);
    void reinitialiserCycle();

    float getProductionDisponible() const;
    float getConsommationActuelle() const;
};