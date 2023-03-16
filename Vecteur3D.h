#pragma once

class Vecteur3D {
public:
    //constructeur
    explicit Vecteur3D(double x = 0, double y = 0, double z = 0);
    void set_coord(int coordinate, double value);   //cette methode pourrait etre eliminé dans le future

    //methodes auxiliaires aux operateurs
    void affiche() const;   // operator<<
    bool compare(Vecteur3D v, double epsilon = 1e-10)const; // operator==
    Vecteur3D addition(Vecteur3D autre) const;
    Vecteur3D soustraction(Vecteur3D autre) const;
    Vecteur3D mult(double) const;
    Vecteur3D oppose() const;
    double prod_scal(Vecteur3D autre) const;
    Vecteur3D prod_vect(Vecteur3D) const;
    double norme() const;
    double norme2() const;
    Vecteur3D unitaire() const;
    
private:
    double x;
    double y;
    double z;
};