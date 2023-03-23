#include <iostream>
#include "Ressort.h"
#include "Masse.h"
#include "Constantes.h"
using namespace std;

void test1();

int main() {
    test1();
    return 0;
}

void test1(){
    Masse masse1(1, 0.3, Vecteur3D(0,0,0), Vecteur3D(0,0,0), g);
    Masse masse2(2, 0.3, Vecteur3D(1,0,0), Vecteur3D(0,0,0), g);
    Masse masse3(3, 0.3, Vecteur3D(2,0,0), Vecteur3D(0,0,0), g);
    cout << "==== On lie masse1 et masse2 avec un premier ressort ====" << endl;
    Ressort ressort1(masse1, masse2, 3, 1);
    cout << ressort1;

    cout << "==== On lie masse1 et masse2 avec un deuxième ressort ====" << endl;
    Ressort ressort2(masse2 , masse3, 4, 5);
    cout << ressort2;

        cout << "==== On verifie  ====" << endl;



}