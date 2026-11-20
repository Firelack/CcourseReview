# C++ Épisode 4 : Surcharge des Opérateurs et Fonctions Amies (CM4cpp)

## 1. Surcharge des Opérateurs (`operator`)
* Permet de redéfinir le comportement des opérateurs (`+`, `-`, `==`, `<`, `<<`, `>>`, `=`, `[]`, etc.) pour des types personnalisés.
* **Const-Correctness** : Les méthodes d'opérateur ne modifiant pas l'objet courant doivent être déclarées `const` (ex: `bool operator<(const Point &p) const;`).

## 2. Opérateurs Membres vs Opérateurs Libres (Non-membres)
* **Méthodes membres de classe** : L'objet de gauche est l'instance courante (`this`).
  * Obligatoire pour : `=`, `[]`, `()`, `->`.
* **Fonctions libres / non-membres** : Nécessaires pour la commutativité lorsque l'élément de gauche n'est pas un objet de la classe (ex: `3.5 + complexe`).

## 3. Fonctions et Méthodes Amies (`friend`)
* Déclarée dans une classe avec le mot-clé `friend`.
* Permet à une fonction non-membre d'accéder directement aux attributs et méthodes `private` de la classe.
* **Flux d'E/S (`<<` et `>>`)** : Toujours surchargés sous forme de fonctions libres amies car `std::ostream` / `std::istream` se trouvent à gauche.

## 4. Opérateurs Unaires, Affectation et Incrémentation
* **Opérateur d'affectation (`operator=`)** : Doit renvoyer une référence sur l'objet courant (`T&`) pour permettre le chaînage (`c1 = c2 = c3`).
* **Accès par indice (`operator[]`)** : Renvoie une référence (`double&`) pour permettre la lecture/écriture (`c = 3.4`).
* **Pré-incrémentation (`++x`)** : `Type& operator++();` (renvoie l'objet courant par référence).
* **Post-incrémentation (`x++`)** : `Type operator++(int);` avec paramètre `int` fictif (renvoie une copie par valeur).
```