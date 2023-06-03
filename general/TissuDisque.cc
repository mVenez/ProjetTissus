#define _USE_MATH_DEFINES //pour avoir pi
#include <vector>
#include <cmath>
#include "Masse.h"
#include "Ressort.h"
#include "Integrateur.h"
#include "SupportADessin.h"
#include "TissuDisque.h"
#include "constantes.h"
using namespace std;

TissuDisque::TissuDisque(double masse_kg, Vecteur3D centre, Vecteur3D normal, double rayon, double pas_entre_deux_masse_sur_rayon, double coef_frottement, double k, bool fixe, double angle) : Tissu(){
    /*Angle par défaut de 20 degrés = pi/9 radian
    bool fixe par défaut à false permet de fixer le dernier cercle du tissu
    "normal" est un vecteur normal au disque qui a pour norme le rayon du disque*/


    //on vérifie que le vecteur normal est non nul
    if(normal.norme() == 0){
        throw invalid_argument("Le vecteur normal doit être non nul");
    }
    //on rend unitaire le vecteur normal
    normal = ~normal;

    //on trouve un vecteur sur le disque en faisant le produit vectoriel de "normal" avec un vecteur unitaire de la base canonique qui n'est pas colineaire avec "normal"
    Vecteur3D u; //vecteur unitaire sur le disque
    if (normal.x() != 0) u = ~(Vecteur3D(0, 1, 0) ^ normal);
    else u = ~(Vecteur3D(1, 0, 0) ^ normal);

    //on vérifie que les vecteur u et normal soit bien orthogonaux
    if(abs(u*normal) > epsilon){
        throw invalid_argument("Les vecteurs u et normal doivent être orthogonaux");
    }


    //on calcul le nombre de masse sur le rayon
    int nb_masse_rayon = rayon/pas_entre_deux_masse_sur_rayon;
    //on calcul le nombre d’angle pour faire un tour complet, on suppose que l’utilisatour entre un angle en radian qui est un multiple ou diviseur de pi, sinon la dernière jonction du tissu disque est imparfait bien que fonctionnel.
    int nb_angle_tour = 2*M_PI/angle;//2pi car on veut faire un tour complet
     
    //on crée les masses et les ressorts
    for(double n = 0; n < nb_angle_tour; ++n){
        u = ~(cos(angle)*u + sin(angle)*(normal^u));//formule de rotation d'angle "angle" autour de l'axe "normal"
        for(int m = 1; m <= nb_masse_rayon; ++m){
            Masse* masse = new Masse(masse_kg, coef_frottement, centre + m*pas_entre_deux_masse_sur_rayon*~u);
            ajoute_masse(masse);
            if(m >= 2){
                connecte(*vector_masse_[vector_masse_.size() - 2], *vector_masse_.back(), k, pas_entre_deux_masse_sur_rayon);
            }
            if(fixe && m == nb_masse_rayon){//si le parametre fixe est à true on fixe le dernier cercle
                vector_masse_.back()->fixe();
            }
            if(n >= 1){
                connecte(*vector_masse_[vector_masse_.size() - nb_masse_rayon - 1], *vector_masse_.back(), k, 2*sin(angle/2)*pas_entre_deux_masse_sur_rayon*m);
            }
            if(n == nb_angle_tour - 1){//permet de connecter les deux "bout" du tissu disque quand on arrive à la dernière itération de la boucle
                connecte(*vector_masse_[m-1], *vector_masse_.back(), k, 2*sin(angle/2)*pas_entre_deux_masse_sur_rayon*m);
            }
        }
    }
    //masse centrale
    Masse* masse = new Masse(masse_kg, coef_frottement, centre);
    ajoute_masse(masse);
    for(double n = 0; n < nb_angle_tour; ++n){
        connecte(*vector_masse_[n*nb_masse_rayon], *vector_masse_.back(), k, pas_entre_deux_masse_sur_rayon);
    }

}

//destructeur
TissuDisque::~TissuDisque() {
    for (auto masse : vector_masse_) delete masse;
}
