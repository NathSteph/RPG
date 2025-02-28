#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "personnage.hpp"
#include "ennemi.hpp"
#include "arme.hpp"
#include "armure.hpp"
#include "objet.hpp"

class Joueur : public Personnage {
private:
    std::string nom;
    std::vector<Objet*> inventaire;

    Arme* armeEquipee = nullptr;   // Arme actuellement équipée
    Armure* armureEquipee = nullptr; // Armure actuellement équipée

    int pointsDeVie;
    int attaque;
    int defense;
public:    
    Joueur(std::string nom, int pv, int atk, int def);
    virtual ~Joueur();

    std::string getNom() const;
    std::vector<Objet*> getInventaire() const;

    void attaquer(Personnage& ennemi);
    void afficherInventaire() const;
    void afficherInfos() const;
    void afficherEquipement() const; // Affiche l'équipement actuel
    void ajouterObjet(Objet* objet);
    void equiperObjet();  // Fonction pour équiper une arme ou une armure
    //void retirerObjet(Objet* objetChoisi);
    void setNom();
    void setNom(std::string nom);
    void setPointsDeVie(int pointsDeVie);
    void setAttaque(int attaque);
    void setDefense(int defense);
    void setInventaire(std::vector<Objet*> inventaire);
    void utiliserPotion();

    int getPointsDeVie();
    int getAttaque() const;
    int getDefense() const;
};

#endif