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
    cout << endl;
    cout << "Test getters" << endl;
    cout << "masse : " << masse1.masse() << endl;
    cout << "coefficient_frottement : " << masse1.coefficient_frottement() << endl;
    cout << "position : " << masse1.position() << endl;
    cout << "vitesse : " << masse1.vitesse() << endl;
    cout << "force_subie : " << masse1.force_subie() << endl;

    // test ajoute_force() 
    cout << endl;
    cout << "force_subie : " << masse1.force_subie() << endl;
    cout << "Test ajoute_force()" << endl;
    masse1.ajoute_force(Vecteur3D(1,2,3));
    cout << "force_subie : " << masse1.force_subie() << endl;
    // test ajoute_force() opposée
    cout << "Test ajoute_force() opposée";
    masse1.ajoute_force(Vecteur3D(-1,-2,-3));
    cout << "force_subie : " << masse1.force_subie() << endl;

    // test mise_a_jour_forces()
    cout << endl;
    cout << "Test mise_a_jour_forces()" << endl;
    // coder le test avec les ressorts

}

int main() {
    test();
    return 0;
}