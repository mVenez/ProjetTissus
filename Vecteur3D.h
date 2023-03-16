#pragma once

class Vecteur3D {
public:
    //constructeur
    explicit Vecteur3D(double x = 0, double y = 0, double z = 0);
    void set_coord(int coordinate, double value);   //cette methode pourrait etre utile dans le future

    //methodes auxiliaires aux operateurs
    void affiche() const;   // operator<<
    bool compare(Vecteur3D v, double epsilon = 1e-10)const; // operator==
    Vecteur3D prod_vect(Vecteur3D) const; //operator^

    //norme et norme au carré
    double norme() const;
    double norme2() const;

    //methodes obsoletes
    Vecteur3D addition(Vecteur3D) const; //OBSOLETE 
    Vecteur3D soustraction(Vecteur3D) const; //OBSOLETE
    Vecteur3D mult(double) const; //operator* OBSOLETE
    Vecteur3D oppose() const; //OBSOLETE
    double prod_scal(Vecteur3D) const; //operator* OBSOLETE
    Vecteur3D unitaire() const; //OBSOLETE
    
    //operateurs internes
    bool operator==(const Vecteur3D&) const;
    bool operator!=(const Vecteur3D&) const;
    Vecteur3D& operator+=(const Vecteur3D&);
    Vecteur3D& operator-=(const Vecteur3D&);
    Vecteur3D operator-() const;    //opposé
    Vecteur3D& operator*=(const double&); //multiplication par un scalaire
    double operator*=(const Vecteur3D&); //produit scalaire
    Vecteur3D operator~() const; //vecteur unitaire

private:
    double x;
    double y;
    double z;
};

//operateurs externes
std::ostream& operator<<(std::ostream&, const Vecteur3D&);
Vecteur3D operator+(Vecteur3D, const Vecteur3D&);
Vecteur3D operator-(Vecteur3D, const Vecteur3D&);
Vecteur3D operator*(Vecteur3D, const double&); //multiplication par un scalaire
double operator*(Vecteur3D, const Vecteur3D&); //produit scalaire
Vecteur3D operator^(const Vecteur3D&, const Vecteur3D&); // produit vectoriel
