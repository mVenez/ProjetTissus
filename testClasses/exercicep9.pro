QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -std=c++11

TARGET = exerciceP9

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

CONFIG-=app_bundle

INCLUDEPATH = ../general

SOURCES += \
    exerciceP9.cc \

OBJECTS_DIR = ../tmp