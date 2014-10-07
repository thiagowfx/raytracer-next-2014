#ifndef _LAMBERTIAN_H_
#define _LAMBERTIAN_H_

#include "BRDF.hpp"

namespace Raytracer {
/** @brief Lambertian model for lights. */
class Lambertian : public BRDF {
 public:
  Lambertian();
  Lambertian(const Lambertian&);
  virtual Lambertian* clone() const;
  virtual ~Lambertian();
  virtual bool operator==(const Lambertian&) const;
  virtual RGBColor f(const ShadeRec&, const Vector3d& wo,
                     const Vector3d& wi) const;
  virtual RGBColor sample_f(const ShadeRec&, const Vector3d& wo, Vector3d& wi,
                            double& pdf) const;
  virtual RGBColor rho(const ShadeRec&, const Vector3d& wo) const;
  void set_kd(double);
  void set_cd(const RGBColor&);
  double get_kd() const;
  RGBColor get_cd() const;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(BRDF);
    ar& BOOST_SERIALIZATION_NVP(kd);
    ar& BOOST_SERIALIZATION_NVP(cd);
  }

 private:
  /** Diffuse coefficient constant. */
  double kd;

  /** Diffuse color. */
  RGBColor cd;
};

inline void Lambertian::set_kd(double kd) { this->kd = kd; }

inline void Lambertian::set_cd(const RGBColor& cd) { this->cd = cd; }

inline double Lambertian::get_kd() const { return kd; }

inline RGBColor Lambertian::get_cd() const { return cd; }
}

#endif  // _LAMBERTIAN_H_
