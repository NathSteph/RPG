#include "jeu.hpp"
#include "ennemi.hpp"
#include "potion.hpp"
#include "arme.hpp"
#include "armure.hpp"
#include "allie.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <ctime>

using namespace std;

Jeu::Jeu() : joueur("", rand() % 50 + 100, rand() % 30 + 10, rand() % 10 + 5), allie("Sauveur", rand() % 70 + 100, 0, 0) {
    srand(static_cast<unsigned int>(time(0))); // Initialisation du générateur de nombres aléatoires
}

Jeu::~Jeu() {}

void Jeu::trouverObjet() {
    std::vector<Objet*> objetsTrouves = {
        new Potion("Potion mystérieuse"),
        new Arme("Dague en acier", rand() % 10 + 5),
        new Armure("Bouclier en bois", rand() % 5 + 2),
        new Potion("Potion de soin"),
        new Arme("Épée en fer", rand() % 15 + 5),
        new Armure("Armure légère", rand() % 8 + 5),
        new Potion("Potion de force"),
        new Arme("Arc en bois", rand() % 8 + 3),
        new Armure("Casque en acier", rand() % 5 + 2)
    };

    Objet* objet = objetsTrouves[rand() % objetsTrouves.size()];

    std::cout << "🎁 Vous trouvez un objet : " << objet->getNom() << "\n";
    char choix;
    if(objet->getType() == "POTION"){
        std::cout << "Voulez-vous le ramasser ? (O/N) : ";
        std::cin >> choix;
        if (choix == 'O' || choix == 'o') {
            joueur.ajouterObjet(objet);
            //std::cout << "✔️ Vous ajoutez " << objet->getNom() << " à votre inventaire !\n";
        } else {
            std::cout << "❌ Vous laissez l’objet sur place.\n\n";
        }
    }
    else{
        std::cout << "Voulez-vous le ramasser ? (O/N) : ";
        std::cin >> choix;
        if (choix == 'o' || choix == 'O') {
            joueur.ajouterObjet(objet);
            std::cout << "Voulez-vous équiper une arme ou armure ? (O/N) : ";
            std::cin >> choix;
            std::cout << "\n";
            if (choix == 'o' || choix == 'O') {
                joueur.equiperObjet();
            } else {
                std::cout << "🎒 Vous n'avez rien mis !\n\n";
            }
        } else {
            std::cout << "❌ Vous laissez l’objet sur place.\n\n";
        }
    }
}

void Jeu::rencontrerAllie() {
    char choix;
    std::cout << "🤝 Vous rencontrez "<< allie.getNom() << " c'est un allié !\n";
    Objet* objet = allie.offrirObjet();

    if (objet != nullptr && objet->getType() != "POTION") {
        joueur.ajouterObjet(objet);
        std::cout << "Voulez-vous équiper une arme ou armure ? (O/N) : ";
        std::cin >> choix;
        std::cout << "\n";
        if (choix == 'o' || choix == 'O') {
            joueur.equiperObjet();
        } else{
            std::cout << "🎒 L'objet n'a pas été équipé !\n\n";
        }
    }
    else if(objet != nullptr && objet->getType() == "POTION"){
        std::cout << "Voulez-vous le ramasser ? (O/N) : ";
        std::cin >> choix;
        if (choix == 'O' || choix == 'o') {
            joueur.ajouterObjet(objet);
            //std::cout << "✔️ Vous ajoutez " << objet->getNom() << " à votre inventaire !\n";
        } else {
            std::cout << "❌ Vous laissez l’objet sur place.\n\n";
        }
    }
    else {
        std::cout << "👋 " << allie.getNom() << " s'en va avec...\n\n";
    }
}

void Jeu::combattre(Ennemi& ennemi) {
    std::cout << "⚔️  Un combat commence contre " << ennemi.getNom() << " !\n\n";

    // Déterminer qui attaque en premier (1 = joueur, 0 = ennemi)
    bool tourJoueur = rand() % 2;

    estVivant = true;

    while (joueur.getPointsDeVie() > 0 && ennemi.getPointsDeVie() > 0) {
        if (tourJoueur) {
            std::cout << "🔹 Votre tour !\n";
            joueur.attaquer(ennemi);
        } else {
            std::cout << "🔻 L'ennemi attaque !\n";
            ennemi.attaquer(joueur);
            if (joueur.getPointsDeVie() <= 0) {
                joueur.utiliserPotion();
                if (joueur.getPointsDeVie() > 0) {
                    std::cout << "💪 Vous êtes rétabli grâce à la potion et continuez à combattre !\n\n";
                    continue;
                }
            }
        }

        // Vérifier si l'un des deux est mort
        if (ennemi.getPointsDeVie() <= 0) {
            std::cout << "🏆 Vous avez vaincu " << ennemi.getNom() << " ! Vous pouvez récupérer des objets.\n";
            auto lot = ennemi.getInventaire();
            for (Objet* obj : lot) {
                std::cout << "Voulez-vous prendre " << obj->getNom() << " ? (O/N) : ";
                char choix;
                std::cin >> choix;
                if (choix == 'O' || choix == 'o') {
                    joueur.ajouterObjet(obj);
                }
            }
            std::cout << "Voulez-vous sauvegarder la partie ? (O/N) : ";
            char choix;
            std::cin >> choix;
            if (choix == 'O' || choix == 'o') {
                this->sauvegarderPartie();
            }
            std::cout << "\n";
            std::cout << "Voulez-vous continuer à jouer ? (O/N) : ";
            std::cin >> choix;
            std::cout << "\n";
            if (choix == 'N' || choix == 'n') {
                exit(0); // Quitter le jeu après la victoire
            }
            return;
        }

        if (joueur.getPointsDeVie() <= 0) {
            std::cout << "💀 Vous avez perdu... GAME OVER.\n";
            estVivant = false;
            exit(0);
            break;
        }

        // Changement de tour
        tourJoueur = !tourJoueur;
    }
}

void Jeu::lancerPartie() {
    joueur.choisirNom();
    joueur.setPointsDeVie(rand() % 50 + 100);
    joueur.setAttaque(rand() % 30 + 10);
    joueur.setDefense(rand() % 10 + 5);
    joueur.setInventaire(std::vector<Objet*>());

    std::vector<std::string> nomsEnnemis = {"Gobelin", "Orc", "Loup", "Squelette", "Bandit"};
    
    std::cout << "🎮 Début du jeu...\n\n";

    while (joueur.getPointsDeVie() > 0) {

        int evenement = rand() % 2;
        if (evenement == 0) {
            rencontrerAllie();
        } else {
            trouverObjet();
        }

        std::string nom = nomsEnnemis[rand() % nomsEnnemis.size()];
        int pv = rand() % 50 + 100;
        int attaque = rand() % 30 + 10;
        int defense = rand() % 10 + 5;

        Ennemi ennemi(nom, pv, attaque, defense);
        std::cout << "⚔️  Un " << ennemi.getNom() << " sauvage apparaît !\n";

        char choix;
        std::cout << "👉 Que voulez-vous faire ? (A: Attaquer / F: Fuir / Q: Quitter) : ";
        std::cin >> choix;

        if (choix == 'A' || choix == 'a') {
            std::cout << joueur;
            std::cout << ennemi;
            cout << "\n";
            combattre(ennemi);
            if (!estVivant) {
                return; // Sort du jeu si le joueur est mort
            }
        } else if (choix == 'F' || choix == 'F') {
            std::cout << "🏃 Vous prenez la fuite...\n";
        }
        else if (choix == 'Q' || choix == 'q') {
            std::cout << "👋 Au revoir !\n";
            sauvegarderPartie();
            exit(0);
        }
    }
}

void Jeu::chargerPartie() {
    ifstream fichier("sauvegarde.txt");

    if (fichier) {
        string nom;
        int pv, atk, def, nbObjets;
        string nomObjet, typeObjet;

        getline(fichier, nom);
        fichier >> pv;
        fichier >> atk >> def;
        fichier >> nbObjets;

        // Réinitialise les données du joueur
        joueur.setNom(nom);
        joueur.setPointsDeVie(pv);
        joueur.setAttaque(atk);
        joueur.setDefense(def);
        joueur.setInventaire(std::vector<Objet*>());


        fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore le reste de la ligne

        // Charge l'inventaire
        for (int i = 0; i < nbObjets; ++i) {
            std::string ligne;
            std::getline(fichier, ligne);

            if (!ligne.empty()) {
                size_t positionDeuxPoints = ligne.find(':');
                if (positionDeuxPoints != std::string::npos) {
                    std::string nomObjet = ligne.substr(0, positionDeuxPoints);
                    std::string typeObjet = ligne.substr(positionDeuxPoints + 1); // Enlève l'espace après le ':'

                    Objet* objet = new Objet(nomObjet, typeObjet);
                    joueur.ajouterObjet(objet);
                }
            }
        }

        cout << "📂 Partie chargée !" << endl;
        continuerPartie();
    } else {
        cout << "❌ Erreur : Impossible de charger la partie." << endl;
    }
}

void Jeu::sauvegarderPartie() const {
    ofstream fichier("sauvegarde.txt");

    if (fichier) {
        fichier << joueur.getNom() << endl;
        fichier << joueur.getPointsDeVie() << endl;
        fichier << joueur.getAttaque() << " " << joueur.getDefense() << endl;
        
        // Sauvegarde l'inventaire
        fichier << joueur.getInventaire().size() << endl;
        for (const auto& objet : joueur.getInventaire()) {
            fichier << objet->getNom() << ":" << objet->getType() << endl;
        }

        fichier.close();
        cout << "💾 Partie sauvegardée !" << endl;
    } else {
        cout << "❌ Erreur : Impossible de sauvegarder la partie." << endl;
    }
}

void Jeu::continuerPartie() {
    std::vector<std::string> nomsEnnemis = {"Gobelin", "Orc", "Loup", "Squelette", "Bandit"};
    
    std::cout << "🎮 Reprise du jeu...\n";

    while (joueur.getPointsDeVie() > 0) {

        int evenement = rand() % 2;
        if (evenement == 0) {
            rencontrerAllie();
        } else {
            trouverObjet();
        }

        std::string nom = nomsEnnemis[rand() % nomsEnnemis.size()];
        int pv = rand() % 50 + 100;
        int attaque = rand() % 30 + 10;
        int defense = rand() % 10 + 5;

        Ennemi ennemi(nom, pv, attaque, defense);
        std::cout << "⚔️  Un " << ennemi.getNom() << " sauvage apparaît !\n";

        char choix;
        std::cout << "👉 Que voulez-vous faire ? (A: Attaquer / F: Fuir / Q: Quitter) : ";
        std::cin >> choix;

        if (choix == 'A' || choix == 'a') {
            std::cout << joueur;
            std::cout << ennemi;
            combattre(ennemi);
            if (!estVivant) {
                return; // Sort du jeu si le joueur est mort
            }
        } else if (choix == 'F' || choix == 'F') {
            std::cout << "🏃 Vous prenez la fuite...\n";
        }
        else if (choix == 'Q' || choix == 'q') {
            std::cout << "👋 Au revoir !\n";
            sauvegarderPartie();
            exit(0);
        }
    }
}