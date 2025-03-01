#ifndef ALLIE_HPP
#define ALLIE_HPP

#include "personnage.hpp"
#include "objet.hpp"
#include <vector>

class Allie : public Personnage {
private:
    void initLot();
public:
    Allie(std::string nom, int pv, int atk, int def); // Les alliés n'ont pas d'attaque ni de défense

    Objet* offrirObjet(); // Méthode pour offrir un objet
};

#endif
