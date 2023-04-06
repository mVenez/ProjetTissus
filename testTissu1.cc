#include <iostream>
#include <fstream>
#include <vector>
#include "Tissu.h"
#include "Constantes.h"
using namespace std;

void test();

int main() {
    test();
    return 0;
}

void test() {
    ofstream write("./plot.txt");
    Masse masse1(1, 0.3);
    Masse masse2(1, 0.3, Vecteur3D(2,0,0));
    Masse masse3(1, 0.3, Vecteur3D(0,2,0));
    vector<Masse*> liste_masses = {&masse1, &masse2, &masse3};
    IntegrateurEulerCromer integrateur(0.1);
    Tissu tissu(liste_masses);
    tissu.connecte(masse1, masse2, 9, 1.5);
    tissu.connecte(masse1, masse3, 1.9, 1.75);
    tissu.connecte(masse2, masse3, 5.5, 1.25);
    tissu.check();
    cout << "Situation de départ: " << endl;

    cout << masse1 << endl;
    cout << masse2 << endl;
    cout << masse3 << endl;

    cout << "========================================" << endl;
    
    for (int i = 1; i <= 5; i++){
        tissu.mise_a_jour_forces();
        masse1.ajoute_force(-g * masse1.masse());
        masse2.ajoute_force(-g * masse2.masse());
        masse3.ajoute_force(-g * masse3.masse());
        tissu.evolue(integrateur);
        cout << "t = 0." << i << " : " << endl;
        cout << masse1 << endl;
        cout << masse2 << endl;
        cout << masse3 << endl;        

        write << masse1.position() << endl;
        write << masse2.position() << endl;
        write << masse3.position() << endl;
        cout << "========================================" << endl;

    }
}