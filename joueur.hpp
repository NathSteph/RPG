#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "personnage.hpp"
#include "ennemi.hpp"
#include "objet.hpp"

class Joueur : public Personnage {
private:
    std::string nom;
    int pointsDeVie;
    int attaque;
    int defense;
    std::vector<Objet*> inventaire;
        
public:    
    Joueur(std::string nom, int pv, int atk, int def);
    void attaquer(Personnage& ennemi);

    void afficherInventaire() const;
    void ajouterObjet(Objet* objet);

    void setNom();
    void setNom(std::string nom);
    void setPointsDeVie(int pointsDeVie);
    void setAttaque(int attaque);
    void setDefense(int defense);
    void setInventaire(std::vector<Objet*> inventaire);
    std::string getNom() const;
    int getPointsDeVie();
    int getAttaque() const;
    int getDefense() const;
    std::vector<Objet*> getInventaire() const;
    void afficherInfos() const;

};

#endif