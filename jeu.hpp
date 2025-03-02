#ifndef JEU_HPP
#define JEU_HPP

#include "joueur.hpp"
#include "allie.hpp"
#include <fstream>


/**
 * @class Jeu
 * @brief Classe représentant le jeu avec des attributs et des méthodes pour gérer le déroulement du jeu.
 */
class Jeu {
private:

    Joueur joueur; ///< Joueur du jeu
    Allie allie; ///< Allié du joueur
    bool estVivant; ///< Indique si le joueur est vivant
public:
    /**
     * @brief Constructeur de la classe Jeu.
     */
    Jeu();

    /**
     * @brief Destructeur de la classe Jeu.
     */
    virtual ~Jeu();

    /**
     * @brief Combattre un ennemi.
     * @param ennemi Ennemi à combattre.
     */
    void combattre(Ennemi& ennemi);

    /**
     * @brief Rencontrer un allié.
     */
    void rencontrerAllie();

    /**
     * @brief Trouver un objet.
     */
    void trouverObjet();

    /**
     * @brief Lancer une partie.
     */
    void lancerPartie();

    /**
     * @brief Continuer une partie.
     */
    void continuerPartie();

    /**
     * @brief Sauvegarder la partie.
     */
    void sauvegarderPartie() const;

    /**
     * @brief Charger une partie.
     */
    void chargerPartie();
};

#endif