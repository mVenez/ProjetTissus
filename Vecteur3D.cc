#include <iostream>
#include "Vecteur3D.h"
using namespace std;

void Vecteur3D::set_coord(int coordinate, double value) {
    if (coordinate == 0) {x = value;}
    else if (coordinate == 1) {y = value;}
    else if (coordinate == 2) {z = value;}
    else {cout << "La coordonnée choisie n'existe pas" << endl;}
}
void Vecteur3D::affiche() {cout << x << ' ' << y << ' ' << z << endl;};
bool Vecteur3D::compare(Vecteur3D v) {
    return (x == v.x and y == v.y and z == v.z);
}

