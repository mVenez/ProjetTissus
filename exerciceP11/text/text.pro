QMAKE_CXXFLAGS += -std=c++11

TARGET = exerciceP10

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

CONFIG-=app_bundle

INCLUDEPATH = ../general

SOURCES += \
    exerciceP10.cc \
    TextViewer.cc

HEADERS += \
    ../general/TextViewer.h \
    ../general/constantes.h \
    ../general/Dessinable.h \
    ../general/Integrateur.h \
    ../general/Masse.h \
    ../general/Objet.h \
    ../general/Ressort.h \
    ../general/SupportADessin.h \
    ../general/Systeme.h \
    ../general/Tissu.h \
    ../general/Vecteur3D.h