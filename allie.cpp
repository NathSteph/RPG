#include "allie.hpp"
#include "potion.hpp"
#include "arme.hpp"
#include "armure.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Allie::Allie(std::string nom, int pv, int atk, int def) : Personnage(nom, pv, atk, def) {
    srand(static_cast<unsigned int>(time(0))); // Initialisation du générateur de nombres aléatoires
    initLot();
    this->nom = nom;
    this->PV = pv;
    this->attaque = atk;
    this->defense = def;
    this->type = "ALLIE";
}

void Allie::initLot() {
    std::string nom;
    // Initialisation du lot d'objets
    std::vector<std::string> nomsPotions = {
        "Potion de résistance", 
        "Potion de chance", 
        "Potion de guérison"};
    nom = nomsPotions[rand() % nomsPotions.size()];
    ajouterObjet(new Potion(nom));

    std::vector<std::string> nomsArmes = {
        "Arc en bois",
        "Hache en pierre",
        "Épée en bois"};
    nom = nomsArmes[rand() % nomsArmes.size()];
    ajouterObjet(new Arme(nom, rand() % 10 + 5));

    std::vector<std::string> nomsArmures = {
        "Bottes en cuir",
        "Gants en fer",
        "Bouclier en bois"};
    nom = nomsArmures[rand() % nomsArmures.size()];
    ajouterObjet(new Armure(nom, rand() % 5 + 2));
}

Objet* Allie::offrirObjet() {
    if (inventaire.empty()) {
        std::cout << nom << " n'a pas d'objet à offrir. 😢\n";
        return nullptr;
    }

    std::cout << "🎁 " << nom << " veut vous offrir un objet !\n";
    
    // Afficher les objets disponibles
    for (size_t i = 0; i < inventaire.size(); i++) {
        std::cout << i + 1 << ". " << inventaire[i]->getNom() << " (" << inventaire[i]->getType() << ")\n";
    }

    // Choix de l'objet
    int choix;
    std::cout << "Quel objet voulez-vous prendre ? (Entrez le numéro) : ";
    std::cin >> choix;

    if (choix >= 1 && choix <= (int)inventaire.size()) {
        Objet* objetChoisi = inventaire[choix - 1];
        inventaire.erase(inventaire.begin() + (choix - 1)); // Retirer l’objet de l’inventaire de l’allié
        return objetChoisi;
    } else {
        std::cout << "❌ Choix invalide. Vous n'avez pris aucun objet. Il repart...\n";
        return nullptr;
    }
}
