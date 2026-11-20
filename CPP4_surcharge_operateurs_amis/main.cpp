/* 
 * Compilation : g++ -std=c++98 -Wall -Wextra -pedantic main.cpp -o main4
 * Exécution   : ./main4
 */

#include <iostream>
#include <cstdlib>

using namespace std;

class Complexe {
private:
    double re;
    double im;

public:
    Complexe(double r = 0.0, double i = 0.0) : re(r), im(i) {}

    // Constructeur de recopie
    Complexe(const Complexe &autre) : re(autre.re), im(autre.im) {}

    // 1. Opérateur d'affectation = (Membre obligatoire)
    Complexe& operator=(const Complexe &c) {
        if (this != &c) {
            this->re = c.re;
            this->im = c.im;
        }
        return *this; // Permet le chaînage : c1 = c2 = c3
    }

    // 2. Opérateur [] : accès indexé (0: réelle, 1: imaginaire)
    double& operator[](size_t idx) {
        if (idx == 0) return re;
        return im;
    }

    // 3. Opérateur unaire -
    Complexe operator-() const {
        return Complexe(-re, -im);
    }

    // 4. Pré-incrémentation (++c)
    Complexe& operator++() {
        re += 1.0;
        return *this;
    }

    // 5. Post-incrémentation (c++) : int est fictif
    Complexe operator++(int) {
        Complexe temp = *this;
        re += 1.0;
        return temp;
    }

    // 6. Opérateur binaire membre : Complexe + Complexe
    Complexe operator+(const Complexe &c) const {
        return Complexe(re + c.re, im + c.im);
    }

    // 7. Opérateur binaire membre : Complexe + double (c + 3.5)
    Complexe operator+(double val) const {
        return Complexe(re + val, im);
    }

    // Déclarations des fonctions amies (friend)
    friend Complexe operator+(double val, const Complexe &c);
    friend ostream& operator<<(ostream &os, const Complexe &c);
    friend istream& operator>>(istream &is, Complexe &c);
    friend bool operator==(const Complexe &c1, const Complexe &c2);
};

// Fonction libre amie : double + Complexe (3.5 + c)
Complexe operator+(double val, const Complexe &c) {
    return Complexe(val + c.re, c.im);
}

// Surcharge de l'opérateur de flux de sortie <<
ostream& operator<<(ostream &os, const Complexe &c) {
    os << "(" << c.re << " + " << c.im << "i)";
    return os;
}

// Surcharge de l'opérateur de flux d'entrée >>
istream& operator>>(istream &is, Complexe &c) {
    cout << "  Partie reelle : ";
    is >> c.re;
    cout << "  Partie imaginaire : ";
    is >> c.im;
    return is;
}

// Surcharge de l'opérateur d'égalité ==
bool operator==(const Complexe &c1, const Complexe &c2) {
    return (c1.re == c2.re) && (c1.im == c2.im);
}

// ==================================================
// MAIN PRINCIPAL
// ==================================================

int main() {
    cout << "==================================================" << endl;
    cout << " 1. AFFICHAGE ET OPÉRATEURS BINAIRES (+, <<)" << endl;
    cout << "==================================================" << endl;

    Complexe c1(1.2, 2.3);
    Complexe c2(2.2, 3.3);
    cout << "c1 = " << c1 << " | c2 = " << c2 << endl;

    Complexe c3 = c1 + c2; // Complexe + Complexe
    cout << "c1 + c2 = " << c3 << endl;

    Complexe c4 = c1 + 5.0; // Complexe + double
    cout << "c1 + 5.0 = " << c4 << endl;

    Complexe c5 = 10.0 + c1; // double + Complexe (via fonction libre amie)
    cout << "10.0 + c1 = " << c5 << endl;

    cout << "\n==================================================" << endl;
    cout << " 2. AFFECTATION (=), ACCÈS ([]), UNIAIRE ET ++" << endl;
    cout << "==================================================" << endl;

    Complexe c6;
    c6 = c1; // Surcharge de operator=
    cout << "Apres c6 = c1 : c6 = " << c6 << endl;

    cout << "Modification via c6 = 9.9 :" << endl;
    c6 = 9.9;
    cout << "c6 = " << c6 << endl;

    cout << "Pre-incrementation ++c6 : " << ++c6 << endl;
    cout << "Post-incrementation c6++ : " << c6++ << " -> resultat apres : " << c6 << endl;
    cout << "Oppose -c6 : " << -c6 << endl;

    return EXIT_SUCCESS;
}