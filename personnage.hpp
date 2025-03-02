#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include <iostream>
#include <vector>
#include "objet.hpp"

/**
 * @class Personnage
 * @brief Classe représentant un personnage avec des attributs et des méthodes pour gérer ses actions.
 */
class Personnage {
protected:
    std::string nom; ///< Nom du personnage
    std::string type; ///< Type du personnage
    std::vector<Objet*> inventaire; ///< Inventaire des objets du personnage
    int PV; ///< Points de vie du personnage
    int attaque; ///< Valeur d'attaque du personnage
    int defense; ///< Valeur de défense du personnage
    /*Objet* arme; ///< Arme équipée par le personnage
    Objet* armure; ///< Armure équipée par le personnage
    Objet* potion; ///< Potion possédée par le personnage*/

public:
    /**
     * @brief Constructeur de la classe Personnage.
     * @param nom Nom du personnage.
     * @param pv Points de vie du personnage.
     * @param atk Valeur d'attaque du personnage.
     * @param def Valeur de défense du personnage.
     */
    Personnage(std::string nom, int pv, int atk, int def);

    /**
     * @brief Destructeur virtuel de la classe Personnage.
     */
    virtual ~Personnage();

    //------------- Fonctions communes------------------

    /**
     * @brief Obtient le nom du personnage.
     * @return Nom du personnage.
     */
    std::string getNom() const;

    /**
     * @brief Obtient le type du personnage.
     * @return Type du personnage.
     */
    std::string getType() const;

    /**
     * @brief Obtient l'inventaire du personnage.
     * @return Vecteur d'objets représentant l'inventaire du personnage.
     */
    std::vector<Objet*> getInventaire() const;

    /**
     * @brief Attaque un autre personnage.
     * @param cible Référence vers le personnage cible.
     */
    void attaquer(Personnage& cible);

    /**
     * @brief Reçoit des dégâts.
     * @param degats Quantité de dégâts reçus.
     */
    void recevoirDegats(int degats);

    /**
     * @brief Affiche l'inventaire du personnage.
     */
    void afficherInventaire() const;

    /**
     * @brief Surcharge de l'opérateur de flux de sortie pour afficher les informations du personnage.
     * @param os Référence vers le flux de sortie.
     * @param p Référence vers le personnage à afficher.
     * @return Référence vers le flux de sortie.
     */
    friend std::ostream& operator<<(std::ostream& os, const Personnage& p);


    /**
     * @brief Ajoute un objet à l'inventaire du personnage.
     * @param obj Pointeur vers l'objet à ajouter.
     */
    void ajouterObjet(Objet* obj);

    /**
     * @brief Définit le nom du personnage.
     * @param nom Nouveau nom du personnage.
     */
    void setNom(std::string nom);

    /**
     * @brief Définit les points de vie du personnage.
     * @param pointsDeVie Nouveaux points de vie du personnage.
     */
    void setPointsDeVie(int pointsDeVie);

    /**
     * @brief Définit la valeur d'attaque du personnage.
     * @param attaque Nouvelle valeur d'attaque du personnage.
     */
    void setAttaque(int attaque);

    /**
     * @brief Définit la valeur de défense du personnage.
     * @param defense Nouvelle valeur de défense du personnage.
     */
    void setDefense(int defense);

    /**
     * @brief Définit l'inventaire du personnage.
     * @param inventaire Nouveau vecteur d'objets représentant l'inventaire du personnage.
     */
    void setInventaire(std::vector<Objet*> inventaire);

    /**
     * @brief Obtient les points de vie du personnage.
     * @return Points de vie du personnage.
     */
    int getPointsDeVie() const;

    /**
     * @brief Obtient la valeur d'attaque du personnage.
     * @return Valeur d'attaque du personnage.
     */
    int getAttaque() const;

    /**
     * @brief Obtient la valeur de défense du personnage.
     * @return Valeur de défense du personnage.
     */
    int getDefense() const;

    /**
     * @brief Vérifie si le personnage est vivant.
     * @return true si le personnage est vivant, false sinon.
     */
    bool estVivant() const;
};

#endif