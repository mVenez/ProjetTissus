#include "Integrateur.h"
#include "Masse.h"
#include <iostream>
#include <fstream>
using namespace std;

void test_chute_libre(){
    ofstream write("./plot.txt");
    Masse masse(0.127, 0, Vecteur3D(0, 0, 1), Vecteur3D(1, 0, 2));
    IntegrateurEulerCromer integrateur(0.01);
    cout << "Situation de départ : " << endl << masse << endl;
    cout << "=========================" << endl;
    for (int i = 1; i <= 100; ++i){
        masse.mise_a_jour_forces();
        integrateur.evolue(masse);
        cout << "Situation après " << i << " pas de temps : " << endl << masse << endl;
        write << masse.position() << endl;
        cout << "=========================" << endl;
    }

}

int main() {
    test_chute_libre();
    return 0;
}