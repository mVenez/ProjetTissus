#include <iostream>
#include <cmath>
#include "Vecteur3D.h"
using namespace std;

Vecteur3D::Vecteur3D(double x , double y , double z ) 
    : x(x), y(y), z(z) {}

void Vecteur3D::set_coord(int coordinate, double value) {
    if (coordinate == 0) {x = value;}
    else if (coordinate == 1) {y = value;}
    else if (coordinate == 2) {z = value;}
    else {cout << "La coordonnée choisie n'existe pas" << endl;}
}
void Vecteur3D::affiche() const {
    cout << x << ' ' << y << ' ' << z;
}

bool Vecteur3D::compare(Vecteur3D v, double epsilon) const { // epsilon = 1e-10 par défaut défini dans le .h
    return (
        abs(x - v.x) <= epsilon && 
        abs(y - v.y) <= epsilon && 
        abs(z - v.z) <= epsilon
        );
}

Vecteur3D Vecteur3D::addition(Vecteur3D autre) const {
    Vecteur3D resultat;
    resultat.set_coord(0, x + autre.x);
    resultat.set_coord(1, y + autre.y);
    resultat.set_coord(2, z + autre.z);
    return resultat;
}

Vecteur3D Vecteur3D::soustraction(Vecteur3D autre) const {
    Vecteur3D resultat;
    resultat.set_coord(0, x - autre.x);
    resultat.set_coord(1, y - autre.y);
    resultat.set_coord(2, z - autre.z);
    return resultat;
}

Vecteur3D Vecteur3D::mult(double lambda) const {
    Vecteur3D resultat;
    resultat.set_coord(0, lambda * x);
    resultat.set_coord(1, lambda * y);
    resultat.set_coord(2, lambda * z);
    return resultat;
}

Vecteur3D Vecteur3D::oppose() const {
    return mult(-1);
}

double Vecteur3D::prod_scal(Vecteur3D autre) const {
    return (autre.x * x + autre.y * y + autre.z * z);
}

Vecteur3D Vecteur3D::prod_vect(Vecteur3D autre) const {
    Vecteur3D resultat;
    resultat.set_coord(0, y * autre.z - z * autre.y);
    resultat.set_coord(1, z * autre.x - x * autre.z);
    resultat.set_coord(2, x * autre.y - y * autre.x);
    return resultat;
}

double Vecteur3D::norme() const {
    return (sqrt(pow(x,2)+pow(y,2)+pow(z,2)));
}

double Vecteur3D::norme2() const {
    return (pow(x,2)+pow(y,2)+pow(z,2));
}

Vecteur3D Vecteur3D::unitaire() const {
    Vecteur3D resultat;
    double n(norme());
    if (n == 0) {cout << "Le vecteur est nul" << endl; return resultat;} // retourne le vecteur nul (0,0,0
    resultat.set_coord(0, x / n);
    resultat.set_coord(1, y / n);
    resultat.set_coord(2, z / n);
    return resultat;
}