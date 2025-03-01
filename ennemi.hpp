#ifndef ENNEMI_HPP
#define ENNEMI_HPP

#include "personnage.hpp"
#include "objet.hpp"

class Joueur;

class Ennemi : public Personnage {
    private:
        void initLot();
    public:
        Ennemi(std::string nom, int pv, int atk, int def);
    };

#endif
