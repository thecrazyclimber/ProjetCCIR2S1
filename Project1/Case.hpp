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
    noigrumes,      // Ressource naturelle
    fer,            // Ressource naturelle
    demi_capsule,   // Produit intermédiaire
    bouton,         // Produit intermédiaire
    pokéball        // Produit fini
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