#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

/* --- 1. PROTOTYPE DE FONCTION --- */
int maximum(int a, int b);

int main(void) {
    /* ==========================================================================
     * 2. TYPES, VARIABLES ET CONVERSIONS
     * ========================================================================== */
    puts("--- TYPES ET VARIABLES ---");

    printf("%lu octets pour un int \n", sizeof(int));
    printf("%lu octets pour un double \n", sizeof(double));

    float f1 = 3.14;
    //int i2 = 3 + f1; // Conversion implicite
    printf("(int)f1 = %d (Cast explicite)\n\n", (int)f1);

    /* ==========================================================================
     * 3. AFFICHAGE (PRINTF) ET BASES
     * ========================================================================== */
    puts("--- AFFICHAGE ---");
    printf("Char : %c | ASCII : %d \n", 'A', 'A');
    printf("Float: %4.2f | Scientifique : %e \n", 3.1416, 3.1416);
    printf("Bases -> Dec: %d | Hexa: %x | Octal: %o \n\n", 100, 100, 100);

    /* ==========================================================================
     * 4. OPÉRATEURS ET BITS
     * ========================================================================== */
    puts("--- OPERATEURS ---");
    int a = 10, c = 25;

    printf("Négation bit a bit (~a) : %d\n", ~a);
    printf("Décalage (a << 2)       : %d\n", a << 2);
    printf("ET binaire (a & c)      : %d\n", a & c);
    
    // Logique booléenne
    bool test = (!a == false); 
    printf("Test booléen : %d\n\n", test);

    /* ==========================================================================
     * 5. BLOCS ET CONTRÔLES (CONDITIONS ET BOUCLES)
     * ========================================================================== */
    puts("--- CONTROLES ---");
    
    // Conditions IF / ELSE IF / ELSE
    int x = 10;
    if (x > 15) {
        puts("x est grand");
    } else if (x == 10) {
        puts("x vaut 10");
    } else {
        puts("x est petit");
    }

    // SWITCH
    char lettre = 'A';
    switch (lettre) {
        case 'A': puts("Cas A"); break;
        default: puts("Cas defaut");
    }

    // BOUCLE FOR
    printf("For : ");
    for (int i = 0; i < 5; i++) {
        if (i == 2) continue; // Saute l'itération 2
        printf("%d ", i);
    }

    // BOUCLE WHILE (Test avant)
    printf("\nWhile : ");
    int w = 0;
    while (w < 3) {
        printf("%d ", w);
        w++;
    }

    // BOUCLE DO WHILE (Test après - s'exécute au moins une fois)
    printf("\nDo While : ");
    int dw = 0;
    do {
        printf("%d ", dw);
        dw++;
    } while (dw < 3);

    printf("\n\n");

    /* ==========================================================================
     * 6. APPEL DE FONCTION
     * ========================================================================== */
    puts("--- FONCTIONS ---");
    printf("Le maximum entre 5 et 51 est : %d\n", maximum(5, 51));

    return EXIT_SUCCESS;
}

/* ==========================================================================
 * IMPLÉMENTATION DES FONCTIONS
 * ========================================================================== */
int maximum(int a, int b) {
    // Utilisation de l'opérateur ternaire (condition ? si_vrai : si_faux)
    return (a < b) ? b : a; 
}