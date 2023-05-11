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
    //avant cette ligne on touche pas
    
    //test TissuChaine
    vector<Vecteur3D> liste_position = {Vecteur3D(0, 0, 0), Vecteur3D(1, 0, 0), Vecteur3D(2, 0, 0), Vecteur3D(3, 0, 0), Vecteur3D(4, 0, 0)};
    TissuChaine tissuChaine(1, 0.3, 20, 1, liste_position);
    //tissuChaine.vector_masse()[0]->fixe();
    //tissuChaine.vector_masse().back()->fixe();
    Systeme systeme(tissuChaine);
    

    //Apres cette ligne on touche pas
    GLWidget w(systeme);
    w.show();
    return a.exec();
    }
