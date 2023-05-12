#include <QApplication>
#include <vector>
#include "glwidget.h"
#include "Systeme.h"
#include "TissuDisque.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    //avant cette ligne on touche pas
    

    //test TissuDisque

    TissuDisque tissuDisque(1, Vecteur3D(0,0,-1), Vecteur3D(0,0,1), 10, 2, 0.3, 50, true);

    Systeme systeme(tissuDisque);

    //Apres cette ligne on touche pas
    GLWidget w(systeme);
    w.show();
    return a.exec();
    }
