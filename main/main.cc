#include <QApplication>
#include <vector>
#include "glwidget.h"
#include "Systeme.h"
#include "TissuChaine.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);


    TissuChaine tissuChaine(0.5, 0.7, Vecteur3D(0,0,0), Vecteur3D(0,0,-6), 0.5, 30);

    Crochet crochet1(Vecteur3D(0,0,0), 0.2);
    Impulsion impulsion1(Vecteur3D(0,0,-3.5), 2, 0, 60, Vecteur3D(1, 0, 0), tissuChaine);
    vector<Contrainte*> contraintes{&crochet1, &impulsion1};
    Systeme systeme(tissuChaine, contraintes);
    systeme.check();

    GLWidget w(systeme);
    //w.wireframe();
    w.show();
    return a.exec();
    }
