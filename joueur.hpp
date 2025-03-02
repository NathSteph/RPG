#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "personnage.hpp"
#include "ennemi.hpp"
#include "arme.hpp"
#include "armure.hpp"
#include "objet.hpp"

/**
 * @class Joueur
 * @brief Classe représentant un joueur avec des attributs et des méthodes pour gérer ses actions.
 * @details La classe Joueur hérite de la classe Personnage.
 */
class Joueur : public Personnage {
private:
    Arme* armeEquipee = nullptr; ///< Arme actuellement équipée
    Armure* armureEquipee = nullptr; ///< Armure actuellement équipée
public:
    /**
     * @brief Constructeur de la classe Joueur.
     * @param nom Nom du joueur.
     * @param pv Points de vie du joueur.
     * @param atk Valeur d'attaque du joueur.
     * @param def Valeur de défense du joueur.
     */ 
    Joueur(std::string nom, int pv, int atk, int def);

    /**
     * @brief Destructeur de la classe Joueur.
     */
    virtual ~Joueur();

    /**
     * @brief Affiche l'équipement actuel du joueur.
     */
    void afficherEquipement() const;

    /**
     * @brief Équipe un objet de l'inventaire.
     */
    void equiperObjet();

    /**
     * @brief Choisi un nom pour le joueur.
     */
    void choisirNom();

    /**
     * @brief Utilise une potion de l'inventaire.
     */
    void utiliserPotion();
};

#endif