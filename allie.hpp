#ifndef ALLIE_HPP
#define ALLIE_HPP

#include "personnage.hpp"
#include "objet.hpp"
#include <vector>

class Allie : public Personnage {
private:
    std::vector<Objet*> objets; // Inventaire de l'allié
    std::string nom;
    int pointsDeVie;
    int attaque;
    int defense;
    void initLot();

public:
    Allie(std::string nom, int pv, int atk, int def); // Les alliés n'ont pas d'attaque ni de défense

    void ajouterObjet(Objet* objet); // Méthode pour ajouter un objet à l'inventaire de l'allié

    Objet* offrirObjet(); // Méthode pour offrir un objet
};

#endif
