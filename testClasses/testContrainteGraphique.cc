#include <iostream>
#include <vector>
#include <QApplication>
#include "glwidget.h"
#include "Contrainte.h"
#include "TissuChaine.h"
#include "TissuRectangle.h"
#include "Systeme.h"
using namespace std;

int main(int argc, char* argv[]) {

    QApplication a(argc, argv);

    TissuRectangle tissu1(0.3125, Vecteur3D(3,0,0), Vecteur3D(0,3,0), Vecteur3D(0,0,0), 0.3, 1, 1, false, 1 );
    Crochet croch1(Vecteur3D(0,0,0), 0.1);
    Crochet croch2(Vecteur3D(0,3,0), 0.1);

    ImpulsionSin impuls1(Vecteur3D(3,0,0), 0.5, 0, 2, Vecteur3D(0,0,30), 1.5, tissu1);
    ImpulsionSin impuls2(Vecteur3D(3,3,0), 0.5, 0, 2, Vecteur3D(0,0,30), 1.5, tissu1);

    Systeme systeme(tissu1, vector<Contrainte*>{&croch1, &croch2, &impuls1, &impuls2});

    /*TissuChaine tissuChaine1(0.5, 0.7, Vecteur3D(0,0,0), Vecteur3D(0,0,-6), 0.5, 30);
    Crochet crochet1(Vecteur3D(0,0,0), 0.2);
    ImpulsionSin impulsion1(Vecteur3D(0,0,-3.5), 10, 0, 60, Vecteur3D(15, 0, 0), 0.5 , vector<Tissu*>{&tissuChaine1});
    vector<Contrainte*> contraintes{&crochet1, &impulsion1};
    Systeme systeme(vector<Tissu*>{&tissuChaine1}, contraintes);*/

    systeme.check();

    GLWidget w(systeme);
    w.wireframe();
    w.show(); 
    IntegrateurEulerCromer integrateur(0.01);
    
    return a.exec();
}