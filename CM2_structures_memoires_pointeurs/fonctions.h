/* Permet de ne pas inclure plusieurs fois la librairie */
#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdio.h>

/**
 * @brief Échange le contenu de deux variables entières en mémoire
 * @param a pointeur sur le premier entier
 * @param b pointeur sur le second entier
 */
void echange(int *a, int *b);

/**
 * @brief Affiche les éléments d'un tableau d'entiers
 * @param tableau le tableau d'entiers à afficher
 * @param taille le nombre d'éléments contenus dans le tableau
 */
void afficher_tableau(int tableau[], int taille);

#endif