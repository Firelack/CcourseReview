# Récapitulatif Global - Programmation Impérative (Langage C)

## CM1 : Bases, Compilation et Contrôles

### 1. Processus de compilation

Le code source `.c` est transformé en exécutable en 4 étapes :

1. **Préprocesseur** : Gère les directives `#` (comme `#include`) et les remplacements de texte.
2. **Compilateur** : Traduit le code C en code assembleur.
3. **Assembleur** : Transforme le code assembleur en fichier binaire (fichier objet `.o`).
4. **Éditeur de liens (Linker)** : Relie les fichiers objets et les bibliothèques externes pour créer l'exécutable.

- **Commande stricte recommandée** : `gcc -std=c99 -Wall -Wextra -pedantic -o exec main.c`

### 2. Types, Variables et Affichage (`printf`)

- **Types de base** : `int`, `float`, `double`, `char`. `sizeof(type)` donne la taille en octets.
- **Spécificateurs de format** :
  - `%d` (entier), `%u` (non signé), `%o` (octal), `%x` (hexa)
  - `%f` (flottant), `%e` (scientifique)
  - `%c` (caractère), `%s` (chaîne), `%p` (adresse pointeur)
- **Astuces d'affichage** : `%4.2f` (2 chiffres après la virgule), `%05d` (complète avec des zéros).

### 3. Opérateurs et Boucles

- **Opérateurs bit à bit** : `~` (non), `<<` / `>>` (décalages), `&` (et), `|` (ou), `^` (ou exclusif).
- **Contrôles** : `if / else if / else`, `switch / case / default` (attention au `break`).
- **Boucles** : `for` (itératif), `while` (test avant), `do while` (test après, exécute au moins une fois).
- `continue` passe à l'itération suivante, `break` sort de la boucle.

## CM2 : Modularité, Tableaux et Pointeurs

### 1. Modularité (Fichiers multiples)

- **Fichier d'en-tête (`.h`)** : Contient les prototypes des fonctions. Utiliser `#ifndef`, `#define` et `#endif` pour éviter les inclusions multiples (penser aux docstrings).
- **Fichier source (`.c`)** : Contient l'implémentation (le code) des fonctions.
- **Fichier main (`main.c`)** : Contient le programme principal.

> Note : à toujours utiliser dans les projets.

### 2. Les Tableaux

- Un tableau est un espace mémoire contigu de taille fixe : `int tab[5] = {1, 2, 3, 4, 5};`
- C'est une variable _non modifiable_ : on ne peut pas réaffecter un tableau entier à un autre (`tab1 = tab2` est interdit).
- Passé en paramètre de fonction, il se comporte comme un pointeur vers son premier élément. Il faut toujours passer sa taille en argument supplémentaire.

### 3. Les Pointeurs et la Mémoire

- L'opérateur `&` permet d'obtenir l'adresse mémoire d'une variable.
- Un pointeur stocke une adresse mémoire : `int *ptr = &variable;`
- L'opérateur `*` (déréférencement) permet d'accéder à / modifier la valeur stockée à cette adresse (`*ptr = 10;`).
- **Passage par valeur** : La fonction crée une copie locale de la variable.
- **Passage par variable** : On donne l'adresse (`&x`) à la fonction. La fonction utilise un pointeur (`*x`) pour modifier directement la variable d'origine. Ne jamais retourner l'adresse d'une variable locale.

## CM3 : Allocation Dynamique et Makefile

### 1. Pile (Stack) vs Tas (Heap)

- **Pile** : Allocation automatique des variables locales (nettoyée à la fin d'un bloc).
- **Tas** : Allocation manuelle via code, reste en mémoire tant qu'on ne l'efface pas.

### 2. Allocation Dynamique (`<stdlib.h>`)

- `malloc(taille)` : Alloue un bloc mémoire non initialisé.
- `calloc(nb, taille)` : Alloue et initialise tous les octets à 0.
- `realloc(ptr, taille)` : Agrandit ou rétrécit un bloc existant (déplace si besoin).
- `free(ptr)` : Libère l'espace mémoire. Tout ce qui est "malloc" doit être "free".
- **Tableaux 2D (Matrices)** : On alloue d'abord un tableau de pointeurs, puis on alloue un tableau pour chaque ligne. Pour libérer, on fait l'inverse (les lignes, puis le tableau principal).

### 3. Outils

- **Valgrind** : Outil pour traquer les erreurs de mémoire (fuites, double free, accès hors limites). `valgrind ./executable`.
- **Makefile** : Permet d'automatiser les commandes de compilation via des "cibles" et des "dépendances".

> Note : Toujours mettre un makefile complet avec valgrind, les executions doivent passer le valgrind sans erreurs.

## CM4 : Chaînes de caractères, Arguments et Structures

### 1. Les Chaînes de caractères

- Il n'y a pas de type "String". Une chaîne est un tableau de caractères terminé par `\0`.
- `char tab[] = "test";` (Mutable : modifiable) vs `char *ptr = "test";` (Immuable : lecture seule).
- **`<string.h>`** : `strlen` (taille), `strcpy` (copier), `strcat` (concaténer), `strcmp` (comparer), `strchr` (chercher un char).

### 2. Arguments du programme

- `int main(int argc, char **argv)`
- `argc` : Nombre d'arguments (l'exécutable compte pour 1).
- `argv` : Tableau contenant les mots tapés dans le terminal.
- On utilise `atoi()` ou `atof()` pour convertir les arguments texte en nombres.

### 3. Structures (`struct`)

- Regroupe plusieurs variables sous une seule entité logique.
- Accès statique avec un point : `structure.champ`.
- Accès via pointeur avec la flèche : `ptr_struct->champ` (équivalent à `(*ptr_struct).champ`).
- `typedef` permet de créer un alias pour ne pas avoir à réécrire `struct` partout.

## CM5 : Encapsulation, Généricité et Pointeurs de fonctions

### 1. Encapsulation (Cacher les données)

- Simule la POO. On empêche le `main` d'accéder directement aux variables d'une structure pour forcer l'usage des fonctions (getters/setters/constructeurs).
- On définit un type opaque dans le `.h` (`typedef struct pers* Personne;`) et on détaille la vraie structure uniquement dans le `.c`.

### 2. Généricité (`void*`)

- Le pointeur `void*` peut stocker l'adresse de n'importe quel type de donnée.
- Il ne peut pas être déréférencé directement : il faut d'abord le "caster" (`*(int*)ptr`).
- `memcpy` est utilisé pour copier des données génériques dont on ne connaît que la taille en octets.

### 3. Pointeurs de fonctions

- Permet de passer une fonction en paramètre d'une autre fonction.
- Déclaration : `int (*nom_pointeur)(int, int);`
- **Cas pratique (`qsort`)** : La fonction de tri de `<stdlib.h>` utilise la généricité et les pointeurs de fonctions pour trier n'importe quel tableau. Elle a besoin qu'on lui fournisse une fonction de comparaison (`int comparer(const void *a, const void *b)`).

## CPP1 : Introduction au C++98, Références, Classes et STL

### 1. Du C99 au C++98

- **Compilateur et Fichiers** : Compilation avec `g++ -std=c++98 -Wall -Wextra -pedantic`. Utilisation des extensions `.hpp` pour les en-têtes et `.cpp` pour les fichiers sources.
- **Entrées/Sorties (`<iostream>`)** : Remplacement de `printf`/`scanf` par les flux `std::cout << ... << std::endl;` et `std::cin >> var;`.
- **Espaces de noms (`namespace`)** : Permettent d'isoler les identificateurs pour éviter les collisions de noms (ex: `using namespace std;` ou `std::cout`).

### 2. Passages par Référence (`&`)

- Une référence (`int &ref = x;`) agit comme un alias direct sur une variable existante.
- **Passage par référence dans les fonctions** : `void echanger(int &a, int &b)` permet de modifier directement les variables transmises sans manipuler la syntaxe des pointeurs (`*a`) ni passer d'adresses (`&x`) lors de l'appel.

### 3. Allocation Dynamique (`new` / `delete`)

- **Élément simple** : `int *p = new int(42);` -> Libération avec `delete p;`.
- **Tableau dynamique** : `int *tab = new int[n];` -> Libération obligatoire avec `delete[] tab;`.

### 4. Classes (`class`) et Encapsulation

- **Membres privés par défaut** (`private:`), contrairement aux `struct` où les membres sont publics par défaut.
- **Constructeurs et Destructeur** : Initialisation des instances (`Point()`, `Point(double x, double y)`) et libération des ressources à la destruction de l'objet via `~Point()`.
- **Pointeur `this`** : Pointeur implicite vers l'instance courante de la classe (`this->x`).

### 5. Conteneurs de la STL (`string` et `vector`)

- **`std::string`** : Objet chaîne modifiable avec concaténation directe (`+`), taille (`.size()`) et conversion en C-string (`.c_str()`).
- **`std::vector<T>`** : Tableau dynamique gérant automatiquement sa taille et sa mémoire (`.push_back()`, `.size()`, accès par crochets `[]`).
- **Itérateurs** : Objets permettant de parcourir n'importe quel conteneur de manière uniforme (`std::vector<int>::iterator it = v.begin(); it != v.end(); ++it`).

## CPP2 : Constructeur de Copie, Liste d'Initialisation, Héritage et STL Avancée

### 1. Constructeur par Recopie (Copy Constructor)
* **Utilité** : Appelé lors du passage d'un objet par valeur, de la création d'un objet par copie (`NomClasse b = a;`) ou du retour d'un objet par une fonction.
* **Syntaxe** : `NomClasse(const NomClasse& obj);`.
* **Copie naïve vs Copie profonde** :
  * *Par défaut* : Le compilateur effectue une copie membre à membre (copie naïve).
  * *Problème avec les pointeurs* : Si un objet contient un pointeur alloué dynamiquement, la copie naïve copie simplement l'adresse mémoire. La destruction des deux objets provoquera un double `delete` (crash mémoire).
  * *Copie profonde* : Il faut réallouer de la mémoire sur le tas et copier le contenu pointé.

### 2. Liste d'Initialisation des Constructeurs
* **Syntaxe** : `Classe::Classe(type arg) : attribut1(arg), attribut2(valeur) { ... }`.
* **Pourquoi l'utiliser ?** :
  * Initialise directement les membres avant l'exécution du corps du constructeur (évite une construction par défaut suivie d'une réaffectation).
  * **Obligatoire** pour les attributs `const`, les références `&`, les objets sans constructeur par défaut et l'appel au constructeur de la classe de base.

### 3. Surcharge des Opérateurs d'Incrémentation et Décrémentation (`++` et `--`)
* **Pré-incrémentation (`++x`)** : Modifie l'objet et renvoie l'objet lui-même par référence.
  * Signature : `Type& operator++();`
* **Post-incrémentation (`x++`)** : Sauvegarde une copie de l'état actuel, incrémente l'objet, puis renvoie la copie temporaire par valeur.
  * Signature : `Type operator++(int);` *(l'argument `int` est un paramètre muet fictif servant uniquement à différencier la signature du préfixe)*.

### 4. Notions de base de l'Héritage
* **Syntaxe** : `class Etudiant : public Humain { ... };`.
* **Appel du constructeur parent** : Réalisé dans la liste d'initialisation : `Etudiant::Etudiant(string nom, long ine) : Humain(nom), INE(ine) { }`.
* **Ordre de construction & destruction** :
  * **Construction** : Classe de base (Parent) d'abord, puis classe dérivée (Enfant).
  * **Destruction** : Classe dérivée (Enfant) d'abord, puis classe de base (Parent).

### 5. STL : Conteneurs Associatifs (`std::map`) et Types d'Itérateurs
* **`std::map<Key, Value>`** :
  * Conteneur associatif stockant des paires clé/valeur.
  * Accès/Insertion : `m[cle] = valeur;` (si la clé n'existe pas, elle est créée automatiquement).
  * Lecture via itérateur : `it->first` donne la clé, `it->second` donne la valeur.
* **Catégories d'itérateurs** :
  * **`RandomAccessIterator`** (`vector`, `deque`) : Supporte `++`, `--`, `+n`, `-n`, `[]`.
  * **`BidirectionalIterator`** (`list`, `map`, `set`) : Supporte uniquement `++` et `--`.
  * **`ForwardIterator`** (`forward_list`, `unordered_set`) : Supporte uniquement `++`.

## CPP3 : Héritage Avancé, Polymorphisme et Classes Abstraites

### 1. Upcasting, Downcasting et Slicing
* **Upcasting** : Conversion d'une classe fille vers une classe mère (implicite : `Personne &p = e;`).
* **Downcasting** : Conversion d'une classe mère vers une classe fille (explicite : `Etudiant &ep = static_cast<Etudiant&>(p);`).
* **Slicing** : Perte de la partie spécifique lors d'une copie par valeur d'un objet dérivé dans un objet de base (`Personne p = e;`).

### 2. Héritage Multiple et Principe de Liskov (LSP)
* **Héritage Multiple** : Une classe fille hérite de plusieurs mères. Résolution des ambiguïtés via l'opérateur de portée (`obj.ClasseMere::methode()`).
* **Principe de substitution de Liskov (LSP)** : Un objet sous-type doit pouvoir remplacer un objet de type de base sans altérer le bon fonctionnement du programme.

### 3. Polymorphisme, Méthodes Virtuelles et Classes Abstraites
* **Liaison Dynamique (`virtual`)** : L'appel d'une méthode `virtual` via un pointeur/référence appelle la version du type réel à l'exécution (*Late Binding*).
* **Destructeur Virtuel** : **OBLIGATOIRE** (`virtual ~Base()`) pour détruire correctement les classes dérivées via un pointeur de base.
* **Virtuel Pur (`= 0`) et Classe Abstraite** : Une méthode `virtual void f() = 0;` rend la classe abstraite (**impossible à instancier**). Force la redéfinition dans les classes filles.

## CPP4 : Surcharge des Opérateurs et Fonctions Amies (friend)

### 1. Surcharge d'Opérateurs (`operator`)
* **Membres obligatoires** : `=`, `[]`, `()`, `->`.
* **Const-Correctness** : Préciser `const` sur les méthodes ne modifiant pas l'objet (`bool operator==(const Complexe &c) const;`).
* **Opérateur `=`** : Doit renvoyer `Type&` (`return *this;`) pour autoriser le chaînage (`a = b = c`).

### 2. Fonctions Amies (`friend`) et Opérateurs Libres
* **`friend`** : Autorise une fonction non-membre à accéder aux membres privés (`private`) de la classe.
* **Opérateurs libres** : Indispensables pour les flux d'entrée/sortie (`std::ostream &operator<<(std::ostream &os, const Complexe &c)`) et la commutativité des opérations (`double + Complexe`).