#include "Systeme.h"
#include "Dessin.h"

void Systeme::dessine_sur(SupportADessin& support) {
    support.dessine(*this); 
}
