QT += core gui opengl widgets
QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lopengl32


TARGET = testTissuRectangle

LIBS += -L../../general -lgeneral
PRE_TARGETDEPS += ../../general/libgeneral.a

INCLUDEPATH += \
 ../../general \
 ../../exerciceP11/Qt_GL 

SOURCES += \
    testTissuRectangle.cc \
    ../../exerciceP11/Qt_GL/glsphere.cc \
    ../../exerciceP11/Qt_GL/glwidget.cc \
    ../../exerciceP11/Qt_GL/vue_opengl.cc

HEADERS += \
    ../../exerciceP11/Qt_GL/glsphere.h \
    ../../exerciceP11/Qt_GL/glwidget.h \
    ../../exerciceP11/Qt_GL/vertex_shader.h \
    ../../exerciceP11/Qt_GL/vue_opengl.h \

RESOURCES += \
    ../../exerciceP11/Qt_GL/resource.qrc
