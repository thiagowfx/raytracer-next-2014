#include "AmbientLight.hpp"

namespace Raytracer {
AmbientLight::AmbientLight() : Light(), ls(1.0), color(white) {}

AmbientLight::AmbientLight(const AmbientLight& a)
    : Light(a), ls(a.ls), color(a.color) {}

Light* AmbientLight::clone() const { return new AmbientLight(*this); }

AmbientLight::~AmbientLight() {}

bool AmbientLight::operator==(const AmbientLight& o) const {
  return Light::operator==(o) && ls == o.ls && color == o.color;
}

Vector3d AmbientLight::get_direction(ShadeRec& s) {
  return Vector3d(Vector3d::Zero());
}

RGBColor AmbientLight::L(ShadeRec& sr) { return ls * color; }

const char* AmbientLight::to_string() const { return "AmbientLight"; }

bool AmbientLight::in_shadow(const Ray& ray, ShadeRec& sr) const {
  return false;
}
}
