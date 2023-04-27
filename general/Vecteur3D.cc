#include <iostream>
#include <cmath>
#include "Vecteur3D.h"
using namespace std;

//constructeur
Vecteur3D::Vecteur3D(double x_ , double y_ , double z_ ) 
    : x_(x_), y_(y_), z_(z_) {}

//set_coordonnée
void Vecteur3D::set_coord(int coordinate, double value) {
    if (coordinate == 0) {x_ = value;}
    else if (coordinate == 1) {y_ = value;}
    else if (coordinate == 2) {z_ = value;}
    else {cout << "La coordonnée choisie n'existe pas" << endl;}
}

//affichage
ostream& Vecteur3D::affiche(ostream& out) const {
    out << x_ << ' ' << y_ << ' ' << z_;
    return out;
}
ostream& operator<<(ostream& out, const Vecteur3D& vec) {
    vec.affiche(out);
    return out;
}

//égalité et inegalité
bool Vecteur3D::compare(Vecteur3D v, double epsilon) const { // epsilon = 1e-10 par défaut défini dans le .h
    return (
        abs(x_ - v.x_) <= epsilon && 
        abs(y_ - v.y_) <= epsilon && 
        abs(z_ - v.z_) <= epsilon
        );
}
bool Vecteur3D::operator==(const Vecteur3D& autre) const {
    return compare(autre);
}
bool Vecteur3D::operator!=(const Vecteur3D& autre) const {
    return !compare(autre);
}

//addition
Vecteur3D& Vecteur3D::operator+=(const Vecteur3D& autre) {
    x_ += autre.x_;
    y_ += autre.y_;
    z_ += autre.z_;
    return *this;
}
Vecteur3D operator+(Vecteur3D vec1, const Vecteur3D& vec2) {
    return (vec1 += vec2);
}

//soustraction
Vecteur3D& Vecteur3D::operator-=(const Vecteur3D& autre) {
    x_ -= autre.x_;
    y_ -= autre.y_;
    z_ -= autre.z_;
    return *this;
}
Vecteur3D Vecteur3D::operator-() const {
    return Vecteur3D(-x_, -y_, -z_);
}

//opposé
Vecteur3D operator-(Vecteur3D vec1, const Vecteur3D& vec2) {
    return (vec1 -= vec2);
}

//multiplication par un scalaire
Vecteur3D& Vecteur3D::operator*=(const double& lambda) {
    x_ *= lambda;
    y_ *= lambda;
    z_ *= lambda;
    return *this;
}
Vecteur3D operator*(Vecteur3D vec, const double& lambda) { //dans un sens
    return (vec *= lambda);
}
Vecteur3D operator*(const double& lambda, Vecteur3D vec) { //dans l'autre
    return (vec * lambda);
}

//produit scalaire
double Vecteur3D::operator*=(const Vecteur3D& autre) {
    return (autre.x_ * x_ + autre.y_ * y_ + autre.z_ * z_);
}
double operator*(Vecteur3D vec1, const Vecteur3D& vec2) {
    return (vec1 *= vec2);
}

//produit vectoriel
Vecteur3D Vecteur3D::prod_vect(Vecteur3D autre) const {
    Vecteur3D resultat(y_ * autre.z_ - z_ * autre.y_, z_ * autre.x_ - x_ * autre.z_, x_ * autre.y_ - y_ * autre.x_);
    return resultat;
}
Vecteur3D operator^(const Vecteur3D& vec1, const Vecteur3D& vec2) {
    return vec1.prod_vect(vec2);
}

//norme et norme au carré
double Vecteur3D::norme() const {
    return (sqrt(pow(x_,2)+pow(y_,2)+pow(z_,2)));
}
double Vecteur3D::norme2() const {
    return (pow(x_,2)+pow(y_,2)+pow(z_,2));
}

//vecteur unitaire
Vecteur3D Vecteur3D::operator~() const{
    double n(norme());
    if (n == 0) {cout << "Le vecteur est nul" << endl; return Vecteur3D(0,0,0) ;} // retourne le vecteur nul (0,0,0)
    Vecteur3D resultat(x_/n, y_/n, z_/n);
    return resultat;
}
