#pragma once

enum class Elem {
    RESS_NAT,
    MACHINE,
    GENERATEUR,
    CONVOYEUR,
    CONTENEUR,
    VIDE
};

enum class Ressource {
    aucun,         // Si rien
    noigrumes,      // Ressource naturelle
    fer,            // Ressource naturelle
    demi_capsule,   // Produit intermédiaire
    bouton,         // Produit intermédiaire
    pokeball        // Produit fini
};




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
    Ressource gisement;   // ressource naturelle sous la case, ou rien
    Elem type;                           // type de l'occupant (VIDE si aucun)
    ElementGrille* occupant;

public:
    Case();
    Case(int x, int y);                        // case sans gisement
    Case(int x, int y, Ressource gisement);    // case avec gisement
    Case(int X, int Y, ElementGrille* occ);

    int getX() const;
    int getY() const;
    Elem getType() const;
    ElementGrille* getOccupant() const;
    Elem getTypeElem() const;
    Ressource getGisement() const;     // à n'appeler que si aGisement() est vrai

    bool aGisement() const;

    void setX(int);
    void setY(int);
    void setType(Elem);
    void setGisement(Ressource);
    void setOccupant(ElementGrille* elem);   // déduit le type via elem->getTypeElem()
    
    void liberer();                          // occupant = nullptr, type = VIDE ; le gisement reste
    void print();
};