#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h" // Inclusion du fichier d'en-tête local

/*
# 1. Compilation des deux fichiers sources
gcc -std=c99 -Wall -Wextra -pedantic -o exec main.c fonctions.c

# 2. Exécution du programme
./exec
*/

int main(void) {
    /* --- POINTEURS ET PASSAGE PAR VARIABLE --- */
    puts("--- PASSAGE PAR VARIABLE ---");
    int a = 2;
    int b = 5;
    
    printf("Avant echange : a=%d b=%d\n", a, b);
    echange(&a, &b); // On passe les adresses en paramètres
    printf("Apres echange : a=%d b=%d\n\n", a, b);

    /* --- TABLEAUX --- */
    puts("--- TABLEAUX ---");
    int mon_tableau[5] = {1, 2, 3, 4, 5}; // Initialisation
    
    // Un pointeur peut pointer sur un tableau
    int *ptr_tab = mon_tableau;
    printf("Valeur via pointeur (index 2) : %d\n", ptr_tab[2]);
    
    // Affichage via la fonction du module
    printf("Contenu du tableau : ");
    afficher_tableau(mon_tableau, 5);

    return EXIT_SUCCESS;
}