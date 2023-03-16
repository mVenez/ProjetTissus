#include<iostream>
#include<vector>
#include "constantes.h"
#include "Vecteur3D.h"

class Masse{
public:
    Masse(double masse, double coefficient_frottement = 0, Vecteur3D position = Vecteur3D(0,0,0), Vecteur3D vitesse = Vecteur3D(0,0,0), Vecteur3D force_subie=g);
    
    Vecteur3D position() const;

    void ajoute_force(Vecteur3D const& df);

    Vecteur3D acceleration() const;

    void mise_a_jour_forces();
    
private:
    double masse;
    double coefficient_frottement;
    Vecteur3D position_;
    Vecteur3D vitesse;
    Vecteur3D force_subie; // l’accelération multiplié par la masse
    vector<Ressort*> ressorts;
};