#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include <iostream>
#include <vector>
#include "objet.hpp"

class Personnage {
protected:
    std::string nom;
    std::string type;   
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

    //------------- Fonctions communes------------------
    std::string getNom() const;
    std::string getType() const;
    std::vector<Objet*> getInventaire() const;

    void attaquer(Personnage& cible);
    void recevoirDegats(int degats);
    void afficherInventaire() const;
    void afficherInfos() const;
    void ajouterObjet(Objet* obj);

    void setNom(std::string nom);
    void setPointsDeVie(int pointsDeVie);
    void setAttaque(int attaque);
    void setDefense(int defense);
    void setInventaire(std::vector<Objet*> inventaire);

    int getPointsDeVie() const;
    int getAttaque() const;
    int getDefense() const;
    
    bool estVivant() const;
};


#endif