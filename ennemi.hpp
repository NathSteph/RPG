#ifndef ENNEMI_HPP
#define ENNEMI_HPP

#include "personnage.hpp"
#include "objet.hpp"

class Joueur;

class Ennemi : public Personnage {
    private:
        std::vector<Objet*> lot;
        void initLot();

    public:
        Ennemi(std::string nom, int pv, int atk, int def);
        
        std::vector<Objet*> getLot() const;

        void attaquer(Joueur& joueur);
        void afficherInfos() const;  // Pour afficher les infos de l'ennemi
        void ajouterObjet(Objet* obj);
        
    };

#endif
