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
    Vecteur3D position;
    Vecteur3D vitesse;

};