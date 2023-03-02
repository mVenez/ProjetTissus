#pragma once

class Vecteur3D {
public:
    void set_coord(int coordinate, double value);
    void affiche() const;
    bool compare(Vecteur3D v)const;
    Vecteur3D addition(Vecteur3D autre) const;
    Vecteur3D soustraction(Vecteur3D autre) const;
private:
    double x;
    double y;
    double z;
};