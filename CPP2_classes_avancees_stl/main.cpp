/* 
 * Compilation : g++ -std=c++98 -Wall -Wextra -pedantic main.cpp -o main2
 * Exécution   : ./main2
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>

using namespace std;

// ==================================================
// 1. HÉRITAGE ET LISTE D'INITIALISATION
// ==================================================

class Personne {
protected:
    string nom;

public:
    // Liste d'initialisation
    Personne(const string &n) : nom(n) {
        cout << "  [Constructeur Personne] " << nom << endl;
    }

    virtual ~Personne() {
        cout << "  [Destructeur Personne] " << nom << endl;
    }

    void afficher() const {
        cout << "Nom: " << nom;
    }
};

// Classe dérivée (Héritage public)
class Etudiant : public Personne {
private:
    int numEtudiant;

public:
    // Appel obligatoire du constructeur parent dans la liste d'initialisation
    Etudiant(const string &n, int num) : Personne(n), numEtudiant(num) {
        cout << "  [Constructeur Etudiant] INE: " << numEtudiant << endl;
    }

    ~Etudiant() {
        cout << "  [Destructeur Etudiant] INE: " << numEtudiant << endl;
    }

    void afficher_etudiant() const {
        afficher();
        cout << " | N° Etudiant: " << numEtudiant << endl;
    }
};

// ==================================================
// 2. CONSTRUCTEUR DE RECOPIE & SURCHARGE DE ++
// ==================================================

class Compteur {
private:
    int valeur;

public:
    Compteur(int v = 0) : valeur(v) {}

    // Constructeur par recopie explicite
    Compteur(const Compteur &autre) : valeur(autre.valeur) {
        cout << "  [Constructeur de Recopie Compteur] Valeur recopiee: " << valeur << endl;
    }

    // Pré-incrémentation (++c) : renvoie l'objet courant par référence
    Compteur& operator++() {
        ++valeur;
        return *this;
    }

    // Post-incrémentation (c++) : int est un argument fictif
    // Renvoie une copie temporaire par valeur avant l'incrémentation
    Compteur operator++(int) {
        Compteur temp = *this; // Appel du constructeur de recopie
        valeur++;
        return temp;
    }

    int get_valeur() const { return valeur; }
};

// Fonction illustrant le retour d'objet (Sujet à l'optimisation NRVO)
Compteur creer_compteur_initialise(int v) {
    Compteur c(v);
    return c; // NRVO : Le compilateur optimise le retour sans copie inutile
}

// ==================================================
// MAIN PRINCIPAL
// ==================================================

int main() {
    cout << "==================================================" << endl;
    cout << " 1. HÉRITAGE ET ORDRE DE CONSTRUCTION / DESTRUCTION" << endl;
    cout << "==================================================" << endl;
    {
        Etudiant e("Alice", 22001234);
        e.afficher_etudiant();
        cout << "--> Sortie du bloc : destruction dans l'ordre inverse (Etudiant puis Personne) :" << endl;
    }

    cout << "\n==================================================" << endl;
    cout << " 2. CONSTRUCTEUR DE COPIE & SURCHARGE DE ++ / --" << endl;
    cout << "==================================================" << endl;
    Compteur c1(10);
    
    cout << "Copie explicite (c2 = c1) :" << endl;
    Compteur c2 = c1; // Appel du constructeur de recopie

    cout << "\nPré-incrémentation (++c1) : ";
    ++c1;
    cout << "Nouvelle valeur c1 = " << c1.get_valeur() << endl;

    cout << "Post-incrémentation (c2++) : ";
    Compteur ancien = c2++;
    cout << "Valeur retournee = " << ancien.get_valeur() 
         << " | Valeur finale c2 = " << c2.get_valeur() << endl;

    cout << "\nAppel de fonction retournant un objet (NRVO) :" << endl;
    Compteur c3 = creer_compteur_initialise(100);

    cout << "\n==================================================" << endl;
    cout << " 3. STL : STD::MAP & STD::SET" << endl;
    cout << "==================================================" << endl;

    // --- std::map (Clé / Valeur) ---
    cout << "-> Utilisation de std::map<string, int> :" << endl;
    map<string, int> notes;
    notes["Alice"] = 18;
    notes["Bob"] = 14;
    notes["Charlie"] = 16;

    // Parcours avec itérateur bidirectionnel
    for (map<string, int>::const_iterator it = notes.begin(); it != notes.end(); ++it) {
        cout << "   Etudiant : " << it->first << " | Note : " << it->second << endl;
    }

    // --- std::set (Valeurs uniques triées) ---
    cout << "\n-> Utilisation de std::set<int> :" << endl;
    set<int> ensemble;
    ensemble.insert(30);
    ensemble.insert(10);
    ensemble.insert(30); // Ignoré car doublon !
    ensemble.insert(20);

    cout << "   Eléments du set (automatiquement triés et uniques) : ";
    for (set<int>::const_iterator it = ensemble.begin(); it != ensemble.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}