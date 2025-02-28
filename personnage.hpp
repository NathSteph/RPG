#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include <iostream>
#include <vector>
#include "objet.hpp"

class Personnage {
protected:
    std::string nom;
    std::vector<Objet*> inventaire;
    int PV;
    int attaque;
    int defense;
    Objet* arme;
    Objet* armure;
    Objet* potion;

public:
    Personnage(std::string nom, int pv, int atk, int def);
    virtual ~Personnage();
    virtual void attaquer(Personnage& cible);
    std::string getNom() const;

    void recevoirDegats(int degats);
    void afficherInventaire() const;
    
    int getPV() const;
    int getAttaque() const;
    int getDefense() const;

    bool estVivant() const;
};


#endif