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


    // ================= TRAMPOLINE =================
    Vecteur3D position_trampoline(20,-10,-10);
    double angle_trampoline = M_PI/9;
    double rayon_trampoline = 10;
    double pas = 1;
    Vecteur3D normal_trampoline(0,0,1);
    TissuDisque trampoline_base(0.4, position_trampoline, normal_trampoline, rayon_trampoline, pas, 0.3, 200, true, angle_trampoline);
    TissuCompose trampoline(trampoline_base);
    int nb_angle_tour = 2*M_PI/angle_trampoline;
    Vecteur3D u_trampoline;
    if (normal_trampoline.x() != 0) u_trampoline = ~(Vecteur3D(0, 1, 0) ^ normal_trampoline);
    else u_trampoline = ~(Vecteur3D(1, 0, 0) ^ normal_trampoline);
    for(double n = 0; n < nb_angle_tour; ++n){
        u_trampoline = (cos(angle_trampoline)*u_trampoline + sin(angle_trampoline)*(normal_trampoline^u_trampoline));
        TissuChaine* pied_trampoline = new TissuChaine(0.1, 0.6, position_trampoline + u_trampoline*rayon_trampoline, position_trampoline + u_trampoline*rayon_trampoline + Vecteur3D(0,0,-3), 0.5, 50, true);
        trampoline.ajoute_tissu(*pied_trampoline, 1, 0.01);
    }
    for(double n = 0; n < 20; ++n){
        Impulsion* impulsA = new Impulsion(position_trampoline, 2.5, 10*n, 10*n + 4, Vecteur3D(0, 0, -8), trampoline_base);
        toutes_les_contraintes.push_back(impulsA);
        Impulsion* impulsB = new Impulsion(position_trampoline, 30, 10*n + 4, 10*n + 10, Vecteur3D(0, 0, -0.7), trampoline_base);
        toutes_les_contraintes.push_back(impulsB);
    }
    tous_les_tissus.push_back(&trampoline);
    // ================= TRAMPOLINE =================

    // ================= TISSU MALMENER =================
    TissuRectangle tissu_malmener(0.4, Vecteur3D(5,-1,3), Vecteur3D(-2,4,-1), Vecteur3D(0,15,-5), 0.4, 0.1, 1200, true);
    for(double n = 0; n < 20; ++n){
        Impulsion* impulsA = new Impulsion(Vecteur3D(0,0,0), 300, 20*n, 20*n + 5, Vecteur3D(10, 0, 0), tissu_malmener);
        toutes_les_contraintes.push_back(impulsA);
        Impulsion* impulsB = new Impulsion(Vecteur3D(0,0,0), 300, 20*n + 5, 20*n + 10, Vecteur3D(0, 0, 10), tissu_malmener);
        toutes_les_contraintes.push_back(impulsB);
        Impulsion* impulsC = new Impulsion(Vecteur3D(0,0,0), 300, 20*n + 10, 20*n + 15, Vecteur3D(-10, 0, 0), tissu_malmener);
        toutes_les_contraintes.push_back(impulsC);
        Impulsion* impulsD = new Impulsion(Vecteur3D(0,0,0), 300, 20*n + 15, 20*n + 20, Vecteur3D(0, 0, -10), tissu_malmener);
        toutes_les_contraintes.push_back(impulsD);
    }
    tous_les_tissus.push_back(&tissu_malmener);
    // ================= TISSU MALMENER =================


    // ================= BAC À SABLE =================

    // créez le tissu composé/complexe que vous voulez ici
    // vous pouvez vous servir des exemples ci-dessus pour vous aider
    // n'oubliez pas de l'ajouter à la liste des tissus avec tous_les_tissus.push_back(&votre_tissu);
    // ansi que les contraintes avec toutes_les_contraintes.push_back(&votre_contrainte);


    // ================= BAC À SABLE =================


    Systeme systeme(tous_les_tissus, toutes_les_contraintes);

    GLWidget w(systeme);
    w.wireframe();
    w.show();
    return a.exec();
    }
