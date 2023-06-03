#pragma once

#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include "glsphere.h"
#include "SupportADessin.h"
#include "Masse.h"
#include "Tissu.h"
#include "glsphere.h"

class VueOpenGL : public SupportADessin {
 public:
  VueOpenGL() :wireframe_(false), spherical_(false), couleur_ressort_dynamique_(true) {}

  // méthode(s) de dessin (héritée(s) de SupportADessin)
  virtual void dessine(Masse const&) override;
  virtual void dessine(Ressort const&) override;

  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();

  // méthode set
  void setProjection(QMatrix4x4 const& projection) { prog.setUniformValue("projection", projection); }
  void wireframe() {wireframe_ = !wireframe_;} //alterne entre montrer et cacher les masses
  void spherical() {spherical_ = !spherical_;} //alterne entre visualisation cubique et spherique des masses
  void ressort_dynamique() {couleur_ressort_dynamique_ = !couleur_ressort_dynamique_;} //alterne entre l’affichage dynamique/non dynamique de la couleur des ressorts

  // Transformations
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  // Dessin de formes géometriques
  void dessineAxes(QMatrix4x4 const& point_de_vue, bool en_couleur = true);
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() );
  void dessineSphere(QMatrix4x4 const& point_de_vue, double rouge = 1.0, double vert = 1.0, double bleu = 1.0);

 private:
  QOpenGLShaderProgram prog;   // Un shader OpenGL encapsulé dans une classe Qt
  GLSphere sphere;

  bool wireframe_;
  bool spherical_;
  bool couleur_ressort_dynamique_;

  // Caméra
  QMatrix4x4 matrice_vue;
};
