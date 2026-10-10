# Processus de compilation en C

Le fichier source `.c` est traduit en langage machine en 4 étapes distinctes :

1. **Préprocesseur** : Il gère les transformations textuelles, comme l'inclusion des bibliothèques via les directives `#include`.
2. **Compilateur** : Il traduit le fichier source préparé en code assembleur (suite d'instructions pour le microprocesseur).
3. **Assembleur** : Il transforme le code assembleur en fichier binaire, appelé fichier objet.
4. **Éditeur de liens (Linker)** : Il relie les différents fichiers objets et les éventuelles bibliothèques externes pour créer le fichier exécutable final.

## Options de compilation utiles (gcc)

- `-std=c99` : Définition du standard utilisé.
- `-Wall` : Affiche les messages d'erreur standards.
- `-Wextra` : Affiche des messages d'erreur supplémentaires.
- `-pedantic` : Force une compilation ISO C stricte.
- `-o exec` : Nomme le fichier exécutable généré `exec`.
- `-main.c` : Nom du fichier C qu'on execute.

```C
gcc -std=c99 -Wall -Wextra -pedantic -o exec main.c
```

## Les configurations Git

```Bash
git config --global user.name "Ton Prénom Ton Nom"
git config --global user.email "o22402937@etu.univ-orleans.fr"

git init
# Ajout de ton dépôt Bitbucket comme destination distante (origin) (premiere creation)
git remote add origin https://o22402937@pdicost.univ-orleans.fr/git/scm/linpipoo2627/pipoo51.git
# Clone le dépot (editions suivantes)
git clone https://o22402937@pdicost.univ-orleans.fr/git/scm/linpipoo2627/pipoo51.git

git add .                  # Ajoute toutes les modifications
git commit -m "Ajout du chapitre 1 et TP1" # Crée une sauvegarde locale
git push -u origin master  # Envoie sur Bitbucket (ou 'main' selon ta branche par défaut)
```

> Note : Global à retirer si on veut le faire que sur ce dossier.
