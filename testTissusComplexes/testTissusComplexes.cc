#include "Tissu.h"
#include "TissuChaine.h"
#include "TissuRectangle.h"
#include "TissuDisque.h"
#include "Systeme.h"
#include "Masse.h"
#include <vector>
#include <iostream>
using namespace std;

void testTissuChaine(){
    vector<Vecteur3D> liste_position = {Vecteur3D(0, 0, 0), Vecteur3D(1, 0, 0), Vecteur3D(2, 0, 0), Vecteur3D(3, 0, 0), Vecteur3D(4, 0, 0)};
    TissuChaine tissuChaine(1, 0.3, 4, 1, liste_position);
    cout << tissuChaine << endl;
}


void testTissuDisque(){
    TissuDisque tissu(1, Vecteur3D(0,0,0), Vecteur3D(3,3,3), 0.5, 0.3, 20);
    Systeme systeme(tissu);
    cout << systeme << endl;
}


int main(){
    
    //testTissuChaine();
    testTissuDisque();
    cout << "ça compile" << endl;
    return 0;
}