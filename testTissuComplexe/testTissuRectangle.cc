#include <QApplication>
#include <vector>
#include "glwidget.h"
#include "Systeme.h"
#include "TissuRectangle.h"
#include "Contrainte.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    
    //test TissuRectangle

    TissuRectangle tissuRectangle(1, Vecteur3D(18,0,0), Vecteur3D(0,9,0), Vecteur3D(0,0,0), 0.6, 1, 80, true);
    Systeme systeme(tissuRectangle);

    GLWidget w(systeme);
    w.wireframe();
    w.show();
    return a.exec();
}
