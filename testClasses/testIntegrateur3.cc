#include "Integrateur.h"
#include "Masse.h"
#include "Vecteur3D.h"
#include "Ressort.h"
#include <iostream>
#include <fstream>
using namespace std;

void test_ressorts_et_poids_cas_simple(){
    ofstream write("plot.txt");
    double pas_de_temps = 0.1;

    Masse masseA(0.33, 0.3, Vecteur3D(0, 0, -3), Vecteur3D(0, 0, 0));
    Masse masseB(1, 0.3, Vecteur3D(-0.5, 0, 0), Vecteur3D(0, 0, 0));
    Masse masseC(1, 0.3, Vecteur3D(0.5, 0, 0), Vecteur3D(0, 0, 0));

    Ressort R1(masseA, masseB, 0.6, 2.5);
    Ressort R2(masseA, masseC, 0.6, 2.5);

    IntegrateurEulerCromer integrateur(pas_de_temps);

    cout << "Situation de départ : " << endl;
    cout << "Masse A : " << endl << masseA << endl;
    cout << "Masse B : " << endl << masseB << endl;
    cout << "Masse C : " << endl << masseC << endl;
    cout << "Ressort 1 : " << endl << R1 << endl;
    cout << "Ressort 2 : " << endl << R2 << endl;
    cout << "=========================" << endl;


    for(int i = 1; i <= 250; ++i){
        masseA.mise_a_jour_forces();
        integrateur.evolue(masseA);
        //integrateur.evolue(masseB);
        //integrateur.evolue(masseC);
        cout << "Situation à t = " << i*pas_de_temps << "s : " << endl;
        cout << "Masse A : " << endl << masseA << endl;
        write << masseA.position() << endl;
        //cout << "Masse B : " << endl << masseB << endl;
        //cout << "Masse C : " << endl << masseC << endl;
        cout << "=========================" << endl;
    }
}

int main() {
    test_ressorts_et_poids_cas_simple();
    return 0;
}