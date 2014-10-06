#include "DirectionalLight.hpp"

namespace Raytracer {
DirectionalLight::DirectionalLight()
    : Light(), ls(1.0), color(white), direction(Vector3d(1.0, 0.0, 0.0)) {}

DirectionalLight::DirectionalLight(const Vector3d& direction)
    : Light(), ls(1.0), color(white), direction(direction.normalized()) {}

DirectionalLight::DirectionalLight(const DirectionalLight& dl)
    : Light(dl), ls(dl.ls), color(dl.color), direction(dl.direction) {}

Light* DirectionalLight::clone() const { return new DirectionalLight(*this); }

DirectionalLight::~DirectionalLight() {}

bool DirectionalLight::operator==(const DirectionalLight& o) const {
  return Light::operator==(o) && ls == o.ls && color == o.color &&
         direction == o.direction;
}

Vector3d DirectionalLight::get_direction(ShadeRec& sr) { return direction; }

RGBColor DirectionalLight::L(ShadeRec& s) { return ls * color; }

bool DirectionalLight::in_shadow(const Ray& ray, ShadeRec& sr) const {
  double t;
  const unsigned num_objects = sr.w.objects.size();
  for (unsigned j = 0; j < num_objects; ++j) {
    if (sr.w.objects[j]->hit(SHADOW_RAY, ray, t, sr)) {
      return true;
    }
  }
  return false;
}
}
