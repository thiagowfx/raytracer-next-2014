#ifndef _POINTLIGHT_H_
#define _POINTLIGHT_H_

#include "Light.hpp"
#include "ShadeRec.hpp"
#include "World.hpp"

namespace Raytracer {
/** @brief A point light has a location, a color and an intensity. */
class PointLight : public Light {
 public:
  /** Create a point light at the specified location. */
  PointLight(const Vector3d&);
  PointLight(const PointLight&);
  PointLight();
  virtual ~PointLight();
  virtual Light* clone() const;
  virtual bool operator==(const PointLight&) const;

  virtual Vector3d get_direction(ShadeRec&);
  virtual bool in_shadow(const Ray&, ShadeRec&) const;
  virtual RGBColor L(ShadeRec&);

  void set_radiance(double);
  void set_color(const RGBColor);
  void set_location(const Vector3d&);
  double get_radiance() const;
  RGBColor get_color() const;
  Vector3d get_location() const;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Light);
    ar& BOOST_SERIALIZATION_NVP(ls);
    ar& BOOST_SERIALIZATION_NVP(color);
    ar& BOOST_SERIALIZATION_NVP(location);
  }

 private:
  /** Radiance of light. */
  double ls;

  /** Color of light. */
  RGBColor color;

  /** Location of light. */
  Vector3d location;
};

inline void PointLight::set_color(const RGBColor color) { this->color = color; }

inline void PointLight::set_radiance(double ls) { this->ls = ls; }

inline void PointLight::set_location(const Vector3d& location) {
  this->location = location;
}

inline Vector3d get_location() const { return this->location; }

inline RGBCOlor get_color() const { return this->color; }

inline double get_radiance() const { return this->ls; }
}

#endif  // _POINTLIGHT_H_
