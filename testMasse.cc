#include<iostream>
#include "Ressort.h"
#include "Masse.h"
#include "Vecteur3D.h"
using namespace std;

void test1(){
    cout << "=================== Test 1 ===================" << endl;

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
    cout << "Test ajoute_force() opposée" << endl;
    masse1.ajoute_force(Vecteur3D(-1,-2,-3));
    cout << "force_subie : " << masse1.force_subie() << endl;
    cout << endl;

}

void test2(){
    // test mise_a_jour_forces()
    cout << "=================== Test mise à jour des forces ===================" << endl;
    //les masses sont à 10m de distance
    Masse masse1(1.5, 0.3, Vecteur3D(5,0,0));
    Masse masse2(1.5, 0.3, Vecteur3D(-5,0,0));
    
    cout << "force_subie : " << masse1.force_subie() << endl;
    cout << "Test mise_a_jour_forces()" << endl;
    Ressort ressort1(masse1, masse2, 3, 1);
    vector<Ressort*> liste_ressort(1, &ressort1);
    masse1.set_ressort(liste_ressort);
    masse1.mise_a_jour_forces();
    cout << "force_subie : " << masse1.force_subie() << endl;
}

void test3() {
    Masse masse1(1,0.3);
    cout << masse1 << endl;
    masse1.set_position(Vecteur3D(2,2,2));
    masse1.set_vitesse(Vecteur3D(5,5,5));
    cout << masse1 << endl;
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}