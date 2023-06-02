#include <QApplication>
#include <vector>
#include "glwidget.h"
#include "Systeme.h"
#include "TissuRectangle.h"
#include "TissuChaine.h"
#include "TissuCompose.h"
#include "Contrainte.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    TissuRectangle tissu1(0.4, Vecteur3D(5,0,0), Vecteur3D(0,0,-4), Vecteur3D(0,0,0), 0.4, 0.1, 1200);
    TissuRectangle tissu2(0.4, Vecteur3D(0,0,0), Vecteur3D(0,0,-8), Vecteur3D(0,0,0), 0.4, 0.1, 1200, true);
    TissuCompose tissu3(tissu1);
    tissu3.ajoute_tissu(tissu2, 0.01, 1200);
    /*Crochet croch1(Vecteur3D(0,0,0), 0.1);
    Crochet croch2(Vecteur3D(0,0,-1), 0.1);
    Crochet croch3(Vecteur3D(0,0,-2), 0.1);
    Crochet croch4(Vecteur3D(0,0,-3), 0.1);
    Crochet croch5(Vecteur3D(0,0,-4), 0.1);
    Crochet croch6(Vecteur3D(0,0,-0.5), 0.1);
    Crochet croch7(Vecteur3D(0,0,-1.5), 0.1);
    Crochet croch8(Vecteur3D(0,0,-2.5), 0.1);
    Crochet croch9(Vecteur3D(0,0,-3.5), 0.1);*/
    Impulsion impuls1(Vecteur3D(0,0,0), 30, 0, 120, Vecteur3D(2.5,0,0), tissu3);
    /*ImpulsionSin impuls2(Vecteur3D(0,0,0), 30, 0, 120, Vecteur3D(0.7, 1.6, -0.5), 0.5, tissu1);
    ImpulsionSin impuls3(Vecteur3D(0,0,0), 30, 0.3, 120, Vecteur3D(0, 0.4, 0.4), 0.3, tissu1);
    ImpulsionSin impuls4(Vecteur3D(4,0,-3.5), 1.5, 0, 120, Vecteur3D(0.3, -0.7, -0.2), 0.3, tissu1);
    ImpulsionSin impuls5(Vecteur3D(3,0,-1.5), 1.8, 0.4, 120, Vecteur3D(0, 0.6, 0.1), 0.2, tissu1);*/

    ImpulsionSin impuls2(Vecteur3D(0,0,0), 30, 0, 120, Vecteur3D(0.7, 1.6, -0.5), 0.5, tissu3);
    ImpulsionSin impuls3(Vecteur3D(0,0,0), 30, 0.3, 120, Vecteur3D(0, 0.4, 0.4), 0.3, tissu3);
    ImpulsionSin impuls4(Vecteur3D(4,0,-3.5), 1.5, 0, 120, Vecteur3D(0.3, -0.7, -0.2), 0.3, tissu3);
    ImpulsionSin impuls5(Vecteur3D(3,0,-1.5), 1.8, 0.4, 120, Vecteur3D(0, 0.6, 0.1), 0.2, tissu3);

    vector<Contrainte*> contraintes { &impuls1, &impuls2, &impuls3, &impuls4, &impuls5};
    Systeme systeme(tissu3, contraintes);

    GLWidget w(systeme);
    w.wireframe();
    w.show();
    return a.exec();
    }
