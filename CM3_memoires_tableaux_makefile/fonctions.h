#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h> // Nécessaire pour memcpy

/**
 * @brief Alloue dynamiquement un tableau et l'initialise
 * @param taille Le nombre d'éléments
 * @return Un pointeur vers le tableau alloué
 */
int* creer_tableau(int taille);

/**
 * @brief Copie un tableau élément par élément via memcpy
 * @param tableau Le tableau source
 * @param taille La taille du tableau
 * @return Un pointeur vers la copie allouée dynamiquement
 */
int* copier_tableau(int *tableau, int taille);

/**
 * @brief Alloue dynamiquement une matrice 2D
 * @param lignes Le nombre de lignes
 * @param colonnes Le nombre de colonnes
 * @return Un double pointeur vers la matrice
 */
int** creer_matrice(int lignes, int colonnes);

/**
 * @brief Libère proprement une matrice 2D
 * @param matrice Le double pointeur de la matrice
 * @param lignes Le nombre de lignes à libérer
 */
void liberer_matrice(int **matrice, int lignes);

#endif