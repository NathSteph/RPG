#ifndef ARMURE_HPP
#define ARMURE_HPP

#include "objet.hpp"

class Armure : public Objet {
private:
    int defense;
public:
    Armure(std::string n, int d) : Objet(n, "ARMURE"), defense(d) {}
    // autres méthodes spécifiques à Armure
};

#endif