#include <QKeyEvent>
#include <QTimerEvent>
#include <QMatrix4x4>
#include "glwidget.h"
#include "Integrateur.h"
#include "constantes.h"

// ======================================================================
void GLWidget::initializeGL()
{
  vue.init();
  timerId = startTimer(20);
  glClearColor(rouge, vert, bleu, 1);
}

// ======================================================================
void GLWidget::resizeGL(int width, int height)
{
  glViewport(0, 0, width, height);

  QMatrix4x4 matrice;
  matrice.perspective(70.0, qreal(width) / qreal(height ? height : 1.0), 1e-3, 1e5);
  vue.setProjection(matrice);
}

// ======================================================================
void GLWidget::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  sys->dessine_sur(vue);
}


// ======================================================================
void GLWidget::keyPressEvent(QKeyEvent* event)
{
  constexpr double petit_angle(5.0); // en degrés
  constexpr double petit_pas(1.0);

  switch (event->key()) {

  case Qt::Key_Left:
    vue.rotate(petit_angle, 0.0, -1.0, 0.0);
    break;

  case Qt::Key_Right:
    vue.rotate(petit_angle, 0.0, +1.0, 0.0);
    break;

  case Qt::Key_Up:
    vue.rotate(petit_angle, -1.0, 0.0, 0.0);
    break;

  case Qt::Key_Down:
    vue.rotate(petit_angle, +1.0, 0.0, 0.0);
    break;

  case Qt::Key_PageUp:
  case Qt::Key_W:
    vue.translate(0.0, 0.0,  petit_pas);
    break;

  case Qt::Key_PageDown:
  case Qt::Key_S:
    vue.translate(0.0, 0.0, -petit_pas);
    break;

  case Qt::Key_A:
    vue.translate( petit_pas, 0.0, 0.0);
    break;

  case Qt::Key_D:
    vue.translate(-petit_pas, 0.0, 0.0);
    break;

  case Qt::Key_R:
    vue.translate(0.0, -petit_pas, 0.0);
    break;

  case Qt::Key_F:
    vue.translate(0.0,  petit_pas, 0.0);
    break;

  case Qt::Key_Q:
    vue.rotate(petit_angle, 0.0, 0.0, -1.0);
    break;

  case Qt::Key_E:
    vue.rotate(petit_angle, 0.0, 0.0, +1.0);
    break;

  case Qt::Key_0:
  case Qt::Key_Home:
    vue.initializePosition();
    break;

  case Qt::Key_Space:
    pause();
    break;

  case Qt::Key_M:
    vue.wireframe();
    break;

  case Qt::Key_N:
    vue.spherical();
    break;

  case Qt::Key_I:
    use_newmark();
    break;
  };

  update(); // redessine
}

// ======================================================================
void GLWidget::mousePressEvent(QMouseEvent* event)
{
  lastMousePosition = event->pos();
}

// ======================================================================

void GLWidget::mouseMoveEvent(QMouseEvent* event)
{
  if (event->buttons() & Qt::LeftButton) {
    constexpr double petit_angle(.4); // en degrés

    // Récupère le mouvement relatif par rapport à la dernière position de la souris
    QPointF d = event->pos() - lastMousePosition;
    lastMousePosition = event->pos();

    vue.rotate(petit_angle * d.manhattanLength(), d.y(), d.x(), 0);

    update();
  }
}
// ======================================================================
void GLWidget::timerEvent(QTimerEvent* event)
{
  Q_UNUSED(event);

  //nous avons choisi d’avoir un dt constant pour une meilleur stabilité de la simulation, il suffit d’inverser la ligne commenté sur les deux ligne ci-dessous pour avoir un dt dynamique
  //double dt_ = chronometre.restart() / 170.0;

  sys->check();
  if (use_newmark_) sys->evolue(IntegrateurNewmark(dt_));
  else sys->evolue(IntegrateurEulerCromer(dt_));

  update();
}

// ======================================================================
void GLWidget::pause()
{
  if (timerId == 0) {
	// dans ce cas le timer ne tourne pas alors on le lance
	timerId = startTimer(20);
	chronometre.restart();
  } else {
	// le timer tourne alors on l'arrête
	killTimer(timerId);
	timerId = 0;
  }
}
