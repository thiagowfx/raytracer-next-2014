#ifndef _BBOX_H_
#define _BBOX_H_

#include "Ray.hpp"

namespace Raytracer {
/**
 * @brief A bounding box encloses a geometric object to speed up
 * rendering times of complex geometric objects, but it is not a
 * geometric object itself, since it does not have a hit function
 * associated to it.
 */
class BBox {
 public:
  /** Construct a bounding box, given the coordinates of its opposite vertexes.
   */
  BBox(const double x0, const double x1, const double y0, const double y1,
       const double z0, const double z1);
  /** Construct a bounding box given the opposite vertexes in the same
   * plane. */
  BBox(const Vector3d, const Vector3d);
  BBox(const BBox&);
  BBox();
  ~BBox();
  virtual BBox* clone() const;
  bool operator==(const BBox&) const;
  /** Return true if the given ray hits the box. */
  bool hit(const Ray&) const;
  /** Return true if the given point is inside the box. */
  bool inside(const Vector3d&) const;
  /* Vertex coordinates. */
  double x0, y0, z0;
  /* Opposite vertex coordinates. */
  double x1, y1, z1;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_NVP(x0);
    ar& BOOST_SERIALIZATION_NVP(y0);
    ar& BOOST_SERIALIZATION_NVP(z0);
    ar& BOOST_SERIALIZATION_NVP(x1);
    ar& BOOST_SERIALIZATION_NVP(y1);
    ar& BOOST_SERIALIZATION_NVP(z1);
  }
};
}

#endif  // _BBOX_H_
