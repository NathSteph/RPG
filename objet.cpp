#include "objet.hpp"

// Constructeur : initialise le nom de l'objet
Objet::Objet(std::string n, std::string t) : nom(n), type(t) {}

// Destructeur virtuel
Objet::~Objet() { }

// Retourne le nom de l'objet
std::string Objet::getNom() const {
    return nom;
}

// Retourne le type de l'objet
std::string Objet::getType() const {
    return type;
}

