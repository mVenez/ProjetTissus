QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -std=c++11

TARGET = testVecteur3D

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

CONFIG-=app_bundle

INCLUDEPATH = ../general

SOURCES += \
    testVecteur3D.cc \

OBJECTS_DIR = ../tmp