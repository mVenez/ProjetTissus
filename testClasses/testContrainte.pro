QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -std=c++11

TARGET = testContrainte

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

CONFIG-=app_bundle

INCLUDEPATH = ../general

SOURCES += \
    testContrainte.cc \

OBJECTS_DIR = ../tmp