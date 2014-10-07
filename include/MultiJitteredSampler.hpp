#ifndef _MULTIJITTERED_H_
#define _MULTIJITTERED_H_

#include "Sampler.hpp"

namespace Raytracer {
class MultiJittered : public Sampler {
 public:
  MultiJittered(const int number_of_samples = kSamples);
  MultiJittered(const MultiJittered&);
  virtual const char* to_string();
  virtual MultiJittered* clone() const;
  virtual ~MultiJittered();
  virtual bool operator==(const MultiJittered&) const;

  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Sampler);
  }

 private:
  virtual void generate_samples();
};
}

#endif  // _MULTIJITTERED_H_
