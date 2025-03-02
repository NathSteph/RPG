#ifndef ALLIE_HPP
#define ALLIE_HPP

#include "personnage.hpp"
#include "objet.hpp"
#include <vector>

/**
 * @class Allie
 * @brief Classe représentant un allié héritant de la classe Personnage.
 */
class Allie : public Personnage {
private:
    /**
     * @brief Initialise le lot d'objets de l'allié.
     */
    void initLot();
public:
    /**
     * @brief Constructeur de la classe Allie.
     * @param nom Nom de l'allié.
     * @param pv Points de vie de l'allié.
     * @param atk Valeur d'attaque de l'allié.
     * @param def Valeur de défense de l'allié.
     */
    Allie(std::string nom, int pv, int atk, int def);

    /**
     * @brief Offre un objet à un joueur.
     * @return Pointeur vers l'objet offert.
     */
    Objet* offrirObjet();
};

#endif
