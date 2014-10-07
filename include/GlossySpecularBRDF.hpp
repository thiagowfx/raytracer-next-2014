#ifndef _GLOSSYSPECULAR_H_
#define _GLOSSYSPECULAR_H_

#include "BRDF.hpp"

namespace Raytracer {
/**
 * @brief Glossy specular reflection for direct and indirect illumination.
 */
class GlossySpecular : public BRDF {
 public:
  GlossySpecular();
  GlossySpecular(const GlossySpecular&);
  ~GlossySpecular();
  virtual GlossySpecular* clone() const;
  virtual bool operator==(const GlossySpecular&) const;

  virtual RGBColor f(const ShadeRec&, const Vector3d& wo,
                     const Vector3d& wi) const;
  virtual RGBColor sample_f(const ShadeRec&, const Vector3d& wo, Vector3d& wi,
                            double& pdf) const;

  void set_ks(const double);
  void set_exp(const double);
  void set_cs(const RGBColor&);
  void set_normal(const Vector3d&);
  double get_ks() const;
  double get_exp() const;
  RGBColor get_cs() const;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(BRDF);
    ar& BOOST_SERIALIZATION_NVP(ks);
    ar& BOOST_SERIALIZATION_NVP(exp);
    ar& BOOST_SERIALIZATION_NVP(cs);
  }

 private:
  /** Specular (reflective) coefficient constant. */
  double ks;

  /** Specular exponent constant. */
  double exp;

  /** Specular (reflective) color. */
  RGBColor cs;
};

inline void GlossySpecular::set_ks(const double ks) { this->ks = ks; }

inline void GlossySpecular::set_exp(const double exp) { this->exp = exp; }

inline void GlossySpecular::set_cs(const RGBColor& cs) { this->cs = cs; }

inline double GlossySpecular::get_ks() const { return this->ks; }

inline double GlossySpecular::get_exp() const { return this->exp; }

inline RGBColor GlossySpecular::get_cs() const { return this->cs; }
}

#endif  // _GLOSSYSPECULAR_H_
