#include <iostream>
#include <vector>
#include "Contrainte.h"
#include "Masse.h"
#include "Systeme.h"
using namespace std;

int main() {

    Masse masse1(1, 0.7, Vecteur3D(0,0,0));
    Masse masse2(1, 0.7, Vecteur3D(0,0,-2));
    Tissu tissu1(vector<Masse*>{&masse1, &masse2});
    tissu1.connecte(masse1, masse2, 3, 1);
    Crochet crochet1(Vecteur3D(0,0,0), 0.5);
    Impulsion impulsion1(Vecteur3D(0,0,-2), 0.5, 0, 60, Vecteur3D(4,0,0), vector<Tissu*>{&tissu1});
    IntegrateurEulerCromer integrateur(0.1);

    Systeme systeme1(tissu1, vector<Contrainte*>{&crochet1, &impulsion1});
    for (int i(1); i <= 100; ++i) {
        systeme1.evolue(integrateur);
        cout << systeme1 << endl;
    } 
    return 0;
}