QMAKE_CXXFLAGS += -std=c++11

TARGET = testTissusComplexes

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

CONFIG-=app_bundle

INCLUDEPATH = ../general

SOURCES += \
    testTissusComplexes.cc
