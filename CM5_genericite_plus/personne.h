#ifndef PERSONNE_H
#define PERSONNE_H

// Déclaration d'un type opaque : on cache l'implémentation de la structure
typedef struct pers* Personne;

// Prototypes des fonctions permettant de manipuler le type Personne
Personne creer_personne(char* nom, int age);
void afficher_personne(Personne p);
void liberer_personne(Personne *p);

#endif