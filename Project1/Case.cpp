#include <iostream>
#include "Case.hpp"

using namespace std;




//========================================
//    Case
//========================================


Case::Case() {
    setX(0);
    setY(0);
    setOccupant(nullptr);
    setGisement(Ressource::aucun);
}
Case::Case(int X, int Y, Ressource res) {
    setX(X);
    setY(Y);
    setOccupant(nullptr);
    setGisement(res);
}
Case::Case(int X, int Y, ElementGrille* occ) {
    setX(X);
    setY(Y);
    setOccupant(occ);
    setGisement(Ressource::aucun);
}
Case::Case(int X, int Y) {
    setX(X);
    setY(Y);
    setOccupant(nullptr);
    setGisement(Ressource::aucun);
}


int Case::getX() const {
    return x;
}
int Case::getY() const {
    return y;
}
ElementGrille* Case::getOccupant() const {
    return occupant;
}
Elem Case::getTypeElem() const {
    return type;
}
Ressource Case::getGisement() const {
    return gisement;
}


bool Case::aGisement() const {
    if (gisement == Ressource::aucun) {
        return false;
    }
    else {
        return true;
    }
}



void Case::setX(int X) {
    x = X;
}
void Case::setY(int Y) {
    y = Y;
}
void Case::setType(Elem e) {
    type = e;
}
void Case::setGisement(Ressource res) {
    gisement = res;
}
void Case::setOccupant(ElementGrille* elem) {
    occupant = elem;
    if (elem != nullptr) {
        type = elem->getTypeElem();
    }
    else {
        type = Elem::VIDE;
    }
}



void Case::liberer() {
    setOccupant(nullptr);
    setType(Elem::VIDE);   
}