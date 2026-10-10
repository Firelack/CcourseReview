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
