#include <iostream>
#include "Vecteur3D.h"
using namespace std;

void Vecteur3D::set_coord(int coordinate, double value) {
    if (coordinate == 0) {x = value;}
    else if (coordinate == 1) {y = value;}
    else if (coordinate == 2) {z = value;}
    else {cout << "La coordonnée choisie n'existe pas" << endl;}
}
void Vecteur3D::affiche() const {cout << x << ' ' << y << ' ' << z << endl;};

bool Vecteur3D::compare(Vecteur3D v) const {
    return (x == v.x and y == v.y and z == v.z);
}

Vecteur3D Vecteur3D::addition(Vecteur3D autre) const {
    Vecteur3D resultat;
    resultat.set_coord(0, x + autre.x);
    resultat.set_coord(0, y + autre.y);
    resultat.set_coord(0, z + autre.z);
    return resultat;
}

Vecteur3D Vecteur3D::soustraction(Vecteur3D autre) const {
    Vecteur3D resultat;
    resultat.set_coord(0, x - autre.x);
    resultat.set_coord(0, y - autre.y);
    resultat.set_coord(0, z - autre.z);
    return resultat;
}

int main() {
    return 0;
}