#include "PointLight.hpp"

namespace Raytracer {
PointLight::PointLight() :
		Light(),
		ls(1.0),
		color(white),
		location(Vector3d::Zero())
	{}

PointLight::PointLight(const Vector3d& location)
    : Light(), 
	ls(1.0),
	color(white),
	location(location) {}

PointLight::PointLight(const PointLight& a)
    : Light(a), ls(a.ls), color(a.color), location(a.location) {}

Light* PointLight::clone() const { return new PointLight(*this); }

PointLight::~PointLight() {}

bool PointLight::operator==(const PointLight& o) const {
  return Light::operator==(o) && ls == o.ls && color == o.color &&
         location == o.location;
}

Vector3d PointLight::get_direction(ShadeRec& sr) {
  return (location - sr.hit_point).normalized();
}

RGBColor PointLight::L(ShadeRec& sr) { return ls * color; }

bool PointLight::in_shadow(const Ray& ray, ShadeRec& sr) const {
  double t = 0;
  const unsigned num_objects = sr.w.objects.size();
  const double distance = (location - ray.origin).norm();
  for (unsigned j = 0; j < num_objects; ++j) {
    /* t < d means: an object only blocks a point light if it is before the
     * light */
    if (sr.w.objects[j]->hit(SHADOW_RAY, ray, t, sr) && t < distance) {
      return true;
    }
  }
  return false;
}
}
