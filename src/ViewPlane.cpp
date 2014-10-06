#include "ViewPlane.hpp"

namespace Raytracer {
ViewPlane::ViewPlane()
    : hres(100),
      vres(100),
      pixel_size(1.0),
      inv_gamma(1.0),
      out_of_gamut(false),
      max_depth(1) {}

ViewPlane::ViewPlane(const ViewPlane& vp)
    : hres(vp.hres),
      vres(vp.vres),
      pixel_size(vp.pixel_size),
      inv_gamma(vp.inv_gamma),
      out_of_gamut(vp.out_of_gamut),
      max_depth(vp.max_depth) {}

ViewPlane& ViewPlane::operator=(const ViewPlane& rhs) {
	if (this != &rhs) {
		hres = rhs.hres;
		vres = rhs.vres;
		pixel_size = rhs.pixel_size;
		inv_gamma = rhs.inv_gamma;
		out_of_gamut = rhs.out_of_gamut;
		max_depth = rhs.max_depth;
	}
	return *this;
}

bool ViewPlane::operator==(const ViewPlane& o) const {
  return hres == o.hres && vres == o.vres && pixel_size == o.pixel_size &&
         inv_gamma == o.inv_gamma && out_of_gamut == o.out_of_gamut &&
         max_depth == o.max_depth;
}

ViewPlane::~ViewPlane() {}
}
