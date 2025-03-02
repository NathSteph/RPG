#include "joueur.hpp"
#include "objet.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

Joueur::Joueur(std::string nom, int pv, int atk, int def) : Personnage(nom, pv, atk, def) {
    this->type = "JOUEUR";
}

Joueur::~Joueur() {
    // Libérer la mémoire des objets de l'inventaire
    for (auto objet : inventaire) {
        delete objet;
    }
    inventaire.clear();
    if (armeEquipee) delete armeEquipee;
    if (armureEquipee) delete armureEquipee;

}

void Joueur::utiliserPotion() {
    for (size_t i = 0; i < inventaire.size(); ++i) {
        if (inventaire[i]->getType() == "POTION") {
            std::cout << "💖 Vous utilisez une " << inventaire[i]->getNom() << " et récupérez 50 PV !\n";
            setPointsDeVie(getPointsDeVie() + 50); // La potion restaure 50 PV (ajuste cette valeur si nécessaire)
            delete inventaire[i]; // Libère la mémoire de l'objet
            inventaire.erase(inventaire.begin() + i); // Supprime la potion de l’inventaire
            return;
        }
    }
}

void Joueur::choisirNom() {
    cout << "👤 Choisissez un nom pour votre personnage : ";
    cin >> this->nom;
    cout << "👤 Bienvenue, " << this->nom << " !\n\n";
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

    for (auto& objet : getInventaire()) {
        if (objet->getType() == "ARME" || objet->getType() == "ARMURE") {
            std::cout << index << ". " << objet->getNom() << " (" << objet->getType() << ")\n";
            choix.push_back(objet);
            index++;
        }
    }

    if (choix.empty()) {
        std::cout << "❌ Vous n'avez ni arme ni armure dans votre inventaire.\n\n";
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
            std::cout << "⚔️ Vous équipez " << armeEquipee->getNom() << " (+" << armeEquipee->getPuissance() << " attaque) !\n\n";
            afficherEquipement();
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
            std::cout << "🛡️ Vous équipez " << armureEquipee->getNom() << " (+" << armureEquipee->getDefense() << " défense) !\n\n";
            afficherEquipement();
        }

        // Retirer l'objet de l'inventaire
        inventaire.erase(std::remove(inventaire.begin(), inventaire.end(), objetChoisi), inventaire.end());
    } 
    else {
        std::cout << "❌ Annulation.\n";
    }
}