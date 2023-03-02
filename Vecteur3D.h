#pragma once

class Vecteur3D {
public:
    void set_coord(int coordinate, double value);
    void affiche();
    bool compare(Vecteur3D v);
private:
    double x;
    double y;
    double z;
};