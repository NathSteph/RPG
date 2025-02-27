#ifndef ARME_HPP
#define ARME_HPP

#include "objet.hpp"

class Arme : public Objet {
private:
    int puissance;
public:
    Arme(std::string n, int p) : Objet(n, "ARME"), puissance(p) {}
    // autres méthodes spécifiques à Arme
};

#endif