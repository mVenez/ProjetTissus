#include "Integrateur.h"
#include <iostream>

void test();

int main() {
    return 0;
}

void test() {
    Masse masse1(1, 0.3);
    Masse masse2(1, 0.3, Vecteur3D(2,0,0));
    Masse masse3(1, 0.3, Vecteur3D(0,2,0));
}