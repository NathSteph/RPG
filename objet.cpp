#include "objet.hpp"

Objet::Objet(std::string n, std::string t) : nom(n), type(t) {}

Objet::~Objet() { }

std::string Objet::getNom() const {
    return nom;
}

std::string Objet::getType() const {
    return type;
}

