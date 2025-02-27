#include "personnage.hpp"
#include <cstdlib>

Personnage::Personnage(std::string nom, int pv, int atk, int def)
    : nom(nom), PV(pv), attaque(atk), defense(def) {}

Personnage::~Personnage() {
    for (auto obj : inventaire) delete obj;
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

bool Personnage::estVivant() const {
    return PV > 0;
}

/*bool Personnage::ajouterObjet(Objet* objet) {
    if (inventaire.size() < 10) {
        inventaire.push_back(objet);
        return true;
    }
    return false;
}*/

void Personnage::afficherInventaire() const {
    std::cout << nom << " possède :\n";
    for (auto obj : inventaire)
        std::cout << "- " << obj->getNom() << "\n";
}
