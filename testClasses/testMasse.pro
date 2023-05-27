QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -std=c++11

TARGET = testMasse

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

CONFIG-=app_bundle

INCLUDEPATH = ../general

SOURCES += \
    testMasse.cc \

OBJECTS_DIR = ../tmp