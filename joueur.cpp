#include "joueur.hpp"
#include "objet.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

Joueur::Joueur(std::string nom, int pv, int atk, int def) : Personnage(nom, pv, atk, def) {}

Joueur::~Joueur() {
    // Libérer la mémoire des objets de l'inventaire
    for (auto objet : inventaire) {
        delete objet;
    }
    inventaire.clear();
    if (armeEquipee) delete armeEquipee;
    if (armureEquipee) delete armureEquipee;

}

std::string Joueur::getNom() const{
    return this->nom;
}

std::vector<Objet*> Joueur::getInventaire() const{
    return this->inventaire;
}

void Joueur::afficherInventaire() const {
    cout << "🎒 Inventaire de " << nom << " :\n";
    for (const auto& objet : inventaire) {
        cout << "- " << objet->getNom() << " (" << objet->getType() << ")\n";
    }
}

void Joueur::attaquer(Personnage& cible) {
    int degats = (rand() % this->attaque) - cible.getDefense();
    if (degats < 0) degats = 0; // Les dégâts ne peuvent pas être négatifs

    cible.recevoirDegats(degats); // Réduit directement les PV

    std::cout << "🎯 Vous attaquez " << cible.getNom() << " et infligez " 
              << degats << " points de dégâts.\n";

    if (cible.getPV() <= 0) {
        std::cout << "💀 " << cible.getNom() << " est vaincu !\n";
    }

    //this->afficherInfos();
}

void Joueur::utiliserPotion() {
    for (auto it = inventaire.begin(); it != inventaire.end(); ++it) {
        if ((*it)->getType() == "POTION") {
            std::cout << "💖 Vous utilisez une " << (*it)->getNom() << " et récupérez 50 PV !\n";
            pointsDeVie += 50; // La potion restaure 50 PV (ajuste cette valeur si nécessaire)
            delete *it; // Libère la mémoire de l'objet
            inventaire.erase(it); // Supprime la potion de l’inventaire
            return;
        }
    }
}

void Joueur::ajouterObjet(Objet* objet) {
    if (inventaire.size() < 10) {
        inventaire.push_back(objet);
        std::cout << "✔️ Vous ajoutez " << objet->getNom() << " à votre inventaire !\n";
    } else {
        std::cout << "❌ Inventaire plein ! Vous ne pouvez pas ajouter plus de 10 objets.\n";
        delete objet; // Libère la mémoire si l'objet ne peut pas être ajouté
    }
    this->afficherInventaire();
}

void Joueur::setNom() {
    cout << "👤 Choisissez un nom pour votre personnage : ";
    cin >> this->nom;
}

void Joueur::setNom(std::string nom) {
    this->nom = nom;
}

void Joueur::setPointsDeVie(int pointsDeVie) {
    this->pointsDeVie = pointsDeVie;
}

void Joueur::setAttaque(int attaque) {
    this->attaque = attaque;
}

void Joueur::setDefense(int defense) {
    this->defense = defense;
}

void Joueur::setInventaire(std::vector<Objet*> inventaire) {
    this->inventaire = inventaire;
}

// Afficher les infos du joueur
void Joueur::afficherInfos() const {
    std::cout << "Joueur : " << nom << " | PV: " << pointsDeVie 
              << " | ATK: " << attaque << " | DEF: " << defense << std::endl;
}

int Joueur::getPointsDeVie() {
    return this->pointsDeVie;
}

int Joueur::getAttaque() const{
    return this->attaque;
}

int Joueur::getDefense() const{
    return this->defense;
}



