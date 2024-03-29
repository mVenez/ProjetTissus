#include <iostream>
#include <vector>
#include "Contrainte.h"
#include "TissuRectangle.h"
#include "Systeme.h"
using namespace std;

int main() {
    TissuRectangle tissu1(0.3125, Vecteur3D(3,0,0), Vecteur3D(0,3,0), Vecteur3D(0,0,0), 0.3, 1, 1, false, 1 );
    Crochet croch1(Vecteur3D(0,0,0), 0.1);
    Crochet croch2(Vecteur3D(0,3,0), 0.1);

    ImpulsionSin impuls1(Vecteur3D(3,0,0), 0.5, 0, 2, Vecteur3D(0,0,30), 1.5, tissu1);
    ImpulsionSin impuls2(Vecteur3D(3,3,0), 0.5, 0, 2, Vecteur3D(0,0,30), 1.5, tissu1);

    Systeme systeme(tissu1, vector<Contrainte*>{&croch1, &croch2, &impuls1, &impuls2});

    systeme.check();

    IntegrateurEulerCromer integrateur(0.01);

    for (int i = 1; i <= 200; ++i) {
        systeme.evolue(integrateur);
        systeme.affiche_positions(cout);
    }
    return 0;
}