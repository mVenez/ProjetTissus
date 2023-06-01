#include <QApplication>
#include <vector>
#include "glwidget.h"
#include "Systeme.h"
#include "Tissu.h"
#include "Masse.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    Masse masseA(0.33, 0.3, Vecteur3D(0, 0, -3), Vecteur3D(0, 0, 0));
    Masse masseB(1, 0.3, Vecteur3D(-0.5, 0, 0), Vecteur3D(0, 0, 0));
    Masse masseC(1, 0.3, Vecteur3D(0.5, 0, 0), Vecteur3D(0, 0, 0));
    masseB.fixe();
    masseC.fixe();

    vector<Masse*> liste_masse = {&masseA, &masseB, &masseC};
    Tissu tissu1(liste_masse);
    tissu1.connecte(masseA, masseB, 0.6, 2.5);
    tissu1.connecte(masseA, masseC, 0.6, 2.5);
    tissu1.check();
    Systeme systeme(tissu1);
    
    GLWidget w(systeme, 0.05);
    w.show();

    return a.exec();
    }
