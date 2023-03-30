#include "Integrateur.h"
#include "Ressort.h"
#include <iostream>
using namespace std;

void test();

int main() {
    test();
    return 0;
}

void test() {
    Masse masse1(1, 0.3);
    Masse masse2(1, 0.3, Vecteur3D(2,0,0));
    Masse masse3(1, 0.3, Vecteur3D(0,2,0));
    Ressort ressort1(masse1, masse2, 9, 1.5);
    Ressort ressort2(masse1, masse3, 1.9, 1.75);
    Ressort ressort3(masse2, masse3, 5.5, 1.25);
    IntegrateurEulerCromer integrateur(0.1);

    cout << "Situation de départ : " << endl;
    cout << masse1 << endl;
    cout << masse2 << endl;
    cout << masse3 << endl;

    cout << "========================================" << endl;
    for (int i = 1; i <= 5; i++){
        //masse1.ajoute_force(-g * masse1.masse());
        integrateur.evolue(masse1);
        //masse2.ajoute_force(-g * masse2.masse());
        integrateur.evolue(masse2);
        //masse3.ajoute_force(-g * masse3.masse());
        integrateur.evolue(masse3);
        cout << "t = 0." << i << " : " << endl;
        cout << masse1 << endl;
        cout << masse2 << endl;
        cout << masse3 << endl;

        cout << "========================================" << endl;
    }
}