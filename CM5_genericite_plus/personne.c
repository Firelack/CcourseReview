#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personne.h"

// Définition de la structure (invisible pour le main.c)
struct pers {
    char* nom;
    int age;
};

Personne creer_personne(char* nom, int age) {
    // Allocation de la structure
    Personne p = malloc(sizeof(struct pers));
    
    // Allocation et copie de la chaîne de caractères
    p->nom = malloc((strlen(nom) + 1) * sizeof(char));
    strcpy(p->nom, nom);
    
    p->age = age;
    return p;
}

void afficher_personne(Personne p) {
    if (p != NULL) {
        printf("Personne : %s, %d ans\n", p->nom, p->age);
    }
}

void liberer_personne(Personne *p) {
    if (*p != NULL) {
        free((*p)->nom); // Libérer d'abord les allocations internes
        free(*p);        // Libérer la structure elle-même
        *p = NULL;       // Sécuriser le pointeur d'origine
    }
}