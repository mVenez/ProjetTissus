#pragma once
#include "Vecteur3D.h"

extern const Vecteur3D g; //constante gravitationelle
extern const double epsilon; //epsilon pour l’égalité des double
extern const double dt_const; //pas de temps dt des simulation de tissu
extern const double delta_tissu_recompose; //delta par défaut des tissu recomposé, c’est à dire l’écart en dessous duquel l’on connecte de masse avec un ressort lors de la composition de tissu