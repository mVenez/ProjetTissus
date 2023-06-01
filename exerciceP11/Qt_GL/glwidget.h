#pragma once
#include <QOpenGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QTime>            // Classe pour gérer le temps
#include "vue_opengl.h"
#include "Systeme.h"

class GLWidget : public QOpenGLWidget {
public:
  GLWidget(Systeme& systeme, double dt = dt_const, QWidget* parent = nullptr)
    : QOpenGLWidget(parent) , sys(&systeme), dt_(dt) {}
  virtual ~GLWidget() = default;

  void set(Systeme& systeme) {sys = &systeme;}
  void wireframe() {vue.wireframe();}  //montrer ou cacher les masses
  void sphere() {vue.spherical();}  //visualisation cubique ou spherique des masses
  void use_newmark() {use_newmark_ = true;}  //utiliser l'integrateur de Newmark à la place de EulerCromer

private:
  // Les 3 méthodes clés de la classe QOpenGLWidget à réimplémenter
  virtual void initializeGL()                  override;
  virtual void resizeGL(int width, int height) override;
  virtual void paintGL()                       override;

  // Méthodes de gestion d'évènements
  virtual void keyPressEvent(QKeyEvent* event) override;
  virtual void mousePressEvent(QMouseEvent* event)  override;
  virtual void mouseMoveEvent(QMouseEvent* event)  override;
  virtual void timerEvent(QTimerEvent* event)  override;

  // Méthodes de gestion interne
  void pause();

  // Vue : ce qu'il faut donner au contenu pour qu'il puisse se dessiner sur la vue
  VueOpenGL vue;

  // Timer
  int timerId;
  // pour faire évoluer les objets avec le bon "dt"
  QTime chronometre;
  // pour se rappeller de la position de la souris
  QPoint lastMousePosition;

  // objets à dessiner, faire évoluer
  Systeme* sys;

  double dt_;
  bool use_newmark_;
};
