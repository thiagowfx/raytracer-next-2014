#ifndef _RAY_H_
#define _RAY_H_

#include "Globals.hpp"
#include <Eigen/Dense>
using Eigen::Vector3d;

namespace Raytracer {
/** @brief A ray, with an origin and a direction. */
class Ray {
 public:
  /** Create a ray at the specified origin, with the specified direction. */
  Ray(const Vector3d& origin, const Vector3d& direction);
  Ray();
  Ray(const Ray&);
  virtual ~Ray();
  Ray& operator=(const Ray&);
  bool operator==(const Ray&) const;
  void set_origin(const Vector3d&);
  void set_direction(const Vector3d&);
  Vector3d get_origin() const;
  Vector3d get_direction() const;

 private:
  /** Origin point. */
  Vector3d origin;

  /** Direction vector. */
  Vector3d direction;

 public:
  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_NVP(direction);
    ar& BOOST_SERIALIZATION_NVP(origin);
  }
};

/** Ray type.  Primary rays are shot by a camera, and shadow rays are shot by
 * objects to test their intersection with lights. */
enum Ray_t { PRIMARY_RAY, SHADOW_RAY };

inline void Ray::set_origin(const Vector3d& origin) { this->origin = origin; }

inline void Ray::set_direction(const Vector3d& direction) {
  this->direction = direction;
}

inline Vector3d Ray::get_origin() const { return this->origin; }

inline Vector3d Ray::get_direction() const { return this->direction; }
}

#endif  // _RAY_H_
