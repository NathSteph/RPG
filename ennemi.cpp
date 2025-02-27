#include "ennemi.hpp"
#include "joueur.hpp"
#include <cstdlib>
#include <iostream>
#include "potion.hpp"
#include "arme.hpp"
#include "armure.hpp"

// Constructeur de l'ennemi
Ennemi::Ennemi(std::string nom, int pv, int atk, int def) 
    : Personnage(nom, pv, atk, def) {
        initLot();
    }

// Afficher les infos de l'ennemi
void Ennemi::afficherInfos() const {
    std::cout << "Ennemi : " << nom << " | PV: " << PV 
              << " | ATK: " << attaque << " | DEF: " << defense << std::endl;
}

// Initialiser le lot d'objets de l'ennemi
void Ennemi::initLot() {
    std::string nom;
    // Initialisation du lot d'objets
    std::vector<std::string> nomsPotions = {"Potion de soin", "Potion de force", "Potion de défense"};
    nom = nomsPotions[rand() % nomsPotions.size()];
    ajouterObjet(new Potion(nom));

    std::vector<std::string> nomsArmes = {"Épée rouillée", "Dague ébréchée", "Arc en bois"};
    nom = nomsArmes[rand() % nomsArmes.size()];
    ajouterObjet(new Arme(nom, rand() % 10 + 5));

    std::vector<std::string> nomsArmures = {"Tunique en cuir", "Plastron en fer", "Casque en acier"};
    nom = nomsArmures[rand() % nomsArmures.size()];
    ajouterObjet(new Armure(nom, rand() % 5 + 2));
}

// Ajouter un objet au lot de l'ennemi
void Ennemi::ajouterObjet(Objet* obj) {
    if (lot.size() < 10) {
        lot.push_back(obj);
    } else {
        std::cout << "❌ Inventaire plein !\n";
        delete obj; // Libère la mémoire si l'objet ne peut pas être ajouté
    }
}

// Retourne le lot d'objets de l'ennemi
std::vector<Objet*> Ennemi::getLot() const {
    return lot;
}

void Ennemi::attaquer(Joueur& joueur) {
    int degats = (rand() % this->attaque) - joueur.getDefense();
    if (degats < 0) degats = 0;

    joueur.recevoirDegats(degats); // Réduction directe des PV

    std::cout << "👿 " << this->nom << " attaque et inflige " 
              << degats << " points de dégâts à " << joueur.getNom() << ".\n";

    if (joueur.getPV() <= 0) {
        std::cout << "💀 Vous avez été vaincu...\n";
    }

    //this->afficherInfos();
}
