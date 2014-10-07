#ifndef _BRDF_H_
#define _BRDF_H_

#include "Globals.hpp"
#include "RGBColor.hpp"
#include "ShadeRec.hpp"
#include "MultiJitteredSampler.hpp"
#include <Eigen/Dense>
using Eigen::Vector3d;

namespace Raytracer {
/** @brief An abstraction/model for shading calculations. */
class BRDF {
 public:
  BRDF();
  virtual ~BRDF();
  BRDF(const BRDF&);
  virtual BRDF* clone() const = 0;
  virtual bool operator==(const BRDF&) const;
  void set_sampler(Sampler*, const double exp);

  /** Compute the direction of reflected rays for simulating
   * reflective materials and diffuse-diffuse light transport. */
  virtual RGBColor sample_f(const ShadeRec&, const Vector3d& wo,
                            Vector3d& wi) const;

  /** Compute the direction of reflected rays for simulating
   * reflective materials and diffuse-diffuse light
   * transport. Version for area lights. */
  virtual RGBColor sample_f(const ShadeRec&, const Vector3d& wo, Vector3d& wi,
                            double& pdf) const;

  /** The BRDF itself. For example, this is 1.0/PI for a lambertian one
   * (perfectly diffuse). */
  virtual RGBColor f(const ShadeRec&, const Vector3d& wo,
                     const Vector3d& wi) const;

  /** Overall color = intensity * hue */
  virtual RGBColor rho(const ShadeRec&, const Vector3d& wo) const;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
	  BOOST_SERIALIZATION_NVP(sampler_ptr);
  }

 protected:
  /** Sampler for the BRDF. */ 
  Sampler* sampler_ptr;
};
}

#endif  // _BRDF_H_
