#include "fonctions.h"

// Passage par variable (pointeurs) pour modifier les valeurs d'origine
void echange(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

// Le tableau est passé sous forme d'adresse, il faut aussi la taille
void afficher_tableau(int tableau[], int taille) {
    for (int i = 0; i < taille; ++i) {
        printf("%d\t", tableau[i]);
    }
    puts("");
}