QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -std=c++11

TARGET = testTissu2

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

CONFIG-=app_bundle

INCLUDEPATH = ../general

SOURCES += \
    testTissu2.cc \

OBJECTS_DIR = ../tmp