#include <iostream>
#include "jeu.hpp"
#include "joueur.hpp"

using namespace std;

/**
 * @brief Affiche le menu principal du jeu.
 */
void afficherMenu() {
    cout << "=========================\n";
    cout << "     🌟 RPG TEXTUEL 🌟\n";
    cout << "=========================\n";
    cout << "1. 🆕 Nouvelle partie\n";
    cout << "2. 📂 Charger une partie\n";
    cout << "3. ❌ Quitter\n";
    cout << "=========================\n";
    cout << "Votre choix : ";
}

int main() {
    int choix;
    Jeu jeu;  // Création du jeu

    do {
        afficherMenu();
        cin >> choix;

        switch (choix) {
            case 1:
                jeu.lancerPartie();
                break;
            case 2:
                jeu.chargerPartie();
                break;
            case 3:
                jeu.sauvegarderPartie();
                cout << "👋 Au revoir !\n";
                break;
            default:
                cout << "Choix invalide. Réessayez.\n";
        }
    } while (choix != 3);

    return 0;
}
