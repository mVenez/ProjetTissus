#include <vector>
#include "Masse.h"
#include "constantes.h"
#include "TissuCompose.h"
using namespace std;

TissuCompose::TissuCompose(Tissu& tissu) : Tissu() {
    this->ajoute_tissu(tissu);
}

TissuCompose::TissuCompose(Tissu& tissu1, Tissu& tissu2, double delta) : Tissu() {
    this->ajoute_tissu(tissu1);
    this->ajoute_tissu(tissu2, delta);
}

/*TissuCompose::TissuCompose(vector<Tissu*> vector_tissu, double delta) {
    for (auto tissu : vector_tissu) {
        this->ajoute_tissu(*tissu, delta);
    }
}*/


void TissuCompose::ajoute_tissu(Tissu& tissu, double delta) {

    vector_ressort_.insert(vector_ressort_.end(), tissu.vector_ressort_.begin(), tissu.vector_ressort_.end()); //ajoute les ressorts du tissu à la suite de ceux du tissu composé

    //calcul la raideur k moyenne au seins des tissus
    double k_ressort_de_couture(0); //raideur des ressorts de "couture" c’est à dire la raideur des ressorts qui relient les deux tissus
    for (auto ressort : vector_ressort_) {
        k_ressort_de_couture += ressort->k();
    }
    k_ressort_de_couture /= vector_ressort_.size();

    //on connecte les masses des deux tissus qui sont distantes de moins de delta
    for (auto masse1 : vector_masse_) {
        for (auto masse2 : tissu.vector_masse_){
            double distance((masse1->position() - masse2->position()).norme());
            if(distance < 0.1){
            }
            if ( distance < delta ){
                connecte(*masse1, *masse2, k_ressort_de_couture, distance);
            }
        }
    }

    vector_masse_.insert(vector_masse_.end(), tissu.vector_masse_.begin(), tissu.vector_masse_.end()); //ajoute les masses du tissu à la suite de celles du tissu composé

}

TissuCompose& TissuCompose::operator+=(Tissu& tissu) {
    this->ajoute_tissu(tissu);
    return *this;
}