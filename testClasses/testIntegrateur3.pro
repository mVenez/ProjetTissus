QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -std=c++11

TARGET = testIntegrateur3

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

CONFIG-=app_bundle

INCLUDEPATH = ../general

SOURCES += \
    testIntegrateur3.cc \

OBJECTS_DIR = ../tmp