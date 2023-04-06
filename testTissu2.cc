#include "Integrateur.h"
#include "Masse.h"
#include "Vecteur3D.h"
#include "Ressort.h"
#include "Tissu.h"
#include <iostream>
#include <fstream>
using namespace std;

//ce test correspond au test testIntegrateur3.cc mais avec un tissu

void test_ressorts_et_poids_cas_simple(){
    ofstream write("plot.txt");
    double pas_de_temps = 0.1;

    Masse masseA(0.33, 0.3, Vecteur3D(0, 0, -3), Vecteur3D(0, 0, 0));
    Masse masseB(1, 0.3, Vecteur3D(-0.5, 0, 0), Vecteur3D(0, 0, 0));
    Masse masseC(1, 0.3, Vecteur3D(0.5, 0, 0), Vecteur3D(0, 0, 0));
    masseB.fixe();
    masseC.fixe();
    vector<Masse*> liste_masse = {&masseA, &masseB, &masseC};
    Tissu tissu(liste_masse);

    tissu.connecte(masseA, masseB, 0.6, 2.5);
    tissu.connecte(masseA, masseC, 0.6, 2.5);


    IntegrateurEulerCromer integrateur(pas_de_temps);

    cout << "Situation de départ : " << endl;
    cout << tissu << endl;


    for(int i = 1; i <= 250; ++i){
        tissu.mise_a_jour_forces();
        tissu.evolue(integrateur);
        cout << "Situation à t = " << i*pas_de_temps << "s : " << endl;
        cout << "Masse A : " << endl << masseA << endl;
        write << masseA.position() << endl;
        cout << "=========================" << endl;
    }
}

int main() {
    test_ressorts_et_poids_cas_simple();
    return 0;
}