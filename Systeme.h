#include "Dessin.h"
#include <vector>

class Systeme : public Dessinable {
public:
    virtual void dessine_sur(SupportADessin& support) override;
private:
    std::vector<Objet*> vector_objet_;
};

class Objet{};