#include "Integrateur.h"
#include "Ressort.h"
#include <iostream>
#include <fstream>

using namespace std;

void test();
void test2();

int main() {
    test();
    //test2();
    return 0;
}

void test() {
    ofstream write("./plot.txt");
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
    write << masse1.position() << endl;
    write << masse2.position() << endl;
    write << masse3.position() << endl;

    cout << "========================================" << endl;
    for (int i = 1; i <= 5; i++){
        masse1.mise_a_jour_forces();
        masse2.mise_a_jour_forces();
        masse3.mise_a_jour_forces();

        masse1.ajoute_force(-g * masse1.masse());
        masse2.ajoute_force(-g * masse2.masse());
        masse3.ajoute_force(-g * masse3.masse());

        integrateur.evolue(masse1);
        integrateur.evolue(masse2);
        integrateur.evolue(masse3);

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

void test2() {
    ofstream write("./plot.txt");
    Masse masse1(2, 0.3);
    Masse masse2(2, 0.3, Vecteur3D(2,0,0));
    Ressort ressort(masse1, masse2, 3, 1);
    IntegrateurEulerCromer integrateur(0.1);

    for (int i(1); i <= 300; ++i) {
        masse1.ajoute_force(-g * masse1.masse());
        integrateur.evolue(masse1);
        cout << masse1.position() << endl;
        write << masse1.position() << endl;
    }
}