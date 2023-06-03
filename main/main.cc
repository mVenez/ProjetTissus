#include <QApplication>
#include <vector>
#include "glwidget.h"
#include "Systeme.h"
#include "TissuRectangle.h"
#include "TissuChaine.h"
#include "TissuCompose.h"
#include "Contrainte.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    vector<Tissu*> tous_les_tissus;
    vector<Contrainte*> toutes_les_contraintes;

    // ================= DRAPEAU =================
    TissuRectangle drapeau(0.4, Vecteur3D(5,0,0), Vecteur3D(0,0,-4), Vecteur3D(0,0,0), 0.4, 0.1, 1200);
    TissuRectangle mat(0.4, Vecteur3D(0,0,0), Vecteur3D(0,0,-8), Vecteur3D(0,0,0), 0.4, 0.1, 1200, true);
    TissuCompose drapeau_mat(drapeau);
    drapeau_mat.ajoute_tissu(mat, 1200, 0.01);

    Impulsion impuls1(Vecteur3D(0,0,0), 30, 0, 120, Vecteur3D(2.5,0,0), drapeau_mat);
    ImpulsionSin impuls2(Vecteur3D(0,0,0), 30, 0, 120, Vecteur3D(0.7, 1.6, -0.5), 0.5, drapeau_mat);
    ImpulsionSin impuls3(Vecteur3D(0,0,0), 30, 0.3, 120, Vecteur3D(0, 0.4, 0.4), 0.3, drapeau_mat);
    ImpulsionSin impuls4(Vecteur3D(4,0,-3.5), 1.5, 0, 120, Vecteur3D(0.3, -0.7, -0.2), 0.3, drapeau_mat);
    ImpulsionSin impuls5(Vecteur3D(3,0,-1.5), 1.8, 0.4, 120, Vecteur3D(0, 0.6, 0.1), 0.2, drapeau_mat);

    vector<Contrainte*> contraintes_drapeau = {&impuls1, &impuls2, &impuls3, &impuls4, &impuls5};
    tous_les_tissus.push_back(&drapeau_mat);
    toutes_les_contraintes.insert(toutes_les_contraintes.end(), contraintes_drapeau.begin(), contraintes_drapeau.end());
    // ================= DRAPEAU =================
    


    Systeme systeme(tous_les_tissus, toutes_les_contraintes);

    GLWidget w(systeme);
    w.wireframe();
    w.show();
    return a.exec();
    }
