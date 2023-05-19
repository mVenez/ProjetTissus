#include <iostream>
#include <vector>
#include <QApplication>
#include "glwidget.h"
#include "Contrainte.h"
#include "TissuChaine.h"
#include "Masse.h"
#include "Systeme.h"
using namespace std;

int main(int argc, char* argv[]) {

    QApplication a(argc, argv);


    TissuChaine tissuChaine1(0.5, 0.7, Vecteur3D(0,0,0), Vecteur3D(0,0,-6), 0.5, 30);

    Crochet crochet1(Vecteur3D(0,0,0), 0.2);
    ImpulsionSin impulsion1(Vecteur3D(0,0,-3.5), 10, 0, 60, Vecteur3D(15, 0, 0), 0.5 , vector<Tissu*>{&tissuChaine1});
    vector<Contrainte*> contraintes{&crochet1, &impulsion1};

    Systeme systeme(vector<Tissu*>{&tissuChaine1}, contraintes);
    systeme.check();

    GLWidget w(systeme);
    //w.wireframe();
    w.show();
    return a.exec();

}