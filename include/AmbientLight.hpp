#ifndef _AMBIENT_H_
#define _AMBIENT_H_

#include "Light.hpp"

namespace Raytracer {
/**
 * @brief A light that is present everywhere, adding a constant
 * amount of illumination to every object.
 */
class AmbientLight : public Light {
 public:
  AmbientLight(const AmbientLight&);
  AmbientLight();
  virtual ~AmbientLight();
  virtual Light* clone() const;
  virtual bool operator==(const AmbientLight&) const;

  virtual const char* to_string() const;
  virtual Vector3d get_direction(ShadeRec&);
  virtual RGBColor L(ShadeRec&);
  virtual bool in_shadow(const Ray&, ShadeRec&) const;

  void set_radiance(const double);
  void set_color(const RGBColor);
  double get_radiance() const;
  RGBColor get_color() const;
  virtual bool get_shadows() const;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Light);
    ar& BOOST_SERIALIZATION_NVP(ls);
    ar& BOOST_SERIALIZATION_NVP(color);
  }

 protected:
  /** Radiance of light. */
  double ls;
  /** Color of light. */
  RGBColor color;
};

inline void AmbientLight::set_radiance(const double ls) { this->ls = ls; }

inline void AmbientLight::set_color(const RGBColor color) {
  this->color = color;
}

inline double AmbientLight::get_radiance() const { return ls; }

inline RGBColor AmbientLight::get_color() const { return color; }

inline bool AmbientLight::get_shadows() const { return false; }
}

#endif  // _AMBIENT_H_
