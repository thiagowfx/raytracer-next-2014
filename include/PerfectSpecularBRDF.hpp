#ifndef _PERFECTSPECULAR_H_
#define _PERFECTSPECULAR_H_

#include "BRDF.hpp"

namespace Raytracer {
/**
 * @brief Perfect specular reflection for indirect illumination with reflective
 * materials.
 */
class PerfectSpecular : public BRDF {
 public:
  PerfectSpecular();
  ~PerfectSpecular();
  PerfectSpecular(const PerfectSpecular&);
  virtual PerfectSpecular* clone() const;
  virtual bool operator==(const PerfectSpecular&) const;

  void set_kr(const double);
  void set_cr(const RGBColor&);
  double get_kr() const;
  RGBColor get_cr() const;

  virtual RGBColor sample_f(const ShadeRec&, const Vector3d& wo,
                            Vector3d& wi) const;
  virtual RGBColor sample_f(const ShadeRec&, const Vector3d& wo, Vector3d& wi,
                            double& pdf) const;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(BRDF);
    ar& BOOST_SERIALIZATION_NVP(kr);
    ar& BOOST_SERIALIZATION_NVP(cr);
  }

 private:
  /** Reflection coefficient constant. */
  double kr;

  /** Reflection color. */
  RGBColor cr;
};

inline void PerfectSpecular::set_kr(const double kr) { this->kr = kr; }

inline void PerfectSpecular::set_cr(const RGBColor& cr) { this->cr = cr; }

inline double PerfectSpecular::get_kr() const { return this->kr; }

inline RGBColor PerfectSpecular::get_cr() const { return this->cr; }
}

#endif  // _PERFECTSPECULAR_H_
