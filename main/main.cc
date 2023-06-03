#include <QApplication>
#include <vector>
#include "glwidget.h"
#include "Systeme.h"
#include "TissuRectangle.h"
#include "TissuChaine.h"
#include "TissuDisque.h"
#include "TissuCompose.h"
#include "Contrainte.h"
#include "constantes.h"
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
    

    // ================= ENCEINTE (de musique) =================
    Vecteur3D position_enceinte(-5, 10, -3);
    TissuDisque enceinte(0.5, position_enceinte, Vecteur3D(1,0,0), 5, 0.2, 0.3, 1000, true);
    ImpulsionSin impuls6(position_enceinte, 30, 0, 120, Vecteur3D(-3, 0, 0), 0.5, enceinte);
    tous_les_tissus.push_back(&enceinte);
    toutes_les_contraintes.push_back(&impuls6);
    // ================= ENCEINTE (de musique) =================


    // ================= trampoline1 avec implusion vers le bas = g =================
    Vecteur3D position_trampoline1(15,15,0);
    double angle_trampoline1 = M_PI/9;
    double rayon_trampoline1 = 10;
    double pas = 1;
    Vecteur3D normal_trampoline1(0,0,1);
    TissuDisque trampoline1_base(0.4, position_trampoline1, normal_trampoline1, rayon_trampoline1, pas, 0.3, 100, true, angle_trampoline1);
    TissuCompose trampoline1(trampoline1_base);
    int nb_angle_tour = 2*M_PI/angle_trampoline1;
    int nb_masse_rayon = rayon_trampoline1/pas;
    Vecteur3D u_trampoline1;
    if (normal_trampoline1.x() != 0) u_trampoline1 = ~(Vecteur3D(0, 1, 0) ^ normal_trampoline1);
    else u_trampoline1 = ~(Vecteur3D(1, 0, 0) ^ normal_trampoline1);
    for(double n = 0; n < nb_angle_tour; ++n){
        u_trampoline1 = (cos(angle_trampoline1)*u_trampoline1 + sin(angle_trampoline1)*(normal_trampoline1^u_trampoline1));
        TissuChaine* pied_trampoline1 = new TissuChaine(0.1, 0.6, position_trampoline1 + u_trampoline1*rayon_trampoline1, position_trampoline1 + u_trampoline1*rayon_trampoline1 + Vecteur3D(0,0,-3), 0.5, 50, true);
        trampoline1.ajoute_tissu(*pied_trampoline1, 1, 0.01);
    }

    // ================= ICI  =================
    Impulsion impuls8(position_trampoline1, 30, 0, 120, g, trampoline1_base);
    toutes_les_contraintes.push_back(&impuls8);
    // ================= ICI  =================

    /*for(double n = 0; n < nb_masse_rayon; ++n){
        ImpulsionSin* impuls = new ImpulsionSin(position_trampoline1, pas*n, 0, 120, normal_trampoline1*10*(nb_masse_rayon-n), 3, trampoline1_base);
        toutes_les_contraintes.push_back(impuls);
    }*/
    //ImpulsionSin impuls7(position_trampoline1, 30, 0, 120, -normal_trampoline1*(g.norme()), 5, trampoline1_base);
    //toutes_les_contraintes.push_back(&impuls7);
    tous_les_tissus.push_back(&trampoline1);
    // ================= trampoline1 =================


    // ================= trampoline2 simplement avec la gravité =================
    Vecteur3D position_trampoline2(15,-10,0);
    double angle_trampoline2 = M_PI/9;
    double rayon_trampoline2 = 10;
    Vecteur3D normal_trampoline2(0,0,1);
    TissuDisque trampoline2_base(0.4, position_trampoline2, normal_trampoline2, rayon_trampoline2, pas, 0.3, 100, true, angle_trampoline2);
    TissuCompose trampoline2(trampoline2_base);
    Vecteur3D u_trampoline2;
    if (normal_trampoline2.x() != 0) u_trampoline2 = ~(Vecteur3D(0, 1, 0) ^ normal_trampoline2);
    else u_trampoline2 = ~(Vecteur3D(1, 0, 0) ^ normal_trampoline2);
    for(double n = 0; n < nb_angle_tour; ++n){
        u_trampoline2 = (cos(angle_trampoline2)*u_trampoline2 + sin(angle_trampoline2)*(normal_trampoline2^u_trampoline2));
        TissuChaine* pied_trampoline2 = new TissuChaine(0.1, 0.6, position_trampoline2 + u_trampoline2*rayon_trampoline2, position_trampoline2 + u_trampoline2*rayon_trampoline2 + Vecteur3D(0,0,-3), 0.5, 50, true);
        trampoline2.ajoute_tissu(*pied_trampoline2, 1, 0.01);
    }
    tous_les_tissus.push_back(&trampoline2);
    // ================= trampoline2 =================



    Systeme systeme(tous_les_tissus, toutes_les_contraintes);

    GLWidget w(systeme);
    w.wireframe();
    w.show();
    return a.exec();
    }
