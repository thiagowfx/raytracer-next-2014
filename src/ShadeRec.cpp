#include "ShadeRec.hpp"

namespace Raytracer {
ShadeRec::ShadeRec(World& w)
    : hit_an_object(false),
      material_ptr(NULL),
      hit_point(Vector3d::Zero()),
      local_hit_point(Vector3d::Zero()),
      normal(Vector3d::Zero()),
      ray(),
      depth(0),
      t(0.0),
      w(w) {}

ShadeRec::~ShadeRec() {}

ShadeRec::ShadeRec(const ShadeRec& sr)
    : hit_an_object(sr.hit_an_object),
      material_ptr(sr.material_ptr),
      hit_point(sr.hit_point),
      local_hit_point(sr.local_hit_point),
      normal(sr.normal),
      ray(sr.ray),
      depth(sr.depth),
      t(sr.t),
      w(sr.w) {}

bool ShadeRec::operator==(const ShadeRec& o) const {
  return hit_an_object == o.hit_an_object && material_ptr == o.material_ptr &&
         hit_point == o.hit_point && local_hit_point == o.local_hit_point &&
         normal == o.normal && ray == o.ray && depth == o.depth && t == o.t &&
         &w == &(o.w);
}
}
