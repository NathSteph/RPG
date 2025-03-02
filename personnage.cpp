#include "personnage.hpp"
#include <cstdlib>

Personnage::Personnage(std::string nom, int pv, int atk, int def)
    : nom(nom), PV(pv), attaque(atk), defense(def) {}

Personnage::~Personnage() {
    for (auto obj : inventaire) {
        if (obj != nullptr) {
            delete obj;
        }
    }
}

std::string Personnage::getNom() const {
    return this->nom;
}

std::string Personnage::getType() const {
    return this->type;
}

std::vector<Objet*> Personnage::getInventaire() const {
    return this->inventaire;
}

void Personnage::attaquer(Personnage& cible) {
    int degats = (rand() % this->attaque) - cible.getDefense();
    if (degats < 0) degats = 0; // Les dégâts ne peuvent pas être négatifs

    cible.recevoirDegats(degats); // Réduit directement les PV

    if(this->getType() == "JOUEUR") {
        std::cout << "🎯 Vous attaquez " << cible.getNom() << " et infligez " 
              << degats << " points de dégâts.\n";
    } else {
        std::cout << "👿 " << this->nom << " attaque et inflige " 
              << degats << " points de dégâts à " << cible.getNom() << ".\n";
    }

    if (cible.getPointsDeVie() <= 0) {
        if(this->getType() == "JOUEUR") {
            std::cout << "💀 Vous avez vaincu " << cible.getNom() << " !\n";
        } else {
            std::cout << "💀 " << cible.getNom() << " est vaincu !\n";
        }
    }

    cible.afficherInfos();
    std::cout << "\n";
}

void Personnage::ajouterObjet(Objet* objet) {
    if(this->getType() == "JOUEUR") {
        if (this->inventaire.size() < 10) {
            this->inventaire.push_back(objet);
            std::cout << "✔️ Vous ajoutez " << objet->getNom() << " à votre inventaire !\n\n";
            this->afficherInventaire();
        } else {
            std::cout << "❌ Inventaire plein ! Vous ne pouvez pas ajouter plus de 10 objets.\n";
            delete objet; // Libère la mémoire si l'objet ne peut pas être ajouté
        }
    } else {
        if (this->inventaire.size() < 10) {
            this->inventaire.push_back(objet);
        } else {
            std::cout << "❌ Inventaire plein !\n";
            delete objet; // Libère la mémoire si l'objet ne peut pas être ajouté
        }
    }
}

void Personnage::afficherInventaire() const {
    std::cout << "🎒 Inventaire de " << this->getNom() << " :\n";
    for (size_t i = 0; i < this->inventaire.size(); i++) {
        if (this->inventaire[i] != nullptr) {
            std::cout << i + 1 << ". " << this->inventaire[i]->getNom() << " (" << this->inventaire[i]->getType() << ")\n";
        }
    }
}

void Personnage::recevoirDegats(int degats) {
    this->PV -= degats;
    if (this->PV < 0) this->PV = 0;
}

void Personnage::afficherInfos() const {
    if(this->getType() == "JOUEUR") {
        std::cout << "👤 Joueur : " << this->getNom() << " | PV: " << this->getPointsDeVie()
              << " | ATK: " << this->getAttaque() << " | DEF: " << this->getDefense() << std::endl;
    } else {
        std::cout << "👿 Ennemi : " << this->getNom() << " | PV: " << this->getPointsDeVie()
              << " | ATK: " << this->getAttaque() << " | DEF: " << this->getDefense() << std::endl;
    }
}

void Personnage::setNom(std::string nom) {
    this->nom = nom;
}

void Personnage::setPointsDeVie(int pointsDeVie) {
    this->PV = pointsDeVie;
}

void Personnage::setAttaque(int attaque) {
    this->attaque = attaque;
}

void Personnage::setDefense(int defense) {
    this->defense = defense;
}

void Personnage::setInventaire(std::vector<Objet*> inventaire) {
    this->inventaire = inventaire;
}

int Personnage::getPointsDeVie() const {
    return this->PV;
}

int Personnage::getAttaque() const {
    return this->attaque;
}

int Personnage::getDefense() const {
    return this->defense;
}

bool Personnage::estVivant() const {
    return this->PV > 0;
}

