#ifndef ENNEMI_HPP
#define ENNEMI_HPP

#include "personnage.hpp"
#include "objet.hpp"

/**
 * @class Ennemi
 * @brief Classe représentant un ennemi héritant de la classe Personnage.
 */
class Ennemi : public Personnage {
    private:
        /**
         * @brief Initialise le lot d'objets de l'ennemi.
         */
        void initLot();
    public:
        /**
         * @brief Constructeur de la classe Ennemi.
         * @param nom Nom de l'ennemi.
         * @param pv Points de vie de l'ennemi.
         * @param atk Valeur d'attaque de l'ennemi.
         * @param def Valeur de défense de l'ennemi.
         */
        Ennemi(std::string nom, int pv, int atk, int def);
    };

#endif
