#include "personnage.hpp"
#include <cstdlib>

Personnage::Personnage(std::string nom, int pv, int atk, int def)
    : nom(nom), PV(pv), attaque(atk), defense(def) {}

Personnage::~Personnage() {
    for (auto obj : inventaire) delete obj;
}

std::string Personnage::getNom() const {
    return nom;
}

void Personnage::attaquer(Personnage& cible) {
    int degats = (rand() % attaque) - cible.defense;
    if (degats < 0) degats = 0;
    cible.recevoirDegats(degats);
    std::cout << nom << " attaque " << cible.getNom() << " et inflige " << degats << " dégâts.\n";
}

void Personnage::recevoirDegats(int degats) {
    PV -= degats;
    if (PV < 0) PV = 0;
}

void Personnage::afficherInventaire() const {
    std::cout << nom << " possède :\n";
    for (auto obj : inventaire)
        std::cout << "- " << obj->getNom() << "\n";
}

int Personnage::getPV() const {
    return PV;
}

int Personnage::getAttaque() const {
    return attaque;
}

int Personnage::getDefense() const {
    return defense;
}

bool Personnage::estVivant() const {
    return PV > 0;
}