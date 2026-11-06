#include "Point.hpp"

using namespace std;

Point::Point() : x(0.0), y(0.0) {
    cout << "  [Point] Constructeur par defaut appele (0, 0)" << endl;
}

Point::Point(double x, double y) : x(x), y(y) {
    cout << "  [Point] Constructeur parametre appele (" << x << ", " << y << ")" << endl;
}

Point::~Point() {
    cout << "  [Point] Destructeur appele pour (" << x << ", " << y << ")" << endl;
}

void Point::afficher() const {
    cout << "Point(" << x << ", " << y << ")" << endl;
}