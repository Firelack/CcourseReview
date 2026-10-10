/* Compilation : gcc -std=c99 -Wall -Wextra -pedantic -o exec struct.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- DECLARATION DE STRUCTURE --- */
// Définition classique
struct une_structure {
    char *nom;
    int age;
};

// Utilisation de typedef pour simplifier le nom (Concept Objet/Encapsulation)
typedef struct une_structure Personne;

int main(void) {
    puts("--- STRUCTURE STATIQUE ---");
    // Création statique sur la pile
    Personne p1;
    p1.nom = "Dupont";
    p1.age = 33;
    // Accès avec le point '.'
    printf("Personne 1 : %s, %d ans\n", p1.nom, p1.age);

    puts("\n--- STRUCTURE DYNAMIQUE (POINTEUR) ---");
    // Création dynamique sur le tas (malloc)
    Personne *p2 = malloc(sizeof(Personne));
    
    // Allocation interne pour la chaîne de caractères (bonne pratique)
    p2->nom = malloc(50 * sizeof(char));
    strcpy(p2->nom, "Moby");
    
    // Accès avec la flèche '->' (équivalent à (*p2).age)
    p2->age = 40; 
    (*p2).age = 41; // Syntaxe alternative (moins lisible)

    printf("Personne 2 : %s, %d ans\n", p2->nom, p2->age);

    // Libération : toujours libérer le contenu AVANT le contenant
    free(p2->nom); 
    free(p2); 

    return EXIT_SUCCESS;
}