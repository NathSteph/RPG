#include "joueur.hpp"
#include "objet.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>

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

void Joueur::afficherEquipement() const {
    std::cout << "🛡️ Équipement actuel de " << nom << " :\n";
    std::cout << "- Arme : " << (armeEquipee ? armeEquipee->getNom() : "Aucune") << "\n";
    std::cout << "- Armure : " << (armureEquipee ? armureEquipee->getNom() : "Aucune") << "\n";
}

void Joueur::equiperObjet() {
    std::cout << "🎒 Choisissez un objet à équiper :\n";
    
    int index = 1;
    std::vector<Objet*> choix;

    for (auto& objet : inventaire) {
        if (objet->getType() == "ARME" || objet->getType() == "ARMURE") {
            std::cout << index << ". " << objet->getNom() << " (" << objet->getType() << ")\n";
            choix.push_back(objet);
            index++;
        }
    }

    if (choix.empty()) {
        std::cout << "❌ Vous n'avez ni arme ni armure dans votre inventaire.\n";
        return;
    }

    int selection;
    std::cout << "👉 Entrez le numéro de l'objet à équiper (0 pour annuler) : ";
    std::cin >> selection;

    if (selection > 0 && selection <= (int)choix.size()) {
        Objet* objetChoisi = choix[selection - 1];

        if (objetChoisi->getType() == "ARME") {
            if (armeEquipee) {
                std::cout << "❌ Vous retirez " << armeEquipee->getNom() << ".\n";
                attaque -= armeEquipee->getPuissance(); //
                inventaire.push_back(armeEquipee);
                armeEquipee = nullptr;
            }
            armeEquipee = dynamic_cast<Arme*>(objetChoisi);
            attaque += armeEquipee->getPuissance(); // Augmentation fictive (ajuste selon l'arme)
            std::cout << "⚔️ Vous équipez " << armeEquipee->getNom() << " (+" << armeEquipee->getPuissance() << " attaque) !\n";
        } 
        else if (objetChoisi->getType() == "ARMURE") {
            if (armureEquipee) {
                std::cout << "❌ Vous retirez " << armureEquipee->getNom() << ".\n";
                defense -= armureEquipee->getDefense(); //
                inventaire.push_back(armureEquipee);
                armureEquipee = nullptr;
            }
            armureEquipee = dynamic_cast<Armure*>(objetChoisi);
            defense += armureEquipee->getDefense(); // Augmentation fictive (ajuste selon l’armure)
            std::cout << "🛡️ Vous équipez " << armureEquipee->getNom() << " (+" << armureEquipee->getDefense() << " défense) !\n";
        }

        // Retirer l'objet de l'inventaire
        inventaire.erase(std::remove(inventaire.begin(), inventaire.end(), objetChoisi), inventaire.end());
    } 
    else {
        std::cout << "❌ Annulation.\n";
    }
}

/*void Joueur::retirerObjet(Objet* objetChoisi) {
    auto it = std::remove_if(inventaire.begin(), inventaire.end(),
        [objetChoisi](Objet* obj) { return obj == objetChoisi; });

    if (it != inventaire.end()) {
        delete *it;  // Libérer la mémoire si nécessaire
        inventaire.erase(it, inventaire.end());
        std::cout << "🗑 Objet retiré de l'inventaire !\n";
    } else {
        std::cout << "⚠️ Objet introuvable dans l'inventaire.\n";
    }
}*/



int Joueur::getPointsDeVie() {
    return this->pointsDeVie;
}

int Joueur::getAttaque() const{
    return this->attaque;
}

int Joueur::getDefense() const{
    return this->defense;
}



