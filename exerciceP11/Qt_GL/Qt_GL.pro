QT += core gui opengl widgets
QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lopengl32


TARGET = exerciceP11

LIBS += -L../../general -lgeneral
PRE_TARGETDEPS += ../../general/libgeneral.a

INCLUDEPATH = ../../general

SOURCES += \
    main_qt_gl.cc \
    glwidget.cc \
    vue_opengl.cc

HEADERS += \
    glwidget.h \
    vertex_shader.h \
    vue_opengl.h \

RESOURCES += \
    resource.qrc
