#include<iostream>
#include "Masse.h"
#include "Vecteur3D.h"
using namespace std;

class Masse{
public:
    void lala(){
        cout << "lala" << endl;
    }
private:
    double masse;
    double coefficient_frottement;
    Vecteur3D position;
    Vecteur3D vitesse;
    Vecteur3D force_subie; // l’accelération quoi, mais bon jsp pourquoi il faut l’appeler comme ça.
};