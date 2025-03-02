#ifndef ARME_HPP
#define ARME_HPP

#include "objet.hpp"

/**
 * @class Arme
 * @brief Classe représentant une arme héritant de la classe Objet.
 */
class Arme : public Objet {
private:
    int puissance; ///< Puissance de l'arme
public:
    /**
     * @brief Constructeur de la classe Arme.
     * @param n Nom de l'arme.
     * @param p Puissance de l'arme.
     */
    Arme(std::string n, int p) : Objet(n, "ARME"), puissance(p) {}

    /**
     * @brief Obtient la puissance de l'arme.
     * @return Puissance de l'arme.
     */
    int getPuissance() const { return puissance; }
};

#endif