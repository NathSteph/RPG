#ifndef OBJET_HPP
#define OBJET_HPP

#include <string>

class Objet {
private:
    std::string nom;
    std::string type;
public:
    Objet(std::string n, std::string t);
    virtual ~Objet();
    std::string getNom() const;
    std::string getType() const;
};

#endif