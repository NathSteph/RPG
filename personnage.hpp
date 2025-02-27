#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include <iostream>
#include <vector>
#include "objet.hpp"

class Personnage {
protected:
    std::string nom;
    int PV;
    int attaque;
    int defense;
    std::vector<Objet*> inventaire;
    Objet* arme;
    Objet* armure;
    Objet* potion;

public:
    Personnage(std::string nom, int pv, int atk, int def);
    virtual ~Personnage();
    
    virtual void attaquer(Personnage& cible);
    void recevoirDegats(int degats);
    bool estVivant() const;
    //bool ajouterObjet(Objet* objet);
    void afficherInventaire() const;
    
    std::string getNom() const { return nom; }
    int getPV() const { return PV; }
    int getAttaque() const { return attaque; }
    int getDefense() const { return defense; }
};


#endif