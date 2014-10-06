#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "Globals.hpp"
#include "Ray.hpp"
#include "RGBColor.hpp"
#include <Eigen/Dense>
using Eigen::Vector3d;

namespace Raytracer {
class ShadeRec;
/**
 * @brief A light gives illumination to world objects.
 */
class Light {
 public:
  Light();
  Light(const Light&);
  virtual Light* clone() const = 0;
  virtual ~Light();
  virtual bool operator==(const Light&) const;

  /** Get the vector(direction) defined by two points: hit point and light
   * point. */
  virtual Vector3d get_direction(ShadeRec&) = 0;

  /** Does the given ray hit this light? Is there any objects between them? */
  virtual bool in_shadow(const Ray&, ShadeRec&) const = 0;

  /** Radiance this light emits. */
  virtual RGBColor L(ShadeRec&) = 0;

  /** Does this light cast shadows? */
  virtual bool get_shadows() const;

  /** Sets the shadow property of this light. */
  void set_shadows(const bool);

  /* For area lights.  Default value for both of them is 1.0, allowing
     us to add point and directional lights to scenes with area
     lights. */
  virtual double G(const ShadeRec&) const;
  virtual double pdf(const ShadeRec&) const;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_NVP(shadows);
  }

 protected:
  /** Does this light cast shadows? */
  bool shadows;
};
}

#endif  // _LIGHT_H_
