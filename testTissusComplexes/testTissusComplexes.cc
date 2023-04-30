#include "Tissu.h"
#include "TissuChaine.h"
#include "TissuRectangle.h"
#include "TissuDisque.h"
#include <vector>
#include <iostream>
using namespace std;

void testTissuChaine(){
    cout << "testTissuChaine" << endl;
    vector<Vecteur3D> liste_position = {Vecteur3D(0, 0, 0), Vecteur3D(1, 0, 0), Vecteur3D(2, 0, 0), Vecteur3D(3, 0, 0), Vecteur3D(4, 0, 0)};
    TissuChaine tissuChaine(1, 0.3, 4, 1, liste_position);
    cout << tissuChaine << endl;
    cout << "testTissuChaine fini" << endl;
}


int main(){
    
    testTissuChaine();
    cout << "ça compile sa mère la pute" << endl;
    return 0;
}