QT += core gui opengl widgets
QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -std=c++11 -Wno-deprecated-declarations

win32:LIBS += -lopengl32


TARGET = exerciceP11

LIBS += -L../../general -lgeneral
PRE_TARGETDEPS += ../../general/libgeneral.a

INCLUDEPATH += \
 ../../general \
 ../exerciceP11/Qt_GL \

SOURCES += \
    main_qt_gl.cc \
    glsphere.cc \
    glwidget.cc \
    vue_opengl.cc \

HEADERS += \
    glsphere.h \
    glwidget.h \
    vertex_shader.h \
    vue_opengl.h \

RESOURCES += \
    resource.qrc

OBJECTS_DIR = ../../tmp