#ifndef OBJET_HPP
#define OBJET_HPP

#include <string>

/**
 * @class Objet
 * @brief Classe représentant un objet avec un nom et un type.
 */
class Objet {
private:
    std::string nom; ///< Nom de l'objet
    std::string type; ///< Type de l'objet
public:
    /**
     * @brief Constructeur de la classe Objet.
     * @param n Nom de l'objet.
     * @param t Type de l'objet.
     */
    Objet(std::string n, std::string t);

    /**
     * @brief Destructeur virtuel de la classe Objet.
     */
    virtual ~Objet();

    /**
     * @brief Obtient le nom de l'objet.
     * @return Nom de l'objet.
     */
    std::string getNom() const;

    /**
     * @brief Obtient le type de l'objet.
     * @return Type de l'objet.
     */
    std::string getType() const;
};

#endif