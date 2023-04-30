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

    cout << "On crée la masse" << endl;
    Masse masseA(0.33, 0.3, Vecteur3D(0, 0, -3), Vecteur3D(0, 0, 0));
    cout << "MasseA crée " << endl;
    Masse masseB(1, 0.3, Vecteur3D(-0.5, 0, 0), Vecteur3D(0, 0, 0));
    Masse masseC(1, 0.3, Vecteur3D(0.5, 0, 0), Vecteur3D(0, 0, 0));
    masseB.fixe();
    masseC.fixe();

    vector<Masse*> liste_masse = {&masseA, &masseB, &masseC};
    Tissu tissu1(liste_masse);
    tissu1.connecte(masseA, masseB, 0.6, 2.5);
    tissu1.connecte(masseA, masseC, 0.6, 2.5);
    tissu1.check();
    cout << "On cree le tissu " << endl;;
    cout << "Tissu1 crée" << endl;
    cout << "on cree le systeme avec tissu1"<< endl;
    Systeme systeme1(tissu1);
    cout << "systeme1 crée"<< endl;

    cout << "On construit le GLWidget" << endl;
    GLWidget w(systeme1);
    cout << "GLWidget crée" << endl;

    //w.set(systeme1);
    cout << "On appelle w.show() " << endl;
    w.show();
    cout << "the show is on" << endl;

    return a.exec();
    }
