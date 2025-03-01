#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "personnage.hpp"
#include "ennemi.hpp"
#include "arme.hpp"
#include "armure.hpp"
#include "objet.hpp"

class Joueur : public Personnage {
private:
    Arme* armeEquipee = nullptr;   // Arme actuellement équipée
    Armure* armureEquipee = nullptr; // Armure actuellement équipée
public:    
    Joueur(std::string nom, int pv, int atk, int def);
    virtual ~Joueur();

    void afficherEquipement() const; // Affiche l'équipement actuel
    void equiperObjet();  // Fonction pour équiper une arme ou une armure
    void choisirNom();
    void utiliserPotion();
};

#endif