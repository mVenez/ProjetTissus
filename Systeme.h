#include "Dessin.h"

class Systeme : public Dessinable {
public:
    virtual void dessine_sur(SupportADessin& support) override;

};