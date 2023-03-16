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
ostream& operator<<(ostream& out, const Vecteur3D& vec) {
    vec.affiche();
    return out;
}

bool Vecteur3D::compare(Vecteur3D v, double epsilon) const { // epsilon = 1e-10 par défaut défini dans le .h
    return (
        abs(x - v.x) <= epsilon && 
        abs(y - v.y) <= epsilon && 
        abs(z - v.z) <= epsilon
        );
}
bool Vecteur3D::operator==(const Vecteur3D& autre) const {
    return compare(autre);
}
bool Vecteur3D::operator!=(const Vecteur3D& autre) const {
    return !compare(autre);
}

Vecteur3D& Vecteur3D::operator+=(const Vecteur3D& autre) {
    x += autre.x;
    y += autre.y;
    z += autre.z;
    return *this;
}
Vecteur3D operator+(Vecteur3D vec1, const Vecteur3D& vec2) {
    return (vec1 += vec2);
}

Vecteur3D& Vecteur3D::operator-=(const Vecteur3D& autre) {
    x -= autre.x;
    y -= autre.y;
    z -= autre.z;
    return *this;
}
Vecteur3D Vecteur3D::operator-() const {
    return Vecteur3D(-x, -y, -z);
}
Vecteur3D operator-(Vecteur3D vec1, const Vecteur3D& vec2) {
    return (vec1 -= vec2);
}

//mult scalaire
Vecteur3D& Vecteur3D::operator*=(const double& lambda) {
    x *= lambda;
    y *= lambda;
    z *= lambda;
    return *this;
}
Vecteur3D operator*(Vecteur3D vec, const double& lambda) {
    return (vec *= lambda);
}

//produit scalaire
double Vecteur3D::operator*=(const Vecteur3D& autre) {
    return (autre.x * x + autre.y * y + autre.z * z);
}
double operator*(Vecteur3D vec1, const Vecteur3D& vec2) {
    return (vec1 *= vec2);
}

Vecteur3D Vecteur3D::prod_vect(Vecteur3D autre) const {
    Vecteur3D resultat(y * autre.z - z * autre.y, z * autre.x - x * autre.z, x * autre.y - y * autre.x);
    return resultat;
}
Vecteur3D operator^(const Vecteur3D& vec1, const Vecteur3D& vec2) {
    return vec1.prod_vect(vec2);
}


double Vecteur3D::norme() const {
    return (sqrt(pow(x,2)+pow(y,2)+pow(z,2)));
}

double Vecteur3D::norme2() const {
    return (pow(x,2)+pow(y,2)+pow(z,2));
}

Vecteur3D Vecteur3D::operator~() const{
    double n(norme());
    if (n == 0) {cout << "Le vecteur est nul" << endl; return Vecteur3D(0,0,0) ;} // retourne le vecteur nul (0,0,0)
    Vecteur3D resultat(x/n, y/n, z/n);
    return resultat;
}
