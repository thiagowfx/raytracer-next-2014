#ifndef _MATTE_H_
#define _MATTE_H_

#include "Material.hpp"
#include "LambertianBRDF.hpp"
#include "World.hpp"

namespace Raytracer {
/**
 * @brief A material that models ambient + diffuse radiance.
 */
class Matte : public Material {
 public:
  /** Construct a new Matte material with the given color. */
  Matte(const RGBColor&);
  Matte();
  Matte(const Matte&);
  ~Matte();
  virtual Material* clone() const;
  virtual bool operator==(const Matte&) const;

  virtual RGBColor get_color() const;
  virtual RGBColor shade(ShadeRec&);
  virtual RGBColor area_light_shade(ShadeRec&);

  void set_ka(const double);
  void set_kd(const double);
  void set_cd(const RGBColor&);
  double get_ka() const;
  double get_kd() const;
  RGBColor get_cd() const;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Material);
    ar& BOOST_SERIALIZATION_NVP(ambient_brdf);
    ar& BOOST_SERIALIZATION_NVP(diffuse_brdf);
  }

 private:
  /** Ambient color component. */
  Lambertian* ambient_brdf;

  /** Diffuse color component. */
  Lambertian* diffuse_brdf;
};

/** This sets Lambertian::kd, there is no Lambertian::ka data member
    because ambient reflection is diffuse reflection */
inline void Matte::set_ka(const double ka) { ambient_brdf->set_kd(ka); }

/** This also sets Lambertian::kd, but for a different Lambertian
    object */
inline void Matte::set_kd(const double kd) { diffuse_brdf->set_kd(kd); }

inline void Matte::set_cd(const RGBColor& c) {
  ambient_brdf->set_cd(c);
  diffuse_brdf->set_cd(c);
}

inline double get_ka() const { return this->ambient_brdf->get_kd(); }

inline double get_kd() const { return this->diffuse_brdf->get_kd(); }

inline RGBColor get_cd() const { return this->diffuse_brdf->getcd(); }
}
BOOST_CLASS_EXPORT_KEY(Raytracer::Matte)

#endif  // _MATTE_H_
