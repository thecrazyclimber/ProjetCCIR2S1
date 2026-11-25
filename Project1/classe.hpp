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

class Case {
private:
    int x;
    int y;
    std::string type;

public:
    Case();
    Case(int, int, std::string);
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


class Convoyeur {

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