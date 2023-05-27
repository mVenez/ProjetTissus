QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -std=c++11

TARGET = testIntegrateur2

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

CONFIG-=app_bundle

INCLUDEPATH = ../general

SOURCES += \
    testIntegrateur2.cc \

OBJECTS_DIR = ../tmp