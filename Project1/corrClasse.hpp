#pragma once
#include <string>
#include <map>
#include <vector>
#include <atomic>
#include <thread>


//========================================
//    Déclarations anticipées
//========================================

class Case;
class ReseauEnergie;


//========================================
//    Énumérations
//========================================

enum class Elem {
    RESS_NAT,
    MACHINE,
    GENERATEUR,
    CONVOYEUR,
    CONTENEUR,
    VIDE
};

enum class Ressource {
    noigrumes,      // Ressource naturelle
    fer,            // Ressource naturelle
    demi_capsule,   // Produit intermédiaire
    bouton,         // Produit intermédiaire
    pokéball        // Produit fini
};

enum class Direction {
    DROITE,
    BAS,
    GAUCHE,
    HAUT
};


//========================================
//    Position sur la carte
//========================================

// Classe mère abstraite de tout ce qui peut occuper une case
class ElementGrille {
public:
    virtual ~ElementGrille() = default;
    virtual Elem getTypeElem() const = 0;
};

class Case {
private:
    int x;
    int y;
    Elem type;
    ElementGrille* occupant;

public:
    Case();
    Case(int, int, Elem);
    Case(int, int);

    int getX() const;
    int getY() const;
    Elem getType() const;
    ElementGrille* getOccupant() const;

    void setX(int);
    void setY(int);
    void setType(Elem);
    void placerOccupant(ElementGrille* elem, Elem nouveauType);
    void liberer(); // Libère la case de son occupant et remet le type à VIDE
};

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


//========================================
//    Recettes
//========================================

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


//========================================
//    Énergie : réseau
//========================================

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


//========================================
//    Stockage et convoyeurs
//========================================

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


//========================================
//    Machines (transforment des ressources)
//========================================

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


//========================================
//    Énergie : générateurs (produisent de l'énergie)
//========================================

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