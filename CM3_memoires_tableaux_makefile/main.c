#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"

int main(void) {
    /* --- 1. MALLOC SIMPLE ET VERIFICATION --- */
    puts("--- ALLOCATION SIMPLE ---");
    int *pointeur = malloc(sizeof(int));
    
    if (pointeur == NULL) {
        fputs("erreur memoire", stderr);
        return EXIT_FAILURE;
    }
    *pointeur = 12;
    printf("Valeur pointee : %d\n", *pointeur);
    free(pointeur); // Toujours libérer !

    /* --- 2. TABLEAUX DYNAMIQUES ET MEMCPY --- */
    puts("\n--- TABLEAUX DYNAMIQUES ---");
    int taille = 5;
    
    // Appel d'une fonction qui alloue et retourne un tableau
    int *tab = creer_tableau(taille);
    
    // Copie rapide avec memcpy
    int *tab_copie = copier_tableau(tab, taille);
    
    printf("Copie (index 3) : %d\n", tab_copie[3]);

    /* --- 3. REALLOCATION --- */
    puts("\n--- REALLOCATION ---");
    int nouvelle_taille = 10;
    // Réalloue l'espace, déplace si nécessaire et gère le free de l'ancien bloc
    int *ptr_rea = realloc(tab, sizeof(int) * nouvelle_taille);
    
    if (ptr_rea != NULL) {
        tab = ptr_rea; // Mise à jour du pointeur
        tab[9] = 42;
        printf("Nouvelle valeur allouee : %d\n", tab[9]);
    }

    // Libération des tableaux 1D
    free(tab);
    free(tab_copie);

    /* --- 4. MATRICES (2D) --- */
    puts("\n--- MATRICE 2D ---");
    int lignes = 3;
    int colonnes = 4;
    
    int **matrice = creer_matrice(lignes, colonnes);
    matrice[2][3] = 99;
    printf("Matrice[2][3] = %d\n", matrice[2][3]);
    
    // Libération complexe requise pour le multi-dimensionnel
    liberer_matrice(matrice, lignes);

    return EXIT_SUCCESS;
}