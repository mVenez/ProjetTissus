#include <iostream>
#include <vector>
#include "TextViewer.h"
#include "Masse.h"
#include "Systeme.h"
#include "Tissu.h"
#include "Integrateur.h"
using namespace std;

void test1();

int main() {
    test1();
    return 0;
}

void test1() {
    TextViewer terminal(cout);

    double pas_de_temps(0.1);
    IntegrateurEulerCromer integrateur(pas_de_temps);

    Masse masseA(0.33, 0.3, Vecteur3D(0, 0, -3), Vecteur3D(0, 0, 0));
    Masse masseB(1, 0.3, Vecteur3D(-0.5, 0, 0), Vecteur3D(0, 0, 0));
    Masse masseC(1, 0.3, Vecteur3D(0.5, 0, 0), Vecteur3D(0, 0, 0));
    masseB.fixe();
    masseC.fixe();

    vector<Masse*> liste_masse = {&masseA, &masseB, &masseC};
    Tissu tissu1(liste_masse);
    tissu1.connecte(masseA, masseB, 0.6, 2.5);
    tissu1.connecte(masseA, masseC, 0.6, 2.5);
    tissu1.check();
    
    Systeme systeme1(tissu1);

    for(int i = 1; i <= 25; ++i){  //boucle d'evolution
        systeme1.evolue(integrateur);
        
        cout << "=========================" << endl;
        cout << "Situation à t = " << i*pas_de_temps << "s : " << endl;
        systeme1.dessine_sur(terminal);
        cout << "=========================" << endl;
    }
}