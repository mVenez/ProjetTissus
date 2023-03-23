#include <iostream>
#include "Ressort.h"
#include "Masse.h"
using namespace std;

int main() {
    Masse masse1(1, 0.3, Vecteur3D(0,0,0), Vecteur3D(0,0,0), Vecteur3D(0, 0, -9.81));
    Masse masse2(2, 0.3, Vecteur3D(1,0,0), Vecteur3D(0,0,0), Vecteur3D(0, 0, -9.81));
    Ressort ressort1(masse1, masse2, 3, 1);
    cout << ressort1;
    return 0;
}