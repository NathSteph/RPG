#include "ennemi.hpp"
#include "joueur.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "potion.hpp"
#include "arme.hpp"
#include "armure.hpp"

Ennemi::Ennemi(std::string nom, int pv, int atk, int def) 
    : Personnage(nom, pv, atk, def) {
        srand(static_cast<unsigned int>(time(0))); // Initialisation du générateur de nombres aléatoires
        this->type = "ENNEMI";
        initLot();
    }

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

