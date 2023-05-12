#include <QApplication>
#include <vector>
#include "glwidget.h"
#include "Systeme.h"
#include "Tissu.h"
#include "Masse.h"
#include "TissuRectangle.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    
    //test TissuRectangle
    TissuRectangle tissuRectangle(1, Vecteur3D(6,0,0), Vecteur3D(0,3,0), Vecteur3D(0,0,0), 0.6, 3, 40, true);
    Systeme systeme(tissuRectangle);

    GLWidget w(systeme);
    w.wireframe();
    w.show();
    return a.exec();
    }
