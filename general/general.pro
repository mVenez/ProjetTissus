TEMPLATE = lib

CONFIG = staticlib
QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -std=c++11 -fPIE

SOURCES += \
    Contrainte.cc \
    constantes.cc \
    Dessinable.cc \
    Integrateur.cc \
    Masse.cc \
    Objet.cc \
    Ressort.cc \
    Systeme.cc \
    Tissu.cc \
    TissuChaine.cc \
    TissuRectangle.cc \
    TissuDisque.cc \
    Vecteur3D.cc \

HEADERS += \
    Contrainte.h \
    constantes.h \
    Dessinable.h \
    Integrateur.h \
    Masse.h \
    Objet.h \
    Ressort.h \
    SupportADessin.h \
    Systeme.h \
    Tissu.h \
    TissuChaine.h \
    TissuRectangle.h \
    TissuDisque.h \
    Vecteur3D.h \
