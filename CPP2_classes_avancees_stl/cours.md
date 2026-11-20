# C++ Épisode 2 : Constructeur de Copie, Héritage et STL Avancée (CM2cpp)

## 1. Liste d'Initialisation des Constructeurs
* **Syntaxe** : `Classe::Classe(type arg) : attribut1(arg), attribut2(valeur) { }`
* **Obligatoire pour** :
  * Les attributs `const` et les références `&`.
  * L'appel au constructeur de la classe de base (parent) en cas d'héritage.
  * Les objets membres n'ayant pas de constructeur par défaut.

## 2. Constructeur de Recopie (Copy Constructor) & NRVO
* **Constructeur par recopie** (`NomClasse(const NomClasse& autre)`) : Appelé lors du passage par valeur, de la création d'un objet par copie (`Point p2 = p1;`) ou du retour d'objet.
* **Copie profonde vs Copie naïve** : Nécessaire dès qu'une classe alloue de la mémoire dynamique (`new`) pour éviter le double `delete` à la destruction.
* **NRVO (Named Return Value Optimization)** : Optimisation du compilateur qui élimine la création de copies temporaires lors du retour d'un objet local nommé dans une fonction.

## 3. Surcharge des Opérateurs (`++` et `--`)
* **Pré-incrémentation (`++x`)** : Modifie l'objet et renvoie l'objet lui-même par référence (`Type& operator++()`).
* **Post-incrémentation (`x++`)** : Copie l'état initial, incrémente l'objet, puis renvoie la copie temporaire par valeur (`Type operator++(int)` avec un paramètre muet `int`).

## 4. Héritage (Parent / Enfant)
* **Syntaxe** : `class Etudiant : public Personne { ... };`
* **Ordre d'exécution** :
  * **Construction** : Constructeur Parent d'abord, puis Constructeur Enfant.
  * **Destruction** : Destructeur Enfant d'abord, puis Destructeur Parent.

## 5. STL : Conteneurs & Itérateurs
* **Séquentiels** : `std::vector` (tableau dynamique), `std::list` (liste doublement chaînée).
* **Associatifs** : 
  * `std::map<Key, Value>` : Paires clé/valeur triées par clé (`it->first`, `it->second`).
  * `std::set<T>` : Ensemble d'éléments uniques triés.
* **Itérateurs** :
  * `RandomAccessIterator` (`vector`) : `++`, `--`, `+n`, `[]`.
  * `BidirectionalIterator` (`map`, `set`, `list`) : `++`, `--`.