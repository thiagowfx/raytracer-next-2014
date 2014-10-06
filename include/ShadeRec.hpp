#ifndef _SHADEREC_H_
#define _SHADEREC_H_

#include "Ray.hpp"

namespace Raytracer {
class Material;
class World;
/**
 * @brief Helper object to store information for shading.
 */
class ShadeRec {
 public:
  ShadeRec(World&);
  ShadeRec(const ShadeRec&);
  virtual ~ShadeRec();
  bool operator==(const ShadeRec&) const;

  /** Did the ray hit any object? */
  bool hit_an_object;

  /** Pointer to the nearest hit object material. */
  Material* material_ptr;

  /** World coordinates of intersection. */
  Vector3d hit_point;

  /** World coordinates of hit point on generic object (used for texture
   * transformations). */
  Vector3d local_hit_point;

  /** Normal at hit point. */
  Vector3d normal;

  /** Used for specular highlights and area lights. */
  Ray ray;

  /** Recursion depth, for reflected rays. */
  int depth;

  /** Ray parameter. */
  double t;

  /** World reference. */
  World& w;
};
}

#endif  // _SHADEREC_H_
