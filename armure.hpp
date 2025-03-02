#ifndef ARMURE_HPP
#define ARMURE_HPP

#include "objet.hpp"

/**
 * @class Armure
 * @brief Classe représentant une armure héritant de la classe Objet.
 */
class Armure : public Objet {
private:
    int defense; ///< Valeur de défense de l'armure
public:
    /**
     * @brief Constructeur de la classe Armure.
     * @param n Nom de l'armure.
     * @param d Valeur de défense de l'armure.
     */
    Armure(std::string n, int d) : Objet(n, "ARMURE"), defense(d) {}

    /**
     * @brief Obtient la valeur de défense de l'armure.
     * @return Valeur de défense de l'armure.
     */
    int getDefense() const { return defense; }
};

#endif