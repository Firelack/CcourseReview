#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point {
private:
    double x;
    double y;

public:
    // Constructeur par défaut
    Point();
    // Constructeur avec paramètres
    Point(double x, double y);
    // Destructeur
    ~Point();

    // Méthodes
    void afficher() const;
    double get_x() const { return x; }
    double get_y() const { return y; }
};

#endif