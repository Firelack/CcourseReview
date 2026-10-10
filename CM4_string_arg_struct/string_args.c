/* Compilation : gcc -std=c99 -Wall -Wextra -pedantic -o exec string_args.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Indispensable pour les chaînes

// Utilisation de argc et argv pour lire la ligne de commande
int main(int argc, char **argv) {
    puts("--- ARGUMENTS ---");
    printf("Nombre d'arguments (argc) : %d\n", argc);
    
    // Si on passe des arguments, on peut les convertir
    if (argc == 3) {
        int a = atoi(argv[1]); // Convertit la chaîne argv[1] en int
        int b = atoi(argv[2]);
        printf("Somme des arguments : %d + %d = %d\n", a, b, a + b);
    }

    puts("\n--- CHAINES DE CARACTERES ---");
    
    // 1. Tableau (Mutable)
    char mutable[10] = "pipoo";
    mutable[0] = 'P'; // OK, on peut modifier
    printf("Chaine mutable : %s\n", mutable);

    // 2. Pointeur (Non Mutable / Constante)
    char *immuable = "chaine";
    // immuable[0] = 'C'; -> ERREUR DE SEGMENTATION !
    printf("Chaine immuable : %s\n", immuable);

    puts("\n--- STRING.H ---");
    
    // Allocation dynamique d'une chaîne (attention à laisser la place pour '\0')
    char *dyn = malloc(50 * sizeof(char));
    
    // strcpy : Copier une chaîne
    strcpy(dyn, "Bonjour");
    
    // strcat : Concaténer (ajouter à la fin)
    strcat(dyn, " le monde"); 
    printf("Chaine dynamique : %s\n", dyn); 

    // strcmp : Comparer deux chaînes
    char *test1 = "test 1";
    char *test2 = "test 2";
    printf("Comparaison : %d (0 = identiques)\n", strcmp(test1, test2));

    free(dyn);
    return EXIT_SUCCESS;
}