#ifndef POTION_HPP
#define POTION_HPP

#include "objet.hpp"


/**
 * @class Potion
 * @brief Classe représentant une potion héritant de la classe Objet.
 */
class Potion : public Objet {
public:
    /**
     * @brief Constructeur de la classe Potion.
     * @param n Nom de la potion.
     */
    Potion(std::string n) : Objet(n, "POTION") {}
};

#endif