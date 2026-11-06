# C++ Episode 1 : Bases, Références, Classes et STL

## 1. Nouveautés C++98 par rapport au C99

- **Compilateur** : `g++ -std=c++98 -Wall -Wextra -pedantic`
- **Fichiers** : En-tête `.hpp` et source `.cpp`.
- **Entrées/Sorties (`<iostream>`)** : `std::cout << ... << std::endl;` et `std::cin >> var;`.

## 2. Passage par Référence (`&`)

- Une référence (`int &ref = x;`) agit comme un alias direct sur la variable.
- Permet le passage par référence dans les fonctions (`void echanger(int &a, int &b)`) de façon plus sûre et lisible sans utiliser de pointeurs explicitement.

## 3. Allocation Dynamique (`new` / `delete`)

- Allocation simple : `int *p = new int;` -> Libération : `delete p;`
- Allocation tableau : `int *tab = new int;` -> Libération : `delete[] tab;`

## 4. Classes (`class`) et Encapsulation

- `class` a ses membres **privés par défaut** (`private:`), tandis que `struct` les a publics.
- **Constructeurs** : Initialisent l'objet (`Point()`, `Point(double x, double y)`).
- **Destructeur** : Déclaré avec `~NomClasse()`, libère les ressources lors de la destruction de l'objet.
- **Pointeur `this`** : Pointeur implicite vers l'instance courante (`this->x`).

## 5. Conteneurs STL (`string` et `vector`)

- `std::string` : Chaine d'objets modifiable (`s1 + s2`, `s.c_str()`).
- `std::vector<type>` : Tableau dynamique automatique (`v.size()`, `v.push_back()`, itérateurs `v.begin()` / `v.end()`).
