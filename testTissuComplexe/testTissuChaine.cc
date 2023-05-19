#include <QApplication>
#include <vector>
#include "glwidget.h"
#include "Systeme.h"
#include "TissuChaine.h"
#include "Contrainte.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    //avant cette ligne on touche pas
    
    //test TissuChaine

    TissuChaine tissuChaine(1, 0.3 ,Vecteur3D(0,0,0), Vecteur3D(4,0,0), 1, 200, true);
    //Crochet crochet(Vecteur3D(0,0,0), 0.5);
    Systeme systeme(tissuChaine);//, crochet);
    

    //Apres cette ligne on touche pas
    GLWidget w(systeme);
    w.show();
    return a.exec();
    }
