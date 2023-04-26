TEMPLATE = lib

CONFIG = staticlib
QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    constantes.cc \
    Dessinable.cc \
    Integrateur.cc \
    Masse.cc \
    Objet.cc \
    Ressort.cc \
    Systeme.cc \
    Tissu.cc \
    Vecteur3D.cc \
    contenu.cc

HEADERS += \
    constantes.h \
    Dessinable.h \
    Integrateur.h \
    Masse.h \
    Objet.h \
    Ressort.h \
    SupportADessin.h \
    Systeme.h \
    Tissu.h \
    Vecteur3D.h \
    contenu.h
