#include <iostream>
#include <vector>
#include "Contrainte.h"
#include "Masse.h"
#include "Systeme.h"
using namespace std;

int main() {

    Masse masse1(1, 0.7, Vecteur3D(0,0,0));
    //Masse masse2(1, 0.7, Vecteur3D(0,0,-1));
    Tissu tissu1(masse1);
    Crochet crochet1(Vecteur3D(0,0,0), 0.5);
    IntegrateurEulerCromer integrateur(0.1);
    if (crochet1.concerns(masse1)) cout << "OK"<<  endl;    
    //if (crochet1.concerns(masse2)) cout << "NOT OK"<<  endl;    

    Systeme systeme1(tissu1, crochet1);
    for (int i(1); i <= 100; ++i) {
        systeme1.evolue(integrateur);
        cout << "Instant t = " << i * 0.1 << endl;
        cout << systeme1 << endl;
    } 
    return 0;
}