# CM2 : Modularité, Tableaux et Pointeurs

## 1. Modularité (Séparation des fichiers)

- Pour bien structurer un programme C, on sépare les déclarations et les implémentations.
- **Le fichier d'en-tête (`.h`) :** Contient les prototypes des fonctions.
- Pour éviter les inclusions multiples, on utilise les directives de préprocesseur `#ifndef`, `#define` et `#endif`.
- **Le fichier source (`.c`) :** Contient le code des fonctions (l'implémentation) et inclut le fichier `.h` correspondant.

## 2. Les Tableaux

- Un tableau réserve une zone mémoire contiguë pour stocker plusieurs éléments du même type.
- Déclaration classique : `int tableau[4];`.
- Initialisation directe : `int tableau[4] = {1, 2, 3, 4};`.
- **Attention :** Un tableau est une variable non modifiable (on ne peut pas faire `tab1 = tab2`).
- Lorsqu'on passe un tableau à une fonction, le paramètre contient l'adresse du premier élément, il faut donc toujours passer la taille en argument supplémentaire.

## 3. Les Pointeurs et la Mémoire

- Toute variable possède une adresse mémoire, qu'on récupère avec l'opérateur `&`.
- Un pointeur est une variable qui contient l'adresse mémoire d'une autre variable.
- Syntaxe de déclaration : `int *ptr;`.
- Déréférencement : l'opérateur `*` permet d'accéder ou de modifier la valeur pointée (ex: `*ptr = 12;`).
- **Passage par valeur :** Les arguments d'une fonction sont copiés dans des variables locales, les modifications n'affectent pas les variables d'origine.
- **Passage par variable :** On passe l'adresse mémoire (`&var`) à la fonction, ce qui lui permet de modifier la variable d'origine (très utile pour une fonction d'échange).
- Il ne faut jamais retourner l'adresse d'une variable locale à une fonction, car celle-ci est détruite à la fin du bloc.
