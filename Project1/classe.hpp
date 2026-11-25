#pragma once
#include <string>



//========================================
//    Position sur map
//========================================

class Grille {
private:
    int x;
    int y;

public:
    Grille();
    Grille(int, int);
    Grille(std::string);
    void setX(int);
    void setY(int);
    int getX() const;
    int getY() const;
};

enum class Elem {
    RESS_NAT,
    MACHINE,
    CONVOYEUR,
    CONTENEUR,
    VIDE
};

class Case {
private:
    int x;
    int y;
    Elem type;

public:
    Case();
    Case(int, int, Elem);
    Case(int, int);
};



//========================================
//    Ressources et Recettes
//========================================


class Recette {
private:
    std::string nom;
    std::string id;

};

enum class Ressource {
    noigrumes,
    fer
};



//========================================
//    Stockage et Convoyeur
//========================================

enum class Side {
    DROITE = 1,
    BAS = 2,
    GAUCHE = 3,
    HAUT = 4
};

enum class Sens {
    DROITE = 1,
    BAS = 2,
    GAUCHE = 3,
    HAUT = 4
};

class Convoyeur {
private:
    Case entree;
    Case sortie;
    Sens sens;

public:
    Convoyeur();
    Convoyeur(Case, Case, Sens);

    Case getEntree();
    Case getSortie();
    Sens getSens();
    void setEntree(Case);
    void setSortie(Case);
    void setSens(Sens);
};

class Stockage {
private:
    std::string typeRessource;
    int taille;
    int stockage;
};



//========================================
//    Machines
//========================================


class Machine {
private:
    std::string id;
    Case pos;
    float conso;
    int entree;
    int sortie;

public:
    Machine(std::string);
    void produit();
    void consomme();
    bool peutProd();
};

class Assembleur {

};

class Extracteur {

};

class Four {

};




//========================================
//    Prod énergie
//========================================


class Solaire {

};