# CM3 : Allocation Dynamique, Gestion de la Mémoire et Makefile

## 1. La Mémoire : Pile (Stack) vs Tas (Heap)

- **La Pile (Stack) :** Utilisée pour les variables locales d'une fonction. Ces variables sont automatiquement détruites à la sortie du bloc ou de la fonction. Il ne faut jamais retourner l'adresse d'une variable locale.
- **Le Tas (Heap) :** Espace mémoire utilisé pour l'allocation dynamique. Les objets y restent en mémoire jusqu'à ce qu'ils soient explicitement libérés par le développeur.

## 2. Allocation Dynamique (stdlib.h)

L'allocation dynamique permet de réserver de la mémoire pendant l'exécution du programme, indispensable pour créer des tableaux dont on ne connaît la taille qu'à l'exécution.

- `malloc(size_t size)` : Alloue un bloc de mémoire de `size` octets. Le contenu n'est pas initialisé.
- `calloc(size_t nitems, size_t size)` : Alloue un bloc pour un tableau de `nitems` éléments de taille `size`, et initialise tous les bits à 0.
- `realloc(void *ptr, size_t size)` : Modifie la taille d'un bloc de mémoire précédemment alloué. Peut déplacer le bloc en mémoire si nécessaire.
- `free(void* ptr)` : Libère la mémoire allouée dynamiquement. Oublier de faire un `free` crée une fuite de mémoire (memory leak).

## 3. Contrôle de la mémoire avec Valgrind

- `valgrind ./executable` permet de détecter les erreurs de mémoire.
- Il détecte les fuites mémoires (`definitely lost`), les désallocations incorrectes (ex: double `free()`), ainsi que les lectures/écritures invalides (débordement de tableau ou accès à une zone libérée).

## 4. Automatisation avec Makefile

- Permet d'automatiser la compilation avec la commande `make`.
- **Structure :** `cible : dépendances`.
- **Variables spéciales :** `$@` (nom de la cible), `$^` (toutes les dépendances), `$<` (première dépendance).
-
