#ifndef _HAMMERSLEY_H_
#define _HAMMERSLEY_H_

#include "Sampler.hpp"

namespace Raytracer {
class Hammersley : public Sampler {
 public:
  Hammersley(const int number_of_samples = 10);
  Hammersley(const Hammersley&);
  virtual const char* to_string();
  virtual Hammersley* clone() const;
  virtual ~Hammersley();
  virtual bool operator==(const Hammersley&) const;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Sampler);
  }

 private:
  virtual void generate_samples();
  double phi(int) const;
};
}

#endif  // _HAMMERSLEY_H_
