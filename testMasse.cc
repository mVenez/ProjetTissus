#include<iostream>
#include "Ressort.h"
#include "Masse.h"
#include "Vecteur3D.h"
using namespace std;

void test(){
    // test constructeur
    cout << "Test constructeur" << endl;
    Masse masse1(1.5);// test valeur par defaut
    cout << masse1 << endl;
    Masse masse2(1.5, 0.3, Vecteur3D(1,2,3), Vecteur3D(4,5,6));
    cout << masse2 << endl;

    // test getters
    cout << "Test getters" << endl;
    cout << "masse : " << masse1.masse() << endl;
    cout << "coefficient_frottement : " << masse1.coefficient_frottement() << endl;
    cout << "position : " << masse1.position() << endl;
    cout << "vitesse : " << masse1.vitesse() << endl;
    cout << "force_subie : " << masse1.force_subie() << endl;
    
}

int main() {
    test();
    return 0;
}