#ifndef _VIEWPLANE_H_
#define _VIEWPLANE_H_

#include "Globals.hpp"

namespace Raytracer {
/** @brief A ViewPlane stores image settings. */
class ViewPlane {
 public:
  ViewPlane();
  ViewPlane(const ViewPlane&);
  ~ViewPlane();
  bool operator==(const ViewPlane&) const;
  void set_hres(const unsigned);
  void set_vres(const unsigned);
  void set_pixel_size(const double);
  void set_gamma(const double);
  void set_out_of_gamut(const bool);
  void set_max_depth(const unsigned);
  unsigned get_hres() const;
  unsigned get_vres() const;
  double get_pixel_size() const;
  double get_gamma() const;
  bool get_out_of_gamut() const;
  unsigned get_max_depth() const;

 private:
  /** Horizontal Image Resolution. */
  unsigned hres;

  /** Vertical Image Resolution. */
  unsigned vres;

  /** Pixel size; decreasing means to zoom into a scene. */
  double pixel_size;

  /** Inverse of gamma factor. */
  double inv_gamma;

  /** If true, out-of-gamut colors are displayed differently. */
  bool out_of_gamut;

  /** Maximum number of bounces for reflective rays. */
  unsigned max_depth;

 public:
  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_NVP(hres);
    ar& BOOST_SERIALIZATION_NVP(vres);
    ar& BOOST_SERIALIZATION_NVP(pixel_size);
    ar& BOOST_SERIALIZATION_NVP(inv_gamma);
    ar& BOOST_SERIALIZATION_NVP(out_of_gamut);
    ar& BOOST_SERIALIZATION_NVP(max_depth);
  }
};

inline void ViewPlane::set_hres(const unsigned hres) { this->hres = hres; }

inline unsigned ViewPlane::get_hres() const { return this->hres; }

inline void ViewPlane::set_vres(const unsigned vres) { this->vres = vres; }

inline unsigned ViewPlane::get_vres() const { return this->vres; }

inline void ViewPlane::set_pixel_size(const double pixel_size) {
  this->pixel_size = pixel_size;
}

inline double ViewPlane::get_pixel_size() const { return this->pixel_size; }

inline void ViewPlane::set_gamma(const double gamma) {
  this->inv_gamma = 1.0 / gamma;
}

inline double ViewPlane::get_gamma() const { return 1.0 / this->inv_gamma; }

inline void ViewPlane::set_out_of_gamut(const bool out_of_gamut) {
  this->out_of_gamut = out_of_gamut;
}

inline bool ViewPlane::get_out_of_gamut() const { return this->out_of_gamut; }

inline void ViewPlane::set_max_depth(const unsigned max_depth) {
  this->max_depth = max_depth;
}

inline unsigned ViewPlane::get_max_depth() const { return this->max_depth; }
}

#endif  // _VIEWPLANE_H_
