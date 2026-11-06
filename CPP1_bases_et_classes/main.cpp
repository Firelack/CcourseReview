/* 
 * Compilation : g++ -std=c++98 -Wall -Wextra -pedantic main.cpp Point.cpp -o main
 * Exécution   : ./main
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Point.hpp"

using namespace std;

// --- FONCTIONS AUXILIAIRES ---

// Passage par référence en C++ (&) : modifie directement les variables de l'appelant
void echanger(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// --- MAIN PRINCIPAL ---

int main() {
    cout << " 1. ENTRÉES / SORTIES ET PASSAGE PAR RÉFÉRENCE" << endl;
    
    int x = 5, y = 10;
    cout << "Avant echange : x = " << x << ", y = " << y << endl;
    echanger(x, y); // Pas besoin d'utiliser l'opérateur & lors de l'appel
    cout << "Apres echange : x = " << x << ", y = " << y << endl;

    cout << " 2. ALLOCATION DYNAMIQUE (NEW / DELETE)" << endl;
    
    // Allocation simple sur le tas
    int *pInt = new int(42);
    cout << "Valeur allouee sur le tas (*pInt) : " << *pInt << endl;
    delete pInt; // Libération de la mémoire simple

    // Allocation d'un tableau sur le tas
    size_t taille = 4;
    int *tab = new int[taille];
    for (size_t i = 0; i < taille; ++i) {
        tab[i] = (i + 1) * 10;
    }
    cout << "Elements du tableau alloue dynamiquement : ";
    for (size_t i = 0; i < taille; ++i) {
        cout << tab[i] << " ";
    }
    cout << endl;
    delete[] tab; // Libération obligatoire avec delete[] pour un tableau

    cout << " 3. UTILISATION DE LA CLASSE POINT" << endl;
    
    cout << "-> Instanciation statique sur la pile :" << endl;
    Point p1(2.5, 4.0);
    cout << "   p1 : ";
    p1.afficher();

    cout << "\n-> Instanciation dynamique sur le tas (new) :" << endl;
    Point *p2 = new Point(10.0, 20.0);
    cout << "   p2 : ";
    p2->afficher();
    
    cout << "-> Liberation de p2 (declenche le destructeur) :" << endl;
    delete p2; 

    cout << " 4. CONTENEURS STL : STD::STRING & STD::VECTOR" << endl;
    
    // std::string
    string s1 = "Hello ";
    string s2 = "C++98!";
    string s3 = s1 + s2; // Concaténation directe avec '+'
    cout << "Chaine concatenee : " << s3 << " (Taille : " << s3.size() << ")" << endl;

    // std::vector
    vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    cout << "Elements du vector (parcours avec indice) : ";
    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "Elements du vector (parcours avec iterateur) : ";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "\n-> Fin de main() (les objets de la pile vont etre detruits) :" << endl;
    return EXIT_SUCCESS;
}