# C++ Épisode 3 : Héritage Avancé, Polymorphisme et Classes Abstraites (CM3cpp)

## 1. Constructeurs et Héritage
* **Ordre d'appel** : Lors de la construction d'une classe fille, le constructeur par défaut de la classe mère est appelé implicitement en premier.
* **Appel explicite** : Si la classe mère n'a pas de constructeur par défaut, la classe fille doit appeler un constructeur existant dans sa liste d'initialisation.

## 2. Upcasting, Downcasting et Slicing
* **Upcasting** : Conversion implicite d'une classe dérivée vers une classe de base (`Personne &p = e;` ou `Personne *p = &e;`).
* **Downcasting** : Conversion d'une classe de base vers une classe dérivée. Nécessite un cast explicite (`Etudiant &ep = static_cast<Etudiant&>(p);`).
* **Slicing (Découpage)** : Se produit lors d'une copie par valeur d'un objet dérivé dans un objet de base (`Personne p = e;`). La partie spécifique à `Etudiant` est définitivement perdue.

## 3. Héritage Multiple et Problème du Diamant
* Une classe peut hériter de plusieurs classes (`class Bat : public Mammal, public WingedAnimal`).
* **Conflit de noms** : Si deux parents ont une méthode `f()`, l'appel `b.f()` est ambigu. Il faut préciser le sous-espace : `b.Mammal::f()`.
* **Problème du diamant** : Se produit lorsqu'une classe hérite de deux classes ayant le même parent (ex: `Doctorant` -> `Etudiant`/`Enseignant` -> `Personne`), provoquant une redondance des attributs hérités.

## 4. Principe de Substitution de Liskov (LSP)
* « Les objets d'une sous-classe doivent pouvoir remplacer des objets de la classe de base sans altérer le comportement attendu du programme. »
* *Exemple classique d'erreur* : Faire hériter `Carré` de `Rectangle` viole le LSP si les mutateurs de hauteur/largeur modifient les deux côtés à la fois.

## 5. Polymorphisme et Méthodes Virtuelles (`virtual`)
* **Liaison Statique (*Early Binding*)** : Sans `virtual`, l'appel de méthode est déterminé à la compilation selon le type statique de la variable.
* **Liaison Dynamique (*Late Binding*)** : Avec `virtual` sur pointeurs/références, la méthode appelée est déterminée à l'exécution selon le type réel de l'objet.
* **Destructeur Virtuel (`virtual ~Base()`)** : **OBLIGATOIRE** dès qu'une classe est destinée à être dérivée, afin de garantir l'appel du destructeur enfant lors d'un `delete ptr_base`.

## 6. Classes Abstraites et Virtuel Pur (`= 0`)
* **Méthode virtuelle pure** : Méthode déclarée avec `= 0` (`virtual void dessin() = 0;`).
* **Classe Abstraite** : Classe contenant au moins une méthode virtuelle pure. **Impossible à instancier** (`new Figure()` est interdit).
* Force les classes dérivées à redéfinir la méthode pour pouvoir être instanciées.