#include <iostream>
#include "Ressort.h"
#include "Masse.h"
#include "Constantes.h"
using namespace std;

void test1();
void test2();

int main() {
    test1();
    //test2();
    return 0;
}

void test1(){
    cout << "=================== Test 1 ===================" << endl;
    Masse masse1(1, 0.3, Vecteur3D(0,0,0), Vecteur3D(0,0,0), g);
    Masse masse2(2, 0.3, Vecteur3D(1,0,0), Vecteur3D(0,0,0), g);
    Masse masse3(3, 0.3, Vecteur3D(2,0,0), Vecteur3D(0,0,0), g);
    cout << "==== On lie masse1 et masse2 avec un premier ressort ====" << endl;
    Ressort ressort1(masse1, masse2, 3, 1);
    cout << ressort1;

    cout << "==== On lie masse2 et masse3 avec un deuxième ressort ====" << endl;
    Ressort ressort2(masse2 , masse3, 4, 5);
    cout << ressort2;

    cout << "==== On verifie que la masse2 liste maintenant le deuxieme ressort ====" << endl;
    cout << ressort1;
    cout << ressort2;


    cout << "==== Nous modifions la masse2 et on verifie que les ressort soient mis à jour ====" << endl;
    masse2.ajoute_force(Vecteur3D(42,42,0));
    cout << masse2 << endl;
    cout << ressort1;
    cout << ressort2;

    cout << "==== On verifie maintenant les forces exercées par les ressorts sur les masses ====" << endl;
    cout << "ressort " << &ressort1 << " sur masse " << &masse1 << " : " << ressort1.force_rappel(&masse1) << endl;
    cout << "ressort " << &ressort1 << " sur masse " << &masse2 << " : " << ressort1.force_rappel(&masse2) << endl;
    //cout << "ressort " << &ressort1 << " sur masse " << &masse3 << " : " << ressort1.force_rappel(&masse3) << endl;

    //cout << "ressort " << &ressort2 << " sur masse " << &masse1 << " : " << ressort2.force_rappel(&masse1) << endl;   //dans ces deux instances on a un invalid_argument comme prevu. Par contre dans la description du projet c'est censé renvoyer 0 0 0 
    cout << "ressort " << &ressort2 << " sur masse " << &masse2 << " : " << ressort2.force_rappel(&masse2) << endl;
    cout << "ressort " << &ressort2 << " sur masse " << &masse3 << " : " << ressort2.force_rappel(&masse3) << endl;



}

/*void test2() {
    cout << "=================== Test 1 (destruction masses et ressorts) ===================" << endl;
    Masse masse1(1, 0.3, Vecteur3D(0,0,0), Vecteur3D(0,0,0), g);
    Masse masse2(2, 0.3, Vecteur3D(1,0,0), Vecteur3D(0,0,0), g);
    Masse masse3(3, 0.3, Vecteur3D(2,0,0), Vecteur3D(0,0,0), g);

    cout << "==== On lie masse1 et masse2 avec un premier ressort ====" << endl;
    Ressort ressort1(masse1, masse2, 3, 1);

    cout << "==== On lie masse2 et masse3 avec un deuxième ressort ====" << endl;
    Ressort ressort2(masse2 , masse3, 4, 5);
    cout << endl;

    cout << ressort1;
    cout << ressort2;

    cout << "==== BOUM!!! : masse2 est detruite" << endl;
    masse2.~Masse();
    cout << endl;

    cout << "==== On affiche la situation après la destruction de masse2 ====" << endl;
    cout << ressort1;
    cout << ressort2;


}*/
