#include <QApplication>
#include <vector>
#include "glwidget.h"
#include "Systeme.h"
#include "Tissu.h"
#include "Masse.h"
#include "TissuChaine.h"
#include "TissuRectangle.h"
#include "TissuDisque.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    //avant cette ligne on touche pas

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
    

    /*vector<Vecteur3D> liste_position = {Vecteur3D(0, 0, 0), Vecteur3D(1, 0, 0), Vecteur3D(2, 0, 0), Vecteur3D(3, 0, 0), Vecteur3D(4, 0, 0)};
    TissuChaine tissuChaine(1, 0.3, 20, 1, liste_position);
    tissuChaine.vector_masse()[0]->fixe();
    //tissuChaine.vector_masse().back()->fixe();
    Systeme systeme(tissuChaine);*/

    /*TissuDisque tissu(1, Vecteur3D(0,0,0), Vecteur3D(3,3,3), 0.5, 0.3, 50);
    for (auto masse : tissu.vector_masse()) {
        masse->fixe();
    }*/


    /*TissuRectangle tissu(1, Vecteur3D(3,0,0), Vecteur3D(0,2,0), Vecteur3D(0,0,0), 0.3, 3, 40);
    for (auto masse : tissu.vector_masse()) {
        masse->fixe();
    }*/
    

    //Apres cette ligne on touche pas
    GLWidget w(systeme);
    w.show();

    return a.exec();
    }
