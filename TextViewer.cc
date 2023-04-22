#include "TextViewer.h"
#include "Tissu.h"
#include "Systeme.h"
#include "Masse.h"
using namespace std;

TextViewer::TextViewer(ostream& flot)
    : flot_(flot) {}

void TextViewer::dessine(Tissu const& tissu){
    flot_ << tissu;
}
void TextViewer::dessine(Systeme const& systeme){
    flot_ << systeme;
}
void TextViewer::dessine(Masse const& masse){
    flot_ << masse;
}