# CcourseReview - Programmation Impérative en C

## 🎯 Objectifs du Projet

Ce dépôt regroupe l'ensemble des concepts, syntaxes et bonnes pratiques de la programmation impérative en langage C (Module PIPOO).
Il a été conçu comme résumé mes cours de C (et C++) pour les réviser simplement et avec des exemples.

## 💻 Environnement de Développement

Les codes de ce dépôt suivent le standard C99 de manière stricte.

- **Compilateur :** `gcc` (GNU Compiler Collection).
- **Environnement recommandé :** Linux (parfaitement adapté pour une exécution sous WSL Ubuntu).
- **Outils d'analyse :** `valgrind` pour la vérification des fuites mémoires.

## 📂 Structure du Dépôt

Le projet est divisé en 5 chapitres correspondant à la progression du cours, complétés par un récapitulatif global :

- 📄 **`recap.md`** : Un résumé de tous les chapitres.

- 📁 **`CM1_bases_imperatives/`**
  - Syntaxe de base, variables, types et conversions (cast).
  - Affichage formaté avec `printf` et manipulation des bases (décimal, octal, hexa).
  - Blocs de contrôle : conditions (`if`, `switch`) et boucles (`for`, `while`, `do while`).
  - Opérateurs arithmétiques, logiques et opérations bit à bit.

- 📁 **`CM2_structures_memoires_pointeurs/`**
  - Modularité du code : séparation entre fichiers d'en-tête (`.h`) et implémentations (`.c`).
  - Manipulation des tableaux statiques.
  - Introduction à la mémoire et aux pointeurs : différence fondamentale entre le passage par valeur et le passage par adresse (pointeurs).

- 📁 **`CM3_memoires_tableaux_makefile/`**
  - La gestion manuelle de la mémoire : Différence entre la Pile (Stack) et le Tas (Heap).
  - Allocation dynamique avec `malloc`, `calloc`, `realloc` et libération avec `free`.
  - Création et libération de tableaux dynamiques à une ou plusieurs dimensions (matrices).
  - Automatisation de la compilation à l'aide de `Makefile`.

- 📁 **`CM4_string_arg_struct/`**
  - Les chaînes de caractères en C (tableaux vs pointeurs) et la gestion du caractère de fin `\0`.
  - Utilisation de la bibliothèque `<string.h>` (`strcpy`, `strcat`, `strcmp`...).
  - Récupération et traitement des arguments de la ligne de commande (`argc` et `argv`).
  - Création de structures de données (`struct` et `typedef`).

- 📁 **`CM5_genericite_plus/`**
  - Concepts avancés d'architecture logicielle : simulation de l'encapsulation (structures opaques) pour protéger les données.
  - La généricité en C avec l'utilisation des pointeurs génériques `void*`.
  - Les pointeurs de fonctions et leur utilisation pratique (ex: algorithme de tri générique `qsort`).

## 🚀 Commandes de Compilation Standard

```bash
gcc -std=c99 -Wall -Wextra -pedantic -Wno-abi -o exec main.c
```
