/* 
 * Compilation : g++ -std=c++98 -Wall -Wextra -pedantic main.cpp -o main3
 * Exécution   : ./main3
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

// ==================================================
// 1. CLASSE ABSTRAITE (Contient une virtuelle pure = 0)
// ==================================================

class Figure {
protected:
    string nom;

public:
    Figure(const string &n) : nom(n) {
        cout << "  [Constructeur Figure] " << nom << endl;
    }

    // DESTRUCTEUR VIRTUEL : Obligatoire pour la destruction via pointeur de base
    virtual ~Figure() {
        cout << "  [Destructeur Figure] " << nom << endl;
    }

    // Méthode virtuelle pure (= 0) -> Classe abstraite
    virtual void afficher() const = 0;

    // Méthode virtuelle classique avec comportement par défaut
    virtual double aire() const {
        return 0.0;
    }
};

// ==================================================
// 2. CLASSES DÉRIVÉES
// ==================================================

class Rectangle : public Figure {
private:
    double largeur;
    double hauteur;

public:
    Rectangle(double l, double h) : Figure("Rectangle"), largeur(l), hauteur(h) {
        cout << "  [Constructeur Rectangle] " << largeur << "x" << hauteur << endl;
    }

    virtual ~Rectangle() {
        cout << "  [Destructeur Rectangle]" << endl;
    }

    // Redéfinition obligatoire de la méthode virtuelle pure
    virtual void afficher() const {
        cout << "Figure: " << nom << " | Largeur: " << largeur 
             << ", Hauteur: " << hauteur << " | Aire: " << aire() << endl;
    }

    virtual double aire() const {
        return largeur * hauteur;
    }

    void methode_specifique_rectangle() const {
        cout << "  -> Methode specifique au Rectangle appelee !" << endl;
    }
};

class Cercle : public Figure {
private:
    double rayon;

public:
    Cercle(double r) : Figure("Cercle"), rayon(r) {
        cout << "  [Constructeur Cercle] r=" << rayon << endl;
    }

    virtual ~Cercle() {
        cout << "  [Destructeur Cercle]" << endl;
    }

    virtual void afficher() const {
        cout << "Figure: " << nom << " | Rayon: " << rayon 
             << " | Aire: " << aire() << endl;
    }

    virtual double aire() const {
        return 3.14159 * rayon * rayon;
    }
};

// ==================================================
// MAIN PRINCIPAL
// ==================================================

int main() {
    cout << "==================================================" << endl;
    cout << " 1. POLYMORPHISME ET LATE BINDING (VIRTUAL)" << endl;
    cout << "==================================================" << endl;
    
    // Figure f("Test"); // ERREUR : Impossible d'instancier une classe abstraite !

    vector<Figure*> figures;
    figures.push_back(new Rectangle(4.0, 5.0));
    figures.push_back(new Cercle(3.0));

    cout << "\nParcours polymorphe du tableau de pointeurs Figure* :" << endl;
    for (size_t i = 0; i < figures.size(); ++i) {
        figures[i]->afficher(); // Appelle le comportement du type réel (Rectangle ou Cercle)
    }

    cout << "\n==================================================" << endl;
    cout << " 2. UPCASTING ET DOWNCASTING (STATIC_CAST)" << endl;
    cout << "==================================================" << endl;

    Figure *pFig = figures; // Upcasting implicite (Rectangle* -> Figure*)

    // Downcasting explicite avec static_cast
    Rectangle *pRect = static_cast<Rectangle*>(pFig);
    pRect->methode_specifique_rectangle();

    cout << "\n==================================================" << endl;
    cout << " 3. LIBÉRATION MÉMOIRE VIA DESTRUCTEUR VIRTUEL" << endl;
    cout << "==================================================" << endl;

    for (size_t i = 0; i < figures.size(); ++i) {
        delete figures[i]; // Déclenche le destructeur de la classe dérivée puis du parent
    }

    return EXIT_SUCCESS;
}