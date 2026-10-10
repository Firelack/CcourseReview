#include "fonctions.h"

int* creer_tableau(int taille) {
    // Allocation sur le tas (Heap) de 'taille' entiers
    int *tab = malloc(sizeof(int) * taille);
    
    // Initialisation
    for(int i = 0; i < taille; i++) {
        tab[i] = i;
    }
    return tab; // Valide car le tableau est sur le tas, pas sur la pile
}

int* copier_tableau(int *tableau, int taille) {
    int *tableau_copie = malloc(taille * sizeof(int));
    
    // Copie de taille*sizeof(int) octets de tableau vers tableau_copie
    memcpy(tableau_copie, tableau, taille * sizeof(int));
    
    return tableau_copie;
}

int** creer_matrice(int lignes, int colonnes) {
    // Allocation du tableau de pointeurs (les lignes)
    int** tab = malloc(lignes * sizeof(int*));
    
    // Allocation de chaque ligne
    for(int i = 0; i < lignes; i++) {
        tab[i] = malloc(colonnes * sizeof(int));
    }
    return tab;
}

void liberer_matrice(int **matrice, int lignes) {
    // Il faut libérer chaque sous-tableau avant le tableau principal
    for(int i = 0; i < lignes; i++) {
        free(matrice[i]);
    }
    free(matrice);
}