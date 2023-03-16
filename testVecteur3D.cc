#include <iostream>
#include "Vecteur3D.h"
using namespace std;

void test1(Vecteur3D vect1, Vecteur3D vect2, Vecteur3D vect3);

void test2() {
    // un vecteur en 3D :
Vecteur3D vect1(1.0, 2.0, -0.1);

// un autre vecteur en 3D
Vecteur3D vect2(2.6, 3.5,  4.1);

Vecteur3D vect3(vect1);  // copie de V1
Vecteur3D vect4;         // le vecteur nul

cout << "Vecteur 1 : " << vect1 << endl;
cout << "Vecteur 2 : " << vect2 << endl;
cout << "Vecteur 3 : " << vect3 << endl;
cout << "Vecteur 4 : " << vect4 << endl;

cout << "Le vecteur 1 est ";
if (vect1 == vect2) {
    cout << "égal au";
} else {
    cout << "différent du";
}
cout << " vecteur 2," << endl << "et est ";
if (vect1 != vect3) {
    cout << "différent du";
} else {
    cout << "égal au";
}
cout << " vecteur 3." << endl;
}

void test3() {
    Vecteur3D vec1(0,0,0);
    Vecteur3D vec2(-vec1);
    if (vec1 == vec2) { cout << "ok" << endl;}
    else { cout << "not ok " << endl;}

}

int main() {
    Vecteur3D vect1;
    Vecteur3D vect2;
    Vecteur3D vect3;
    //test3();
    test1(vect1, vect2, vect3);
    //test2();
    return 0;
}


void test1(Vecteur3D vect1, Vecteur3D vect2, Vecteur3D vect3) {
     // v1 = (1.0, 2.0, -0.1)
    vect1.set_coord(0, 1.0);
    vect1.set_coord(1, 2.0);
    vect1.set_coord(2, -0.1);

    // v2 = (2.6, 3.5,  4.1)
    vect2.set_coord(0, 2.6);
    vect2.set_coord(1, 3.5);
    vect2.set_coord(2, 4.1); 

    vect3 = vect1;
    vect3.set_coord(0, 1.00000000001); // v1 presque égal à v3

    cout << "Vecteur 1 : ";
    vect1.affiche();
    cout << endl;

    cout << "Vecteur 2 : ";
    vect2.affiche();
    cout << endl;

    //test compare()
    cout << "Le vecteur 1 est ";
    if (vect1.compare(vect2)) {
        cout << "égal au";
    } else {
        cout << "différent du";
    }
    cout << " vecteur 2," << endl << "et est ";
    if ( !vect1.compare(vect3)) {
        cout << "différent du";
    } else {
        cout << "égal au";
    }
    cout << " vecteur 3." << endl;

    //test addition()
    cout << "(";
    vect1.affiche();
    cout << ") + (";
    vect2.affiche();
    cout << ") = ";
    vect3 = vect1 + vect2;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;
    //dans l’autre sens
    cout << "(";
    vect2.affiche();
    cout << ") + (";
    vect1.affiche();
    cout << ") = ";
    vect3 = vect2 + vect1;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;
    //avec vecteur nul
    Vecteur3D vect_nul;
    cout << "(";
    vect1.affiche();
    cout << ") + (";
    vect_nul.affiche();
    cout << ") = ";
    vect3 = vect1 + vect_nul;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;
    //dans l’autre sens
    cout << "(";
    vect_nul.affiche();
    cout << ") + (";
    vect1.affiche();
    cout << ") = ";
    vect3 = vect_nul + vect1;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;


    //test soustraction()
    cout << "(";
    vect1.affiche();
    cout << ") - (";
    vect2.affiche();
    cout << ") = ";
    vect3 = vect1 - vect2;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;
    //soustraction avec lui même
    cout << "(";
    vect1.affiche();
    cout << ") - (";
    vect1.affiche();
    cout << ") = ";
    vect3 = vect1 - vect1;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;
    //soustraction avec vecteur nul
    cout << "(";
    vect1.affiche();
    cout << ") - (";
    vect_nul.affiche();
    cout << ") = ";
    vect3 = vect1 - vect_nul;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;

    //test oppose()
    cout << "-(";
    vect1.affiche();
    cout << ") = ";
    vect3 = -vect1;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;
    //opposé de l’opposé
    cout << "--(";
    vect1.affiche();
    cout << ") = ";
    vect3 = -vect3;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;
    //opposé de vecteur nul
    cout << "-(";
    vect_nul.affiche();
    cout << ") = ";
    vect3 = -vect_nul;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;

    //test mult()
    cout << "3 * (";
    vect1.affiche();
    cout << ") = ";
    vect3 = vect1 * 3.0;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;
    //multiplication par 0
    cout << "0 * (";
    vect1.affiche();
    cout << ") = ";
    vect3 = vect1 * 0;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;
    //multiplication par 1
    cout << "1 * (";
    vect1.affiche();
    cout << ") = ";
    vect3 = vect1 * 1;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;
    //multiplication par -1
    cout << "-1 * (";
    vect1.affiche();
    cout << ") = ";
    vect3 = vect1 * (-1);
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;

    //test prod_scal()
    cout << "(";
    vect1.affiche();
    cout << ") * (";
    vect2.affiche();
    cout << ") = ";
    cout << vect1 * vect2 << endl;
    //produit scalaire avec lui même
    cout << "(";
    vect1.affiche();
    cout << ") * (";
    vect1.affiche();
    cout << ") = ";
    cout << vect1 * vect1 << endl;
    //produit scalaire avec vecteur nul
    cout << "(";
    vect1.affiche();
    cout << ") * (";
    vect_nul.affiche();
    cout << ") = ";
    cout << vect1 * vect_nul << endl;

    //test prod_vect()
    cout << "(";
    vect1.affiche();
    cout << ") ^ (";
    vect2.affiche();
    cout << ") = ";
    vect3 = vect1 ^ vect2;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;
    //produit vectoriel avec lui même
    cout << "(";
    vect1.affiche();
    cout << ") ^ (";
    vect1.affiche();
    cout << ") = ";
    vect3 = vect1 ^ vect1;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;
    //produit vectoriel avec vecteur nul
    cout << "(";
    vect1.affiche();
    cout << ") ^ (";
    vect_nul.affiche();
    cout << ") = ";
    vect3 = vect1 ^ vect_nul;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;

    //test norme()
    cout << "||(";
    vect1.affiche();
    cout << ")|| = ";
    cout << vect1.norme() << endl;
    //norme de vecteur nul
    cout << "||(";
    vect_nul.affiche();
    cout << ")|| = ";
    cout << vect_nul.norme() << endl;

    //test norme2()
    cout << "||(";
    vect1.affiche();
    cout << ")||^2 = ";
    cout << vect1.norme2() << endl;
    //norme2 de vecteur nul
    cout << "||(";
    vect_nul.affiche();
    cout << ")||^2 = ";
    cout << vect_nul.norme2() << endl;

    //test unitaire()
    cout << "unitaire(";
    vect1.affiche();
    cout << ") = ";
    vect3 = ~vect1;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;
    //controle norme du vecteur unitaire
    cout << "||unitaire(";
    vect1.affiche();
    cout << ")|| = ";
    cout << vect3.norme() << endl;
    //unitaire de vecteur nul
    cout << "unitaire(";
    vect_nul.affiche();
    cout << ") = ";
    vect3 = ~vect_nul;
    cout << "(";
    vect3.affiche();
    cout << ")" << endl;


}