#ifndef JEU_HPP
#define JEU_HPP

#include "joueur.hpp"
#include "allie.hpp"
#include <fstream>

class Jeu {
private:
    Joueur joueur;
    Allie allie;
    bool estVivant;
public:
    Jeu();
    void combattre(Ennemi& ennemi);
    void rencontrerAllie();
    void trouverObjet();
    void lancerPartie();
    void continuerPartie();
    void sauvegarderPartie() const;
    void chargerPartie();
};

#endif