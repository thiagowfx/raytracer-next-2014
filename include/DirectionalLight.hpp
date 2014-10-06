#ifndef _DIRECTIONALLIGHT_H_
#define _DIRECTIONALLIGHT_H_

#include "Light.hpp"
#include "ShadeRec.hpp"
#include "World.hpp"

namespace Raytracer {
/** @brief A directional light has a direction, a color and an intensity. */
class DirectionalLight : public Light {
 public:
  /** Create a Directional Light with the specified direction. */
  DirectionalLight(const Vector3d&);
  DirectionalLight(const DirectionalLight&);
  DirectionalLight();
  virtual ~DirectionalLight();
  virtual Light* clone() const;
  virtual bool operator==(const DirectionalLight&) const;

  virtual Vector3d get_direction(ShadeRec&);
  virtual RGBColor L(ShadeRec&);
  virtual bool in_shadow(const Ray&, ShadeRec&) const;

  void set_radiance(const double);
  void set_color(const RGBColor);
  void set_direction(const Vector3d&);
  double get_radiance() const;
  RGBColor get_color() const;
  Vector3d get_direction() const;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Light);
    ar& BOOST_SERIALIZATION_NVP(ls);
    ar& BOOST_SERIALIZATION_NVP(color);
    ar& BOOST_SERIALIZATION_NVP(direction);
  }

 private:
  /** Radiance of light. */
  double ls;

  /** Color of light. */
  RGBColor color;

  /** Direction of light. */
  Vector3d direction;
};

inline void DirectionalLight::set_radiance(const double ls) { this->ls = ls; }

inline void DirectionalLight::set_color(const RGBColor color) {
  this->color = color;
}

inline void DirectionalLight::set_direction(const Vector3d& direction) {
  this->direction = direction;
}

double DirectionalLight::get_radiance() const { return this->ls; }

RGBColor DirectionalLight::get_color() const { return this->color; }

Vector3d DirectionalLight::get_direction() const { return this->direction; }
}

#endif  // _DIRECTIONALLIGHT_H_
