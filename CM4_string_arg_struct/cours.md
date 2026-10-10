# CM4 : Chaînes de caractères, Arguments et Structures

## 1. Les Chaînes de caractères

- En C, il n'y a pas de type `String`. Une chaîne est un tableau de caractères (`char`) qui se termine **toujours** par le caractère nul `\0`.
- **Tableau (Mutable) :** `char chaine[] = "test";` (on peut modifier les lettres).
- **Pointeur (Lecture seule) :** `char *chaine = "test";` (impossible de modifier les lettres, cela provoque une erreur de segmentation).
- Si on alloue une chaîne dynamiquement avec `malloc`, il ne faut pas oublier de compter +1 pour le `\0`.

## 2. La bibliothèque `<string.h>`

Fournit les outils indispensables pour manipuler les chaînes :

- `strlen(str)` : Retourne la longueur de la chaîne (sans compter le `\0`).
- `strcpy(dest, src)` : Copie `src` dans `dest`.
- `strcat(dest, src)` : Concatène (ajoute) `src` à la fin de `dest`.
- `strcmp(str1, str2)` : Compare deux chaînes (retourne 0 si elles sont identiques).
- `strchr(str, c)` : Cherche la première occurrence du caractère `c`.

## 3. Les Arguments du programme (argc / argv)

- `int main(int argc, char **argv)` permet de lire les paramètres passés dans le terminal.
- `argc` : Le nombre d'arguments (le nom du programme compte comme 1).
- `argv` : Le tableau contenant les arguments sous forme de chaînes.
- **Conversion :** Pour utiliser un argument comme un nombre, on utilise `atoi()` (pour un entier) ou `atof()` (pour un décimal) via `<stdlib.h>`.

## 4. Les Constantes et Pointeurs

- `const int *ptr` : Pointeur sur une constante (on ne peut pas modifier la valeur pointée).
- `int *const ptr` : Pointeur constant (on ne peut pas faire pointer le pointeur ailleurs).
- `const int *const ptr` : Les deux à la fois.

## 5. Les Structures (`struct`)

- Permettent de regrouper plusieurs variables de types différents sous un même nom.
- **Accès statique :** On utilise le point `.` (ex: `ma_struct.age`).
- **Accès dynamique (via pointeur) :** On utilise la flèche `->` (ex: `ptr_struct->age`), ce qui équivaut à `(*ptr_struct).age`.
- L'utilisation de `typedef` permet de renommer la structure pour ne plus avoir à écrire le mot-clé `struct` à chaque fois.
