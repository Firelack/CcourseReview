# Variables de compilation
CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -pedantic -Wno-abi -ggdb
# On peut également rajouter exe = nom_executable pour changer le nom de l'exécutable 
# En modifiant les apparitions de executable par $(exe) dans le makefile

# Lancer le programme principal
run : executable
	./executable

# Cible principale
all : executable

# Édition de liens
executable : fonctions.o main.o
	$(CC) -o $@ $^

# Compilation séparée
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour tester avec valgrind
memoire : executable
	valgrind ./executable

# Nettoyage
clean : 
	rm -f *.o executable