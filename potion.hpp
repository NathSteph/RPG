#ifndef POTION_HPP
#define POTION_HPP

#include "objet.hpp"

class Potion : public Objet {
public:
    Potion(std::string n) : Objet(n, "POTION") {}
    // autres méthodes spécifiques à Potion
};

#endif