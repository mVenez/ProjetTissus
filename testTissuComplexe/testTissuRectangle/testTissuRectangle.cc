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
    TissuRectangle tissuRectangle(1, Vecteur3D(3,0,0), Vecteur3D(0,2,0), Vecteur3D(0,0,0), 0.3, 3, 30);
    /*for (auto masse : tissuRectangle.vector_masse()) {
        masse->fixe();
    }*/
    tissuRectangle.vector_masse().back()->fixe();
    tissuRectangle.vector_masse()[5]->fixe();
    tissuRectangle.vector_masse().front()->fixe();
    tissuRectangle.vector_masse()[tissuRectangle.vector_masse().size()-6]->fixe();
    Systeme systeme(tissuRectangle);

    GLWidget w(systeme);
    w.wireframe();
    w.show();
    return a.exec();
    }
