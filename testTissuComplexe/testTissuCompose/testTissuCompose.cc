#include <QApplication>
#include <vector>
#include "glwidget.h"
#include "Systeme.h"
#include "TissuChaine.h"
#include "TissuRectangle.h"
#include "TissuDisque.h"
#include "TissuCompose.h"
#include "Contrainte.h"
#include <iostream>
#define _USE_MATH_DEFINES //pour avoir pi
using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    
    //test TTissuCompose

    TissuRectangle tissuRectangle_base(1, Vecteur3D(18,0,0), Vecteur3D(0,9,0), Vecteur3D(0,0,0), 0.6, 1, 440, true);
    TissuRectangle tissuRectangle_cote1(1, Vecteur3D(18,0,0), Vecteur3D(0,0,-5), Vecteur3D(0,0,0), 0.6, 1, 440);
    TissuRectangle tissuRectangle_cote2(1, Vecteur3D(18,0,0), Vecteur3D(0,0,-5), Vecteur3D(0,9,0), 0.6, 1, 440);
    TissuRectangle tissuRectangle_cote3(1, Vecteur3D(0,9,0), Vecteur3D(0,0,-5), Vecteur3D(0,0,0), 0.6, 1, 440);
    TissuRectangle tissuRectangle_cote4(1, Vecteur3D(0,9,0), Vecteur3D(0,0,-5), Vecteur3D(18,0,0), 0.6, 1, 440);
    TissuCompose tissuCompose_pave(tissuRectangle_base);
    tissuCompose_pave += tissuRectangle_cote1;
    tissuCompose_pave += tissuRectangle_cote2;
    tissuCompose_pave += tissuRectangle_cote3;
    tissuCompose_pave += tissuRectangle_cote4;
    
    TissuDisque TissuDisque_haut(1, Vecteur3D(-15,0,10), Vecteur3D(0,0,1), 10, 1, 0.3, 450, true, M_PI/8);
    TissuDisque TissuDisque_millieu(1, Vecteur3D(-15,0,0), Vecteur3D(0,0,1), 10, 1, 0.3, 450, false, M_PI/8);
    TissuDisque TissuDisque_bas(1, Vecteur3D(-15,0,-10), Vecteur3D(0,0,1), 10, 1, 0.3, 450, true, M_PI/8);
    TissuChaine TissuChaine_liaison1(1, 0.6, Vecteur3D(-5,0,10), Vecteur3D(-5,0,-10), 5, 1440, true, 0.5);
    TissuChaine TissuChaine_liaison2(1, 0.6, Vecteur3D(-25,0,10), Vecteur3D(-25,0,-10), 5, 1440, true, 0.5);
    TissuChaine TissuChaine_liaison3(1, 0.6, Vecteur3D(-15,10,10), Vecteur3D(-15,10,-10), 5, 1440, true, 0.5);
    TissuChaine TissuChaine_liaison4(1, 0.6, Vecteur3D(-15,-10,10), Vecteur3D(-15,-10,-10), 5, 1440, true, 0.5);
    TissuChaine tissuChaine_liaison6(1, 0.6, Vecteur3D(-15,0,10), Vecteur3D(-15,0,0), 5, 1440, false, 0.5);

    TissuCompose tissuCompose_Cylindre(TissuDisque_haut);
    tissuCompose_Cylindre += TissuDisque_millieu;
    tissuCompose_Cylindre += TissuDisque_bas;
    tissuCompose_Cylindre += TissuChaine_liaison1;
    tissuCompose_Cylindre += TissuChaine_liaison2;
    tissuCompose_Cylindre += TissuChaine_liaison3;
    tissuCompose_Cylindre += TissuChaine_liaison4;
    tissuCompose_Cylindre += tissuChaine_liaison6;
    
    vector<Tissu*> liste_tissu = {&tissuCompose_pave, &tissuCompose_Cylindre};
    Systeme systeme(liste_tissu);

    GLWidget w(systeme);
    w.wireframe();
    w.show();
    return a.exec();
}