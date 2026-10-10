#include <stdio.h>
#include <stdlib.h>
#include "personne.h"

/* --- Fonction de comparaison pour qsort (Pointeur de fonction) --- */
int comparer_entiers(const void *a, const void *b) {
    // 1. On "cast" les pointeurs void* en int*
    // 2. On les déréférence avec * pour obtenir les valeurs
    int val_a = *(int*)a;
    int val_b = *(int*)b;
    
    return val_a - val_b; // <0 si a < b, 0 si a == b, >0 si a > b
}

int main(void) {
    /* ==========================================================
     * 1. ENCAPSULATION (Structures cachées)
     * ========================================================== */
    puts("--- 1. ENCAPSULATION ---");
    
    // On ne peut passer que par les fonctions. 
    // Faire p1->age = 40; générerait une erreur de compilation.
    Personne p1 = creer_personne("Ada Lovelace", 36);
    afficher_personne(p1);
    
    // Libération mémoire
    liberer_personne(&p1);


    /* ==========================================================
     * 2. GÉNÉRICITÉ ET POINTEURS DE FONCTIONS (qsort)
     * ========================================================== */
    puts("\n--- 2. QSORT (GENERICITE) ---");
    
    int tableau[5] = {88, 56, 100, 2, 25};
    
    printf("Avant le tri : ");
    for(int i = 0; i < 5; i++) printf("%d ", tableau[i]);
    printf("\n");

    /* Utilisation de qsort :
     * 1. Le tableau (converti implicitement en void*)
     * 2. Le nombre d'éléments
     * 3. La taille d'un élément (sizeof)
     * 4. Le nom de la fonction de comparaison (sert de pointeur de fonction)
     */
    qsort(tableau, 5, sizeof(int), comparer_entiers);

    printf("Apres le tri : ");
    for(int i = 0; i < 5; i++) printf("%d ", tableau[i]);
    printf("\n");

    return EXIT_SUCCESS;
}